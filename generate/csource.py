__all__ = ['Formatter', 'CSource']

import re
from StringIO import StringIO
from collections import defaultdict

class Formatter(object):
    def __init__(self):
        self._indent = 0
        self.lines = []

    def indent(self):
        self._indent += 1
    def dedent(self):
        self._indent -= 1
        if self._indent < 0:
            raise ValueError("Dedented pass left margin")

    def add(self, source):
        for line in source.splitlines():
            if line.startswith('#'):
                i = 0
            else:
                i = self._indent
            self.lines.append( (i, line) )

    def addAsIs(self, source):
        for line in source.splitlines():
            self.lines.append( (0, line) )

    def write(self, fo):
        for i, line in self.lines:
            fo.write(' '*(i*4))
            fo.write(line)
            fo.write('\n')

    def __str__(self):
        sbuf = StringIO()
        self.write(sbuf)
        return sbuf.getvalue()

class NullContextManager(object):
    def __enter__(self):
        return self
    def __exit__(self, *args):
        return False
null_context = NullContextManager()

def identifiers(code):
    return set(re.findall(r'[_a-zA-Z][_a-zA-Z0-9]*', code))

class CScope(object):
    def __init__(self, env=(), parent=None):
        self.parent = parent
        self.children = []
        self._vars = set(env)
        self._used = defaultdict(set)
        self.statements = []

    def newScope(self):
        s = CScope(parent=self)
        self.children.append(s)
        self.statements.append( (self._toC_scope, s) )
        return s

    def isDeclaredVar(self, var):
        if var in self._vars:
            return True
        elif self.parent:
            return self.parent.isDeclaredVar(var)
        else:
            return False

    def declaredVars(self, possibles):
        if isinstance(possibles, str):
            possibles = identifiers(possibles)
        used = set()
        for ident in possibles:
            if self.isDeclaredVar(ident):
                used.add(ident)
        return used

    def markUsed(self, var, by=None):
        """Mark a variable as used by something.

        If `by` is false, `var` is being used in a statement or something else
        that will be included unconditionally (and so `var` should be declared
        unconditionally). Otherwise, `by` is the variable whose initialisation
        uses `var`.
        """
        if var in self._vars:
            u = self._used[var]
            if by:
                u.add(by)
            else:
                u.add(None)
        elif self.parent:
            self.parent.markUsed(var, by=by)

    def markAllUsed(self, used, by=None):
        if not used:
            return
        for var in used:
            self.markUsed(var, by=by)

    def isVarUsed(self, var):
        u = self._used[var]
        if None in u:                   # used unconditionally
            return True
        for v in u:
            if self.isVarUsed(v):
                return True
            for c in self.children:
                if c.isVarUsed(v):
                    return True
        return False

    def addVar(self, var):
        self._vars.add(var)

    def declare(self, ctype, var, value=None, uses=None):
        self.statements.append( (self._toC_var, var, ctype, value) )
        self.addVar(var)
        self.markAllUsed(uses, by=var)

    def implicitDeclare(self, var, stmt, uses=None):
        self.statements.append( (self._toC_var_stmt, var, stmt) )
        self.addVar(var)
        self.markAllUsed(uses, by=var)

    def add(self, frag, uses=None, autouses=False, asis=False,
            dependson=None):
        if autouses and not uses:
            uses = self.declaredVars(frag)
        if asis:
            self.statements.append( (self._toC_asis, frag, dependson) )
        else:
            self.statements.append( (self._toC_stmt, frag, dependson) )
        self.markAllUsed(uses, by=None)
        return null_context

    def indent(self):
        self.statements.append( (self._toC_indent,) )
        return null_context
    def dedent(self):
        self.statements.append( (self._toC_dedent,) )

    def _toC_var_stmt(self, ppf, var, stmt):
        if not self.isVarUsed(var):
            return
        ppf.add(stmt)

    def _toC_var(self, ppf, var, ctype, value):
        if ctype.endswith('*'):
            decl = '%s%s' % (ctype, var)
        else:
            decl = '%s %s' % (ctype, var)
        if value:
            stmt = '%s = %s;'% (decl, value)
        else:
            stmt = decl + ';'
        self._toC_var_stmt(ppf, var, stmt)

    def _toC_asis(self, ppf, s, dependson):
        if dependson and not all(self.isVarUsed(v) for v in dependson):
            return
        ppf.addAsIs(s)
    def _toC_stmt(self, ppf, s, dependson):
        if dependson and not all(self.isVarUsed(v) for v in dependson):
            return
        ppf.add(s)
    def _toC_scope(self, ppf, scope):
        scope.toC(ppf)
    def _toC_indent(self, ppf):
        ppf.indent()
    def _toC_dedent(self, ppf):
        ppf.dedent()
        
    def toC(self, ppf):
        for r in self.statements:
            r[0](ppf, *r[1:])

    # Allow scopes to be used as context managers so that we can
    # indent our Python code along the same lines as C code.
    def __enter__(self):
        return self
    def __exit__(self, *args):
        return False

class CSourceContext(object):
    def __init__(self, source):
        self.source = source
    def __enter__(self):
        return self.source
    def __exit__(self, exc_type, exc_value, exc_tb):
        if exc_type is None:
            self.source.popScope()
        return False

class CSource(object):
    def __init__(self, env=()):
        self.scope = CScope(env=env)

    def newScope(self):
        self.scope = self.scope.newScope()
        return CSourceContext(self)
    def popScope(self):
        self.scope = self.scope.parent

    def markUsed(self, *args, **kw):
        return self.scope.markUsed(*args, **kw)
    def addVar(self, *args, **kw):
        return self.scope.addVar(*args, **kw)

    def declare(self, *args, **kw):
        return self.scope.declare(*args, **kw)
    def implicitDeclare(self, *args, **kw):
        return self.scope.implicitDeclare(*args, **kw)
    def add(self, *args, **kw):
        return self.scope.add(*args, **kw)
    def indent(self):
        return self.scope.indent()
    def dedent(self):
        return self.scope.dedent()

    def toC(self, ppf):
        self.scope.toC(ppf)
