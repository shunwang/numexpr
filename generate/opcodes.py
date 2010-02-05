intt = ('i', 'l')
real = ('i', 'l', 'f', 'd')
floatt = ('f', 'd')
simple = ('b', 'i', 'l', 'f', 'd')
number = ('i', 'l', 'f', 'd', 'c')

def cmul(ar, ai, br, bi):
    d = dict(ar=ar, ai=ai, br=br, bi=bi)
    return ('%(ar)s*%(br)s - %(ai)s*%(bi)s' % d,
            '%(ar)s*%(bi)s + %(ai)s*%(br)s' % d)

set_op_condition()

op('NOOP', '', Code(''))

op('COPY', 'bb', 'a1')
op('COPY', 'ss', S('memcpy(r, a1_ptr, a1_len)'))

op('COPY', (number, number),
   S('memcpy(r, a1_ptr, sizeof(${r_ctype}))'))

op('INVERT', 'bb', '!a1')
op('AND', 'bbb', 'a1 && a2')
op('OR', 'bbb', 'a1 || a2')

op('EQ', ('b', simple, simple), 'a1 == a2')
op('NE', ('b', simple, simple), 'a1 != a2')
op('GT', ('b', real, real), 'a1 > a2')
op('GE', ('b', real, real), 'a1 >= a2')

op('EQ', 'bss', 'stringcmp(a1_ptr, a2_ptr, a1_len, a2_len) == 0')
op('NE', 'bss', 'stringcmp(a1_ptr, a2_ptr, a1_len, a2_len) != 0')
op('GT', 'bss', 'stringcmp(a1_ptr, a2_ptr, a1_len, a2_len) > 0')
op('GE', 'bss', 'stringcmp(a1_ptr, a2_ptr, a1_len, a2_len) >= 0')

op('ONES_LIKE', (intt,), '1')
op('NEG', (intt, intt), '-a1')
op('ADD', (intt, intt, intt), 'a1 + a2')
op('SUB', (intt, intt, intt), 'a1 - a2')
op('MUL', (intt, intt, intt), 'a1 * a2')
op('DIV', (intt, intt, intt), 'a1 / a2')
op('MOD', (intt, intt, intt), 'a1 % a2')
op('POW', (intt, intt, intt), '(a2 < 0) ? (1/a1) : (${r_ctype})pow(a1, a2)')
op('WHERE', (intt, 'b', intt, intt), 'a1 ? a2 : a3')

op('CAST', 'li', '(${r_ctype})(a1)')
for tr in floatt:
    op('CAST', (tr, intt), '(${r_ctype})(a1)')

op('ONES_LIKE', (floatt,), '1.0')
op('NEG', (floatt, floatt), '-a1')
op('ADD', (floatt, floatt, floatt), 'a1 + a2')
op('SUB', (floatt, floatt, floatt), 'a1 - a2')
op('MUL', (floatt, floatt, floatt), 'a1 * a2')
op('DIV', (floatt, floatt, floatt), 'a1 / a2')

op('MOD', 'fff', 'a1 - floorf(a1/a2) * a2')
op('MOD', 'ddd', 'a1 - floor(a1/a2) * a2')

op('POW', 'fff', 'powf(a1, a2)')
op('POW', 'ddd', 'pow(a1, a2)')
op('SQRT', 'ff', 'sqrtf(a1)')
op('SQRT', 'dd', 'sqrt(a1)')
op('WHERE', (floatt, 'b', floatt, floatt), 'a1 ? a2 : a3')
op('FUNC', 'ffn', 'functions_ff[arg2](a1)')
op('FUNC', 'ddn', 'functions_dd[arg2](a1)')
op('FUNC', 'fffn', 'functions_fff[arg3](a1, a2)')
op('FUNC', 'dddn', 'functions_ddd[arg3](a1, a2)')

op('CAST', 'df', '(${r_ctype})(a1)')

op('CAST', ('c', real), C('', '(double)a1', '0'))

op('ONES_LIKE', 'c', C('', '1', '0'))
op('NEG', 'cc', C('', '-a1r', '-a1i'))
op('ADD', 'ccc', C('', 'a1r+a2r', 'a1i+a2i'))
op('SUB', 'ccc', C('', 'a1r-a2r', 'a1i-a2i'))
op('MUL', 'ccc', C('', *cmul('a1r', 'a1i', 'a2r', 'a2i')))
op('DIV', 'ccc', C('double da = a2r*a2r + a2i*a2i',
                   '(a1r*a2r + a1i*a2i) / da',
                   '(a1i*a2r - a1r*a2i) / da'))

op('EQ', 'bcc', 'a1r == a2r && a1i == a2i')
op('NE', 'bcc', 'a1r != a2r || a1i != a2i')
op('WHERE', 'cbcc', C('', 'a1 ? a2r : a3r', 'a1 ? a2i : a3i'))

op('FUNC', 'ccn', C('cdouble ca = a1;\nfunctions_cc[arg2](&ca, &ca)',
                    'ca.real', 'ca.imag'))
op('FUNC', 'cccn', C('cdouble ca = a1; cdouble cb = a2;\n'
                     + 'functions_ccc[arg3](&ca, &cb, &ca)',
                     'ca.real', 'ca.imag'))
op('REAL', 'dc', 'a1r')
op('IMAG', 'dc', 'a1i')
op('COMPLEX', 'cdd', C('', 'a1', 'a2'))

REAL = ('I', 'L', 'F', 'D')
op('SUM', (REAL, real, 'n'), S('*r += a1'))
op('SUM', 'Ccn', C('', 'r->real + a1r', 'r->imag + a1i'))
op('PROD', (REAL, real, 'n'), S('*r *= a1'))
op('PROD', 'Ccn', C('double rr = r->real',
                    *cmul('rr', 'r->imag', 'a1r', 'a1i')))

set_op_condition('defined(USE_VML)')
op('DIV', 'fff', VML('vsDiv'))
op('DIV', 'ddd', VML('vdDiv'))
op('POW', 'fff', VML('vsPow'))
op('POW', 'ddd', VML('vdPow'))
op('SQRT', 'ff', VML('vsSqrt'))
op('SQRT', 'dd', VML('vdSqrt'))
op('FUNC', 'ffn', VML('functions_ff_vml[arg2]'))
op('FUNC', 'ddn', VML('functions_dd_vml[arg2]'))
op('FUNC', 'fffn', VML('functions_fff_vml[arg3]'))
op('FUNC', 'dddn', VML('functions_ddd_vml[arg3]'))
# op('DIV', 'ccc', VML('vzDiv'))
op('FUNC', 'ccn', VML('functions_cc_vml[arg2]'))
