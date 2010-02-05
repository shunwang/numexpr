"""
Generate the virtual machine engines used to do the numexpr calculations.

Note that this module requires Python >= 2.5, while numexpr requires >= 2.4.
"""
from __future__ import with_statement

from string import Template
import re
import copy
import commands
import time

from csource import Formatter, CSource

OPCODES_FILE = 'opcodes.py'
OPCODES_LIST = '../numexpr/opcodes.inc'

VM_ENGINE_PART1 = Template('''\
/* GENERATED FILE. DO NOT EDIT (UNLESS YOU ENJOY LOSING YOUR CHANGES).

Created by genvm.py on ${time}.
*/

static inline int
VM_ENGINE(unsigned int start, unsigned int blen,
          struct vm_params params, int *pc_error)
{\
''')

SYMBOLS_TO_UNDEF = ['TARGET', 'NEXT', 'NEXT2',
                    'USES_STORE_IN', 'USES_ARG1',
                    'USES_ARG2', 'USES_ARG3',
                    'VECTOR_SIZE']

VM_ENGINE_PART2 = '''\
#ifdef USE_COMPUTED_GOTO
# define TARGET(op) lbl_##op:
# define USES_STORE_IN unsigned int store_in = params.program[pc+1]
# define USES_ARG1 unsigned int arg1 = params.program[pc+2]
# define USES_ARG2 unsigned int arg2 = params.program[pc+3]
# define USES_ARG3 unsigned int arg3 = params.program[pc+5]
# define NEXT() pc += 4; if (pc >= params.prog_len) return 0; \\
    op = params.program[pc]; goto *opcode_targets[op];
# define NEXT2() pc += 8; if (pc >= params.prog_len) return 0; \\
    op = params.program[pc]; goto *opcode_targets[op];
#else
# define TARGET(op) case OP_##op:
# define USES_STORE_IN
# define USES_ARG1
# define USES_ARG2
# define USES_ARG3 unsigned int arg3 = params.program[pc+5]
# define NEXT() break;
# define NEXT2() pc += 4; break;
#endif

#define VECTOR_SIZE blen
    unsigned int j;
    vm_setup_input_output_pointers(&params, start, VECTOR_SIZE);
'''

def subst(*args, **kws):
    def s(t):
        return Template(t).substitute(*args, **kws)
    return s

def zip_types(tys):
    if isinstance(tys, str):
        return [tys]
    maxlen = max(len(t) for t in tys)
    if any(len(t) not in (1, maxlen) for t in tys):
        raise ValueError("can't zip over non-equal type lengths")
    tlist = [ t if len(t) == maxlen else tuple(t*maxlen) for t in tys ]

    return zip(*tlist)

class Opcode(object):
    def __init__(self, name, type_):
        self.name = name
        self.type = type_
        self.code = {}

    def addCode(self, code, condition):
        if condition in self.code:
            raise ValueError("duplicate condition %r added for opcode %s" %
                             (condition, self.name))
        self.code[condition] = code

    def __str__(self):
        return '%s(%s): %r' % (self.name, self.type, self.code)

    def encodeLength(self):
        if len(self.type) <= 3:
            return 1
        else:
            assert(len(self.type) <= 6)
            return 2

    def build(self, c):
        if '' not in self.code:
            raise ValueError("no default code for opcode %s" % (self.name,))
        if len(self.code) == 1:
            self.code[''].build(c)
            return
        conditions = self.code.keys()
        conditions.remove('')
        conditions.sort()
        # hrm, scope handling + #ifdef'd code may interact wierdly
        for cond in conditions:
            c.add('#if ' + cond)
            self.code[cond].build(c)
            c.add('#else')
        self.code[''].build(c)
        for cond in conditions:
            c.add('#endif')

class Code(object):
    def __init__(self, code):
        self.code = code
        self.rtype = None
        self.atypes = ()

    def setOpTypes(self, types):
        if types:
            self.rtype = types[0]
            self.atypes = types[1:]

    def isReduction(self):
        return self.rtype == self.rtype.upper()

    def args(self):
        for i, t in enumerate(self.atypes):
            yield i+1, t

    def __str__(self):
        return '%s(%s)' % (self.__class__.__name__, self.code)
    __repr__ = __str__

    ctypes = {
        'b' : 'char',
        'i' : 'int',
        'l' : 'long long',
        'f' : 'float',
        'd' : 'double',
        'c' : 'cdouble',
        's' : 'char',
        'I' : 'int',
        'L' : 'long long',
        'F' : 'float',
        'D' : 'double',
        'C' : 'cdouble',
        }

    def codeSubst(self):
        d = {}
        if self.rtype:
            d['r_ctype'] = self.ctypes[self.rtype]
        for i,t in self.args():
            if t != 'n':
                d['a%d_ctype' % (i,)] = self.ctypes[t]
        def subst(s):
            return Template(s).substitute(d)
        return subst

    def addCode(self, c):
        code = self.codeSubst()(self.code)
        c.add(code, autouses=True)

    def build(self, c):
        c.add('// %s' % (self.__class__.__name__,))
        self.addCode(c)


class ScalarStatement(Code):
    def addSetupDestination(self, c):
        rtype = self.ctypes[self.rtype]
        s = subst(t=rtype, pt=rtype+' *')
        c.implicitDeclare('store_in', 'USES_STORE_IN;')
        c.add('BOUNDS_CHECK(store_in);', dependson=['store_in'])
        if self.isReduction():
            c.declare('char *', 'dest', 'params.mem[store_in]',
                      ['store_in'])
            c.declare('struct index_data *', 'store_index',
                      '&(params.index_data[store_in])', ['store_in'])
        else:
            c.declare(s('$pt'), 'dest',
                      s('($pt)(params.mem[store_in])'),
                      ['store_in'])

    def addDestination(self, c):
        rtype = self.ctypes[self.rtype]
        s = subst(t=rtype, pt=rtype + ' *')
        if self.isReduction():
            c.declare(s('$pt'), 'r',
                      s('($pt)(dest + flat_index(store_index, j))'),
                      ['dest', 'store_index', 'j'])
        elif self.rtype == 's':
            c.declare('char *', 'r', 'dest+j*params.memsteps[store_in]',
                      ['dest', 'store_in', 'j'])
        else:
            c.declare(s('$pt'), 'r', 'dest + j', uses=['dest', 'j'])

    def addSetupArgument(self, c, t, i):
        argn = 'arg%d' % (i,)
        c.implicitDeclare(argn, 'USES_ARG%d;' % (i,))
        if t == 'n':
            return
        c.add('BOUNDS_CHECK(%s);' % (argn,), dependson=[argn])
        c.declare('char *', 'a%d_base' % (i,),
                  'params.mem[%s]' % (argn,), [argn])
        c.declare('intp', 'a%d_step' % (i,),
                  'params.memsteps[%s]' % (argn,), [argn])
        c.declare('intp', 'a%d_len' % (i,),
                  'params.memsizes[%s]' % (argn,), [argn])

    def addArgument(self, c, t, i):
        if t == 'n':
            return
        ct = self.ctypes[t]
        s = subst(i=i, ct=ct)
        ai = s('a${i}')
        c.declare(ct, ai, s('*($ct *)(a${i}_base+j*a${i}_step)'),
                  [s('a${i}_base'), 'j', s('a${i}_step')])
        c.declare('double', ai+'r', ai+'.real', [ai])
        c.declare('double', ai+'i', ai+'.imag', [ai])
        c.declare(ct+' *', ai+'_ptr',
                  s('($ct *)(a${i}_base+j*a${i}_step)'),
                  [s('a${i}_base'), 'j', s('a${i}_step')])

    def addCode(self, c):
        code = self.codeSubst()(self.code)
        c.add(code + ';', autouses=True)

    def build(self, c):
        c.add('// rtype=%s atypes=%s' % (self.rtype, self.atypes))
        with c.newScope():
            self.addSetupDestination(c)
            for i, t in self.args():
                self.addSetupArgument(c, t, i)
            c.add('for (j=0; j < VECTOR_SIZE; j++) {')
            c.indent()
            with c.newScope():
                self.addDestination(c)
                for i, t in self.args():
                    self.addArgument(c, t, i)
                self.addCode(c)
            c.dedent(); c.add('}')

class ScalarExpression(ScalarStatement):
    def __init__(self, code):
        ScalarStatement.__init__(self, '*r = ' + code)

class ComplexScalar(ScalarStatement):
    def __init__(self, pre, real, imag):
        self.pre = pre
        self.real = real
        self.imag = imag
    def __str__(self):
        return '%s(%s, real=%s, imag=%s)' % (self.__class__.__name__,
                                             self.pre, self.real, self.imag)
    __repr__ = __str__

    def addCode(self, c):
        s = self.codeSubst()
        if self.pre:
            c.add(s(self.pre) + ';', autouses=True)
        c.add('r->real = ' + s(self.real) + ';', autouses=True)
        c.add('r->imag = ' + s(self.imag) + ';', autouses=True)

class VectoredRoutine(Code):
    def __init__(self, routine):
        self.routine = routine
    def __str__(self):
        return '%s(%r)' % (self.__class__.__name__, self.routine,)
    __repr__ = __str__

    def buildArgs(self):
        pass

    def build(self, c):
        rtype = self.ctypes[self.rtype]
        c.declare(rtype+' *', 'dest',
                  '(%s *)(params.mem[store_in])' % (rtype, ),
                  ['store_in'])
        for i, t in self.args():
            if t == 'n':
                continue
            vt = self.ctypes[t]
            x = 'x%d' % (i,)
            c.declare(vt+' *', x, '(%s *)(params.mem[arg%d])' % (vt, i),
                      ['arg%d' % (i,)])
        args = self.buildArgs()
        c.add(self.routine + '(' + ', '.join(args) + ');', autouses=True)

class VML(VectoredRoutine):
    ctypes = {'b' : 'char',
              'i' : 'int',
              'l' : 'long long',
              'f' : 'float',
              'd' : 'double',
              'c' : 'MKL_Complex16'}

    def buildArgs(self):
        args = ['VECTOR_SIZE']
        args += ['x%d'%(i,) for i, _ in self.args()]
        args += ['dest']
        return args

def read_opcode_code():
    opcodes = {}
    current_condition = ['']
    def set_op_condition(c=''):
        current_condition[0] = c
    def op(opcode, ty, code):
        for ty in zip_types(ty):
            sty = ''.join(ty)
            name = opcode if not sty else opcode + "_" + sty.upper()
            o = opcodes.get(name)
            if not o:
                o = Opcode(name, sty)
                opcodes[name] = o
            if isinstance(code, str):
                code = ScalarExpression(code)
            else:
                code = copy.copy(code)
            code.setOpTypes(sty)
            o.addCode(code, current_condition[0])
    g = globals().copy()
    g['set_op_condition'] = set_op_condition
    g['op'] = op
    g['S'] = ScalarStatement
    g['C'] = ComplexScalar
    execfile(OPCODES_FILE, g)
    return opcodes

opcodes = read_opcode_code()
def get_opcode_list():
    olist = commands.getoutput("cpp -P '-DOPCODE(n,e,ex,...)=n%e%ex' "+OPCODES_LIST)
    opcodes_order = []
    for line in olist.splitlines():
        if not line:
            continue
        n, enum, exported = line.split('%')
        if exported == 'NULL':
            continue
        n = int(n)
        if enum.startswith('OP_'):
            enum = enum[3:]
        opcodes_order.append((n, enum))
    opcodes_order.sort()
    return opcodes_order

def check_opcodes(order):
    olist = set(name for _, name in order)
    for name in olist:
        if name not in opcodes:
            raise ValueError("opcode %s has no code defined" % (name,))
    for name in opcodes:
        if name not in olist:
            raise ValueError("unknown opcode %s" % (name,))

def static_jump_table(c, opcodes):
    c.add('static void *opcode_targets[256] = {')
    c.indent()
    odict = dict(opcodes)
    for i in range(256):
        if i in odict:
            c.add('[%d] = &&lbl_%s,' % (i, odict[i],))
        else:
            c.add('[%d] = &&unknown_opcode,' % (i,))
    c.dedent(); c.add('};')

def USE_COMPUTED_GOTO(c):
    return c.add('#ifdef USE_COMPUTED_GOTO')
def ELSE(c):
    return c.add('#else')
def ENDIF(c):
    return c.add('#endif')

def opcode_to_C(c, name):
    o = opcodes[name]
    c.add('TARGET(%s) {' % (o.name,))
    c.indent()
    with c.newScope():
        o.build(c)
#    c.add('NEXT(); }')
    if o.encodeLength() == 1:
        c.add('NEXT(); }')
    else:
        c.add('NEXT2(); }')
    c.dedent()


def build_interpreter_body():
    opcodes_order = get_opcode_list()
    check_opcodes(opcodes_order)
    c = CSource()
    c.add(VM_ENGINE_PART1.substitute(time=time.asctime(time.gmtime())))
    c.indent()
    with USE_COMPUTED_GOTO(c):
        static_jump_table(c, opcodes_order)
    ENDIF(c)
    c.add(VM_ENGINE_PART2, asis=True)
    c.declare('unsigned int', 'pc', '0')
    with USE_COMPUTED_GOTO(c):
        c.declare('unsigned int', 'op', 'params.program[pc]')
        c.add('goto *opcode_targets[op];')
        c.add('{ {')
    with ELSE(c):
        c.add('for (pc = 0; pc < params.prog_len; pc += 4) {')
        c.indent()
        c.declare('unsigned int', 'op', 'params.program[pc]')
        c.declare('unsigned int', 'store_in', 'params.program[pc+1]')
        c.declare('unsigned int', 'arg1', 'params.program[pc+2]')
        c.declare('unsigned int', 'arg2', 'params.program[pc+3]')
        c.add('switch (op) {', uses=['op'])
    ENDIF(c)
    c.markUsed('pc')
    c.markUsed('op')

    for _, name in opcodes_order:
        opcode_to_C(c, name)

    with USE_COMPUTED_GOTO(c):
        c.add('unknown_opcode:')
    with ELSE(c):
        c.add('default:')
    ENDIF(c)
    c.indent(); c.add('*pc_error = pc; return -3;'); c.dedent()
    c.add('}')
    c.dedent(); c.add('}')
    c.add('return 0;')
    c.dedent(); c.add('}')
    for d in SYMBOLS_TO_UNDEF:
        c.add('#undef %s' % (d,))
    return c

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1:
        opcodes_order = get_opcode_list()
        c = CSource(['pc', 'j', 'store_in', 'arg1', 'arg2'])
        for pat in sys.argv[1:]:
            for _, name in opcodes_order:
                if re.search(pat, name, re.IGNORECASE):
                    opcode_to_C(c, name)
    else:
        c = build_interpreter_body()
    ppf = Formatter()
    c.toC(ppf)
    ppf.write(sys.stdout)
