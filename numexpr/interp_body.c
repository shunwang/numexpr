/* GENERATED FILE. DO NOT EDIT (UNLESS YOU ENJOY LOSING YOUR CHANGES).

Created by genvm.py on Thu Feb  4 22:57:22 2010.
*/

static inline int
VM_ENGINE(unsigned int start, unsigned int blen,
          struct vm_params params, int *pc_error)
{
#ifdef USE_COMPUTED_GOTO
    static void *opcode_targets[256] = {
        [0] = &&lbl_NOOP,
        [1] = &&lbl_COPY_BB,
        [2] = &&lbl_INVERT_BB,
        [3] = &&lbl_AND_BBB,
        [4] = &&lbl_OR_BBB,
        [5] = &&lbl_EQ_BBB,
        [6] = &&lbl_NE_BBB,
        [7] = &&lbl_GT_BII,
        [8] = &&lbl_GE_BII,
        [9] = &&lbl_EQ_BII,
        [10] = &&lbl_NE_BII,
        [11] = &&lbl_GT_BLL,
        [12] = &&lbl_GE_BLL,
        [13] = &&lbl_EQ_BLL,
        [14] = &&lbl_NE_BLL,
        [15] = &&lbl_GT_BFF,
        [16] = &&lbl_GE_BFF,
        [17] = &&lbl_EQ_BFF,
        [18] = &&lbl_NE_BFF,
        [19] = &&lbl_GT_BDD,
        [20] = &&lbl_GE_BDD,
        [21] = &&lbl_EQ_BDD,
        [22] = &&lbl_NE_BDD,
        [23] = &&lbl_GT_BSS,
        [24] = &&lbl_GE_BSS,
        [25] = &&lbl_EQ_BSS,
        [26] = &&lbl_NE_BSS,
        [27] = &&lbl_COPY_II,
        [28] = &&lbl_ONES_LIKE_I,
        [29] = &&lbl_NEG_II,
        [30] = &&lbl_ADD_III,
        [31] = &&lbl_SUB_III,
        [32] = &&lbl_MUL_III,
        [33] = &&lbl_DIV_III,
        [34] = &&lbl_POW_III,
        [35] = &&lbl_MOD_III,
        [36] = &&lbl_WHERE_IBII,
        [37] = &&lbl_CAST_LI,
        [38] = &&lbl_COPY_LL,
        [39] = &&lbl_ONES_LIKE_L,
        [40] = &&lbl_NEG_LL,
        [41] = &&lbl_ADD_LLL,
        [42] = &&lbl_SUB_LLL,
        [43] = &&lbl_MUL_LLL,
        [44] = &&lbl_DIV_LLL,
        [45] = &&lbl_POW_LLL,
        [46] = &&lbl_MOD_LLL,
        [47] = &&lbl_WHERE_LBLL,
        [48] = &&lbl_CAST_FI,
        [49] = &&lbl_CAST_FL,
        [50] = &&lbl_COPY_FF,
        [51] = &&lbl_ONES_LIKE_F,
        [52] = &&lbl_NEG_FF,
        [53] = &&lbl_ADD_FFF,
        [54] = &&lbl_SUB_FFF,
        [55] = &&lbl_MUL_FFF,
        [56] = &&lbl_DIV_FFF,
        [57] = &&lbl_POW_FFF,
        [58] = &&lbl_MOD_FFF,
        [59] = &&lbl_SQRT_FF,
        [60] = &&lbl_WHERE_FBFF,
        [61] = &&lbl_FUNC_FFN,
        [62] = &&lbl_FUNC_FFFN,
        [63] = &&lbl_CAST_DI,
        [64] = &&lbl_CAST_DL,
        [65] = &&lbl_CAST_DF,
        [66] = &&lbl_COPY_DD,
        [67] = &&lbl_ONES_LIKE_D,
        [68] = &&lbl_NEG_DD,
        [69] = &&lbl_ADD_DDD,
        [70] = &&lbl_SUB_DDD,
        [71] = &&lbl_MUL_DDD,
        [72] = &&lbl_DIV_DDD,
        [73] = &&lbl_POW_DDD,
        [74] = &&lbl_MOD_DDD,
        [75] = &&lbl_SQRT_DD,
        [76] = &&lbl_WHERE_DBDD,
        [77] = &&lbl_FUNC_DDN,
        [78] = &&lbl_FUNC_DDDN,
        [79] = &&lbl_EQ_BCC,
        [80] = &&lbl_NE_BCC,
        [81] = &&lbl_CAST_CI,
        [82] = &&lbl_CAST_CL,
        [83] = &&lbl_CAST_CF,
        [84] = &&lbl_CAST_CD,
        [85] = &&lbl_ONES_LIKE_C,
        [86] = &&lbl_COPY_CC,
        [87] = &&lbl_NEG_CC,
        [88] = &&lbl_ADD_CCC,
        [89] = &&lbl_SUB_CCC,
        [90] = &&lbl_MUL_CCC,
        [91] = &&lbl_DIV_CCC,
        [92] = &&lbl_WHERE_CBCC,
        [93] = &&lbl_FUNC_CCN,
        [94] = &&lbl_FUNC_CCCN,
        [95] = &&lbl_REAL_DC,
        [96] = &&lbl_IMAG_DC,
        [97] = &&lbl_COMPLEX_CDD,
        [98] = &&lbl_COPY_SS,
        [99] = &&unknown_opcode,
        [100] = &&unknown_opcode,
        [101] = &&lbl_SUM_IIN,
        [102] = &&lbl_SUM_LLN,
        [103] = &&lbl_SUM_FFN,
        [104] = &&lbl_SUM_DDN,
        [105] = &&lbl_SUM_CCN,
        [106] = &&unknown_opcode,
        [107] = &&lbl_PROD_IIN,
        [108] = &&lbl_PROD_LLN,
        [109] = &&lbl_PROD_FFN,
        [110] = &&lbl_PROD_DDN,
        [111] = &&lbl_PROD_CCN,
        [112] = &&unknown_opcode,
        [113] = &&unknown_opcode,
        [114] = &&unknown_opcode,
        [115] = &&unknown_opcode,
        [116] = &&unknown_opcode,
        [117] = &&unknown_opcode,
        [118] = &&unknown_opcode,
        [119] = &&unknown_opcode,
        [120] = &&unknown_opcode,
        [121] = &&unknown_opcode,
        [122] = &&unknown_opcode,
        [123] = &&unknown_opcode,
        [124] = &&unknown_opcode,
        [125] = &&unknown_opcode,
        [126] = &&unknown_opcode,
        [127] = &&unknown_opcode,
        [128] = &&unknown_opcode,
        [129] = &&unknown_opcode,
        [130] = &&unknown_opcode,
        [131] = &&unknown_opcode,
        [132] = &&unknown_opcode,
        [133] = &&unknown_opcode,
        [134] = &&unknown_opcode,
        [135] = &&unknown_opcode,
        [136] = &&unknown_opcode,
        [137] = &&unknown_opcode,
        [138] = &&unknown_opcode,
        [139] = &&unknown_opcode,
        [140] = &&unknown_opcode,
        [141] = &&unknown_opcode,
        [142] = &&unknown_opcode,
        [143] = &&unknown_opcode,
        [144] = &&unknown_opcode,
        [145] = &&unknown_opcode,
        [146] = &&unknown_opcode,
        [147] = &&unknown_opcode,
        [148] = &&unknown_opcode,
        [149] = &&unknown_opcode,
        [150] = &&unknown_opcode,
        [151] = &&unknown_opcode,
        [152] = &&unknown_opcode,
        [153] = &&unknown_opcode,
        [154] = &&unknown_opcode,
        [155] = &&unknown_opcode,
        [156] = &&unknown_opcode,
        [157] = &&unknown_opcode,
        [158] = &&unknown_opcode,
        [159] = &&unknown_opcode,
        [160] = &&unknown_opcode,
        [161] = &&unknown_opcode,
        [162] = &&unknown_opcode,
        [163] = &&unknown_opcode,
        [164] = &&unknown_opcode,
        [165] = &&unknown_opcode,
        [166] = &&unknown_opcode,
        [167] = &&unknown_opcode,
        [168] = &&unknown_opcode,
        [169] = &&unknown_opcode,
        [170] = &&unknown_opcode,
        [171] = &&unknown_opcode,
        [172] = &&unknown_opcode,
        [173] = &&unknown_opcode,
        [174] = &&unknown_opcode,
        [175] = &&unknown_opcode,
        [176] = &&unknown_opcode,
        [177] = &&unknown_opcode,
        [178] = &&unknown_opcode,
        [179] = &&unknown_opcode,
        [180] = &&unknown_opcode,
        [181] = &&unknown_opcode,
        [182] = &&unknown_opcode,
        [183] = &&unknown_opcode,
        [184] = &&unknown_opcode,
        [185] = &&unknown_opcode,
        [186] = &&unknown_opcode,
        [187] = &&unknown_opcode,
        [188] = &&unknown_opcode,
        [189] = &&unknown_opcode,
        [190] = &&unknown_opcode,
        [191] = &&unknown_opcode,
        [192] = &&unknown_opcode,
        [193] = &&unknown_opcode,
        [194] = &&unknown_opcode,
        [195] = &&unknown_opcode,
        [196] = &&unknown_opcode,
        [197] = &&unknown_opcode,
        [198] = &&unknown_opcode,
        [199] = &&unknown_opcode,
        [200] = &&unknown_opcode,
        [201] = &&unknown_opcode,
        [202] = &&unknown_opcode,
        [203] = &&unknown_opcode,
        [204] = &&unknown_opcode,
        [205] = &&unknown_opcode,
        [206] = &&unknown_opcode,
        [207] = &&unknown_opcode,
        [208] = &&unknown_opcode,
        [209] = &&unknown_opcode,
        [210] = &&unknown_opcode,
        [211] = &&unknown_opcode,
        [212] = &&unknown_opcode,
        [213] = &&unknown_opcode,
        [214] = &&unknown_opcode,
        [215] = &&unknown_opcode,
        [216] = &&unknown_opcode,
        [217] = &&unknown_opcode,
        [218] = &&unknown_opcode,
        [219] = &&unknown_opcode,
        [220] = &&unknown_opcode,
        [221] = &&unknown_opcode,
        [222] = &&unknown_opcode,
        [223] = &&unknown_opcode,
        [224] = &&unknown_opcode,
        [225] = &&unknown_opcode,
        [226] = &&unknown_opcode,
        [227] = &&unknown_opcode,
        [228] = &&unknown_opcode,
        [229] = &&unknown_opcode,
        [230] = &&unknown_opcode,
        [231] = &&unknown_opcode,
        [232] = &&unknown_opcode,
        [233] = &&unknown_opcode,
        [234] = &&unknown_opcode,
        [235] = &&unknown_opcode,
        [236] = &&unknown_opcode,
        [237] = &&unknown_opcode,
        [238] = &&unknown_opcode,
        [239] = &&unknown_opcode,
        [240] = &&unknown_opcode,
        [241] = &&unknown_opcode,
        [242] = &&unknown_opcode,
        [243] = &&unknown_opcode,
        [244] = &&unknown_opcode,
        [245] = &&unknown_opcode,
        [246] = &&unknown_opcode,
        [247] = &&unknown_opcode,
        [248] = &&unknown_opcode,
        [249] = &&unknown_opcode,
        [250] = &&unknown_opcode,
        [251] = &&unknown_opcode,
        [252] = &&unknown_opcode,
        [253] = &&unknown_opcode,
        [254] = &&unknown_opcode,
        [255] = &&unknown_opcode,
    };
#endif
#ifdef USE_COMPUTED_GOTO
# define TARGET(op) lbl_##op:
# define USES_STORE_IN unsigned int store_in = params.program[pc+1]
# define USES_ARG1 unsigned int arg1 = params.program[pc+2]
# define USES_ARG2 unsigned int arg2 = params.program[pc+3]
# define USES_ARG3 unsigned int arg3 = params.program[pc+5]
# define NEXT() pc += 4; if (pc >= params.prog_len) return 0; \
    op = params.program[pc]; goto *opcode_targets[op];
# define NEXT2() pc += 8; if (pc >= params.prog_len) return 0; \
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
    unsigned int pc = 0;
#ifdef USE_COMPUTED_GOTO
    unsigned int op = params.program[pc];
    goto *opcode_targets[op];
    { {
#else
    for (pc = 0; pc < params.prog_len; pc += 4) {
        unsigned int op = params.program[pc];
        unsigned int store_in = params.program[pc+1];
        unsigned int arg1 = params.program[pc+2];
        unsigned int arg2 = params.program[pc+3];
        switch (op) {
#endif
        TARGET(NOOP) {
            // Code
            NEXT(); }
        TARGET(COPY_BB) {
            // rtype=b atypes=b
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                *r = a1;
            }
            NEXT(); }
        TARGET(INVERT_BB) {
            // rtype=b atypes=b
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                *r = !a1;
            }
            NEXT(); }
        TARGET(AND_BBB) {
            // rtype=b atypes=bb
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                char a2 = *(char *)(a2_base+j*a2_step);
                *r = a1 && a2;
            }
            NEXT(); }
        TARGET(OR_BBB) {
            // rtype=b atypes=bb
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                char a2 = *(char *)(a2_base+j*a2_step);
                *r = a1 || a2;
            }
            NEXT(); }
        TARGET(EQ_BBB) {
            // rtype=b atypes=bb
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                char a2 = *(char *)(a2_base+j*a2_step);
                *r = a1 == a2;
            }
            NEXT(); }
        TARGET(NE_BBB) {
            // rtype=b atypes=bb
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                char a2 = *(char *)(a2_base+j*a2_step);
                *r = a1 != a2;
            }
            NEXT(); }
        TARGET(GT_BII) {
            // rtype=b atypes=ii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                *r = a1 > a2;
            }
            NEXT(); }
        TARGET(GE_BII) {
            // rtype=b atypes=ii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                *r = a1 >= a2;
            }
            NEXT(); }
        TARGET(EQ_BII) {
            // rtype=b atypes=ii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                *r = a1 == a2;
            }
            NEXT(); }
        TARGET(NE_BII) {
            // rtype=b atypes=ii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                *r = a1 != a2;
            }
            NEXT(); }
        TARGET(GT_BLL) {
            // rtype=b atypes=ll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                *r = a1 > a2;
            }
            NEXT(); }
        TARGET(GE_BLL) {
            // rtype=b atypes=ll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                *r = a1 >= a2;
            }
            NEXT(); }
        TARGET(EQ_BLL) {
            // rtype=b atypes=ll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                *r = a1 == a2;
            }
            NEXT(); }
        TARGET(NE_BLL) {
            // rtype=b atypes=ll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                *r = a1 != a2;
            }
            NEXT(); }
        TARGET(GT_BFF) {
            // rtype=b atypes=ff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = a1 > a2;
            }
            NEXT(); }
        TARGET(GE_BFF) {
            // rtype=b atypes=ff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = a1 >= a2;
            }
            NEXT(); }
        TARGET(EQ_BFF) {
            // rtype=b atypes=ff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = a1 == a2;
            }
            NEXT(); }
        TARGET(NE_BFF) {
            // rtype=b atypes=ff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = a1 != a2;
            }
            NEXT(); }
        TARGET(GT_BDD) {
            // rtype=b atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = a1 > a2;
            }
            NEXT(); }
        TARGET(GE_BDD) {
            // rtype=b atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = a1 >= a2;
            }
            NEXT(); }
        TARGET(EQ_BDD) {
            // rtype=b atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = a1 == a2;
            }
            NEXT(); }
        TARGET(NE_BDD) {
            // rtype=b atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = a1 != a2;
            }
            NEXT(); }
        TARGET(GT_BSS) {
            // rtype=b atypes=ss
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            intp a1_len = params.memsizes[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            intp a2_len = params.memsizes[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                char *a1_ptr = (char *)(a1_base+j*a1_step);
                char *a2_ptr = (char *)(a2_base+j*a2_step);
                *r = stringcmp(a1_ptr, a2_ptr, a1_len, a2_len) > 0;
            }
            NEXT(); }
        TARGET(GE_BSS) {
            // rtype=b atypes=ss
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            intp a1_len = params.memsizes[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            intp a2_len = params.memsizes[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                char *a1_ptr = (char *)(a1_base+j*a1_step);
                char *a2_ptr = (char *)(a2_base+j*a2_step);
                *r = stringcmp(a1_ptr, a2_ptr, a1_len, a2_len) >= 0;
            }
            NEXT(); }
        TARGET(EQ_BSS) {
            // rtype=b atypes=ss
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            intp a1_len = params.memsizes[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            intp a2_len = params.memsizes[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                char *a1_ptr = (char *)(a1_base+j*a1_step);
                char *a2_ptr = (char *)(a2_base+j*a2_step);
                *r = stringcmp(a1_ptr, a2_ptr, a1_len, a2_len) == 0;
            }
            NEXT(); }
        TARGET(NE_BSS) {
            // rtype=b atypes=ss
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            intp a1_len = params.memsizes[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            intp a2_len = params.memsizes[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                char *a1_ptr = (char *)(a1_base+j*a1_step);
                char *a2_ptr = (char *)(a2_base+j*a2_step);
                *r = stringcmp(a1_ptr, a2_ptr, a1_len, a2_len) != 0;
            }
            NEXT(); }
        TARGET(COPY_II) {
            // rtype=i atypes=i
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            int *dest = (int *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = dest + j;
                int *a1_ptr = (int *)(a1_base+j*a1_step);
                memcpy(r, a1_ptr, sizeof(int));
            }
            NEXT(); }
        TARGET(ONES_LIKE_I) {
            // rtype=i atypes=
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            int *dest = (int *)(params.mem[store_in]);
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = dest + j;
                *r = 1;
            }
            NEXT(); }
        TARGET(NEG_II) {
            // rtype=i atypes=i
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            int *dest = (int *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                *r = -a1;
            }
            NEXT(); }
        TARGET(ADD_III) {
            // rtype=i atypes=ii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            int *dest = (int *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                *r = a1 + a2;
            }
            NEXT(); }
        TARGET(SUB_III) {
            // rtype=i atypes=ii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            int *dest = (int *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                *r = a1 - a2;
            }
            NEXT(); }
        TARGET(MUL_III) {
            // rtype=i atypes=ii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            int *dest = (int *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                *r = a1 * a2;
            }
            NEXT(); }
        TARGET(DIV_III) {
            // rtype=i atypes=ii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            int *dest = (int *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                *r = a1 / a2;
            }
            NEXT(); }
        TARGET(POW_III) {
            // rtype=i atypes=ii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            int *dest = (int *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                *r = (a2 < 0) ? (1/a1) : (int)pow(a1, a2);
            }
            NEXT(); }
        TARGET(MOD_III) {
            // rtype=i atypes=ii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            int *dest = (int *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                *r = a1 % a2;
            }
            NEXT(); }
        TARGET(WHERE_IBII) {
            // rtype=i atypes=bii
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            int *dest = (int *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            USES_ARG3;
            BOUNDS_CHECK(arg3);
            char *a3_base = params.mem[arg3];
            intp a3_step = params.memsteps[arg3];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                int a2 = *(int *)(a2_base+j*a2_step);
                int a3 = *(int *)(a3_base+j*a3_step);
                *r = a1 ? a2 : a3;
            }
            NEXT2(); }
        TARGET(CAST_LI) {
            // rtype=l atypes=i
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                *r = (long long)(a1);
            }
            NEXT(); }
        TARGET(COPY_LL) {
            // rtype=l atypes=l
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                long long *a1_ptr = (long long *)(a1_base+j*a1_step);
                memcpy(r, a1_ptr, sizeof(long long));
            }
            NEXT(); }
        TARGET(ONES_LIKE_L) {
            // rtype=l atypes=
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                *r = 1;
            }
            NEXT(); }
        TARGET(NEG_LL) {
            // rtype=l atypes=l
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                *r = -a1;
            }
            NEXT(); }
        TARGET(ADD_LLL) {
            // rtype=l atypes=ll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                *r = a1 + a2;
            }
            NEXT(); }
        TARGET(SUB_LLL) {
            // rtype=l atypes=ll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                *r = a1 - a2;
            }
            NEXT(); }
        TARGET(MUL_LLL) {
            // rtype=l atypes=ll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                *r = a1 * a2;
            }
            NEXT(); }
        TARGET(DIV_LLL) {
            // rtype=l atypes=ll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                *r = a1 / a2;
            }
            NEXT(); }
        TARGET(POW_LLL) {
            // rtype=l atypes=ll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                *r = (a2 < 0) ? (1/a1) : (long long)pow(a1, a2);
            }
            NEXT(); }
        TARGET(MOD_LLL) {
            // rtype=l atypes=ll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                *r = a1 % a2;
            }
            NEXT(); }
        TARGET(WHERE_LBLL) {
            // rtype=l atypes=bll
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            long long *dest = (long long *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            USES_ARG3;
            BOUNDS_CHECK(arg3);
            char *a3_base = params.mem[arg3];
            intp a3_step = params.memsteps[arg3];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                long long a2 = *(long long *)(a2_base+j*a2_step);
                long long a3 = *(long long *)(a3_base+j*a3_step);
                *r = a1 ? a2 : a3;
            }
            NEXT2(); }
        TARGET(CAST_FI) {
            // rtype=f atypes=i
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                *r = (float)(a1);
            }
            NEXT(); }
        TARGET(CAST_FL) {
            // rtype=f atypes=l
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                *r = (float)(a1);
            }
            NEXT(); }
        TARGET(COPY_FF) {
            // rtype=f atypes=f
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float *a1_ptr = (float *)(a1_base+j*a1_step);
                memcpy(r, a1_ptr, sizeof(float));
            }
            NEXT(); }
        TARGET(ONES_LIKE_F) {
            // rtype=f atypes=
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                *r = 1.0;
            }
            NEXT(); }
        TARGET(NEG_FF) {
            // rtype=f atypes=f
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                *r = -a1;
            }
            NEXT(); }
        TARGET(ADD_FFF) {
            // rtype=f atypes=ff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = a1 + a2;
            }
            NEXT(); }
        TARGET(SUB_FFF) {
            // rtype=f atypes=ff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = a1 - a2;
            }
            NEXT(); }
        TARGET(MUL_FFF) {
            // rtype=f atypes=ff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = a1 * a2;
            }
            NEXT(); }
        TARGET(DIV_FFF) {
#if defined(USE_VML)
            float *dest = (float *)(params.mem[store_in]);
            float *x1 = (float *)(params.mem[arg1]);
            float *x2 = (float *)(params.mem[arg2]);
            vsDiv(VECTOR_SIZE, x1, x2, dest);
#else
            // rtype=f atypes=ff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = a1 / a2;
            }
#endif
            NEXT(); }
        TARGET(POW_FFF) {
#if defined(USE_VML)
            float *dest = (float *)(params.mem[store_in]);
            float *x1 = (float *)(params.mem[arg1]);
            float *x2 = (float *)(params.mem[arg2]);
            vsPow(VECTOR_SIZE, x1, x2, dest);
#else
            // rtype=f atypes=ff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = powf(a1, a2);
            }
#endif
            NEXT(); }
        TARGET(MOD_FFF) {
            // rtype=f atypes=ff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = a1 - floorf(a1/a2) * a2;
            }
            NEXT(); }
        TARGET(SQRT_FF) {
#if defined(USE_VML)
            float *dest = (float *)(params.mem[store_in]);
            float *x1 = (float *)(params.mem[arg1]);
            vsSqrt(VECTOR_SIZE, x1, dest);
#else
            // rtype=f atypes=f
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                *r = sqrtf(a1);
            }
#endif
            NEXT(); }
        TARGET(WHERE_FBFF) {
            // rtype=f atypes=bff
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            USES_ARG3;
            BOUNDS_CHECK(arg3);
            char *a3_base = params.mem[arg3];
            intp a3_step = params.memsteps[arg3];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                float a3 = *(float *)(a3_base+j*a3_step);
                *r = a1 ? a2 : a3;
            }
            NEXT2(); }
        TARGET(FUNC_FFN) {
#if defined(USE_VML)
            float *dest = (float *)(params.mem[store_in]);
            float *x1 = (float *)(params.mem[arg1]);
            functions_ff_vml[arg2](VECTOR_SIZE, x1, x2, dest);
#else
            // rtype=f atypes=fn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                *r = functions_ff[arg2](a1);
            }
#endif
            NEXT(); }
        TARGET(FUNC_FFFN) {
#if defined(USE_VML)
            float *dest = (float *)(params.mem[store_in]);
            float *x1 = (float *)(params.mem[arg1]);
            float *x2 = (float *)(params.mem[arg2]);
            functions_fff_vml[arg3](VECTOR_SIZE, x1, x2, x3, dest);
#else
            // rtype=f atypes=ffn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            float *dest = (float *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            USES_ARG3;
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                float a2 = *(float *)(a2_base+j*a2_step);
                *r = functions_fff[arg3](a1, a2);
            }
#endif
            NEXT2(); }
        TARGET(CAST_DI) {
            // rtype=d atypes=i
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                *r = (double)(a1);
            }
            NEXT(); }
        TARGET(CAST_DL) {
            // rtype=d atypes=l
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                *r = (double)(a1);
            }
            NEXT(); }
        TARGET(CAST_DF) {
            // rtype=d atypes=f
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                *r = (double)(a1);
            }
            NEXT(); }
        TARGET(COPY_DD) {
            // rtype=d atypes=d
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double *a1_ptr = (double *)(a1_base+j*a1_step);
                memcpy(r, a1_ptr, sizeof(double));
            }
            NEXT(); }
        TARGET(ONES_LIKE_D) {
            // rtype=d atypes=
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                *r = 1.0;
            }
            NEXT(); }
        TARGET(NEG_DD) {
            // rtype=d atypes=d
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                *r = -a1;
            }
            NEXT(); }
        TARGET(ADD_DDD) {
            // rtype=d atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = a1 + a2;
            }
            NEXT(); }
        TARGET(SUB_DDD) {
            // rtype=d atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = a1 - a2;
            }
            NEXT(); }
        TARGET(MUL_DDD) {
            // rtype=d atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = a1 * a2;
            }
            NEXT(); }
        TARGET(DIV_DDD) {
#if defined(USE_VML)
            double *dest = (double *)(params.mem[store_in]);
            double *x1 = (double *)(params.mem[arg1]);
            double *x2 = (double *)(params.mem[arg2]);
            vdDiv(VECTOR_SIZE, x1, x2, dest);
#else
            // rtype=d atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = a1 / a2;
            }
#endif
            NEXT(); }
        TARGET(POW_DDD) {
#if defined(USE_VML)
            double *dest = (double *)(params.mem[store_in]);
            double *x1 = (double *)(params.mem[arg1]);
            double *x2 = (double *)(params.mem[arg2]);
            vdPow(VECTOR_SIZE, x1, x2, dest);
#else
            // rtype=d atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = pow(a1, a2);
            }
#endif
            NEXT(); }
        TARGET(MOD_DDD) {
            // rtype=d atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = a1 - floor(a1/a2) * a2;
            }
            NEXT(); }
        TARGET(SQRT_DD) {
#if defined(USE_VML)
            double *dest = (double *)(params.mem[store_in]);
            double *x1 = (double *)(params.mem[arg1]);
            vdSqrt(VECTOR_SIZE, x1, dest);
#else
            // rtype=d atypes=d
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                *r = sqrt(a1);
            }
#endif
            NEXT(); }
        TARGET(WHERE_DBDD) {
            // rtype=d atypes=bdd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            USES_ARG3;
            BOUNDS_CHECK(arg3);
            char *a3_base = params.mem[arg3];
            intp a3_step = params.memsteps[arg3];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                double a3 = *(double *)(a3_base+j*a3_step);
                *r = a1 ? a2 : a3;
            }
            NEXT2(); }
        TARGET(FUNC_DDN) {
#if defined(USE_VML)
            double *dest = (double *)(params.mem[store_in]);
            double *x1 = (double *)(params.mem[arg1]);
            functions_dd_vml[arg2](VECTOR_SIZE, x1, x2, dest);
#else
            // rtype=d atypes=dn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                *r = functions_dd[arg2](a1);
            }
#endif
            NEXT(); }
        TARGET(FUNC_DDDN) {
#if defined(USE_VML)
            double *dest = (double *)(params.mem[store_in]);
            double *x1 = (double *)(params.mem[arg1]);
            double *x2 = (double *)(params.mem[arg2]);
            functions_ddd_vml[arg3](VECTOR_SIZE, x1, x2, x3, dest);
#else
            // rtype=d atypes=ddn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            USES_ARG3;
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                *r = functions_ddd[arg3](a1, a2);
            }
#endif
            NEXT2(); }
        TARGET(EQ_BCC) {
            // rtype=b atypes=cc
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1r = a1.real;
                double a1i = a1.imag;
                cdouble a2 = *(cdouble *)(a2_base+j*a2_step);
                double a2r = a2.real;
                double a2i = a2.imag;
                *r = a1r == a2r && a1i == a2i;
            }
            NEXT(); }
        TARGET(NE_BCC) {
            // rtype=b atypes=cc
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1r = a1.real;
                double a1i = a1.imag;
                cdouble a2 = *(cdouble *)(a2_base+j*a2_step);
                double a2r = a2.real;
                double a2i = a2.imag;
                *r = a1r != a2r || a1i != a2i;
            }
            NEXT(); }
        TARGET(CAST_CI) {
            // rtype=c atypes=i
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                int a1 = *(int *)(a1_base+j*a1_step);
                r->real = (double)a1;
                r->imag = 0;
            }
            NEXT(); }
        TARGET(CAST_CL) {
            // rtype=c atypes=l
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                long long a1 = *(long long *)(a1_base+j*a1_step);
                r->real = (double)a1;
                r->imag = 0;
            }
            NEXT(); }
        TARGET(CAST_CF) {
            // rtype=c atypes=f
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                float a1 = *(float *)(a1_base+j*a1_step);
                r->real = (double)a1;
                r->imag = 0;
            }
            NEXT(); }
        TARGET(CAST_CD) {
            // rtype=c atypes=d
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                r->real = (double)a1;
                r->imag = 0;
            }
            NEXT(); }
        TARGET(ONES_LIKE_C) {
            // rtype=c atypes=
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                r->real = 1;
                r->imag = 0;
            }
            NEXT(); }
        TARGET(COPY_CC) {
            // rtype=c atypes=c
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                cdouble *a1_ptr = (cdouble *)(a1_base+j*a1_step);
                memcpy(r, a1_ptr, sizeof(cdouble));
            }
            NEXT(); }
        TARGET(NEG_CC) {
            // rtype=c atypes=c
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1r = a1.real;
                double a1i = a1.imag;
                r->real = -a1r;
                r->imag = -a1i;
            }
            NEXT(); }
        TARGET(ADD_CCC) {
            // rtype=c atypes=cc
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1r = a1.real;
                double a1i = a1.imag;
                cdouble a2 = *(cdouble *)(a2_base+j*a2_step);
                double a2r = a2.real;
                double a2i = a2.imag;
                r->real = a1r+a2r;
                r->imag = a1i+a2i;
            }
            NEXT(); }
        TARGET(SUB_CCC) {
            // rtype=c atypes=cc
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1r = a1.real;
                double a1i = a1.imag;
                cdouble a2 = *(cdouble *)(a2_base+j*a2_step);
                double a2r = a2.real;
                double a2i = a2.imag;
                r->real = a1r-a2r;
                r->imag = a1i-a2i;
            }
            NEXT(); }
        TARGET(MUL_CCC) {
            // rtype=c atypes=cc
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1r = a1.real;
                double a1i = a1.imag;
                cdouble a2 = *(cdouble *)(a2_base+j*a2_step);
                double a2r = a2.real;
                double a2i = a2.imag;
                r->real = a1r*a2r - a1i*a2i;
                r->imag = a1r*a2i + a1i*a2r;
            }
            NEXT(); }
        TARGET(DIV_CCC) {
            // rtype=c atypes=cc
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1r = a1.real;
                double a1i = a1.imag;
                cdouble a2 = *(cdouble *)(a2_base+j*a2_step);
                double a2r = a2.real;
                double a2i = a2.imag;
                double da = a2r*a2r + a2i*a2i;
                r->real = (a1r*a2r + a1i*a2i) / da;
                r->imag = (a1i*a2r - a1r*a2i) / da;
            }
            NEXT(); }
        TARGET(WHERE_CBCC) {
            // rtype=c atypes=bcc
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            USES_ARG3;
            BOUNDS_CHECK(arg3);
            char *a3_base = params.mem[arg3];
            intp a3_step = params.memsteps[arg3];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                char a1 = *(char *)(a1_base+j*a1_step);
                cdouble a2 = *(cdouble *)(a2_base+j*a2_step);
                double a2r = a2.real;
                double a2i = a2.imag;
                cdouble a3 = *(cdouble *)(a3_base+j*a3_step);
                double a3r = a3.real;
                double a3i = a3.imag;
                r->real = a1 ? a2r : a3r;
                r->imag = a1 ? a2i : a3i;
            }
            NEXT2(); }
        TARGET(FUNC_CCN) {
#if defined(USE_VML)
            MKL_Complex16 *dest = (MKL_Complex16 *)(params.mem[store_in]);
            MKL_Complex16 *x1 = (MKL_Complex16 *)(params.mem[arg1]);
            functions_cc_vml[arg2](VECTOR_SIZE, x1, x2, dest);
#else
            // rtype=c atypes=cn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                cdouble ca = a1;
                functions_cc[arg2](&ca, &ca);
                r->real = ca.real;
                r->imag = ca.imag;
            }
#endif
            NEXT(); }
        TARGET(FUNC_CCCN) {
            // rtype=c atypes=ccn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            USES_ARG3;
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                cdouble a2 = *(cdouble *)(a2_base+j*a2_step);
                cdouble ca = a1; cdouble cb = a2;
                functions_ccc[arg3](&ca, &cb, &ca);
                r->real = ca.real;
                r->imag = ca.imag;
            }
            NEXT2(); }
        TARGET(REAL_DC) {
            // rtype=d atypes=c
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1r = a1.real;
                *r = a1r;
            }
            NEXT(); }
        TARGET(IMAG_DC) {
            // rtype=d atypes=c
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            double *dest = (double *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = dest + j;
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1i = a1.imag;
                *r = a1i;
            }
            NEXT(); }
        TARGET(COMPLEX_CDD) {
            // rtype=c atypes=dd
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            cdouble *dest = (cdouble *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            USES_ARG2;
            BOUNDS_CHECK(arg2);
            char *a2_base = params.mem[arg2];
            intp a2_step = params.memsteps[arg2];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = dest + j;
                double a1 = *(double *)(a1_base+j*a1_step);
                double a2 = *(double *)(a2_base+j*a2_step);
                r->real = a1;
                r->imag = a2;
            }
            NEXT(); }
        TARGET(COPY_SS) {
            // rtype=s atypes=s
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = (char *)(params.mem[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            intp a1_len = params.memsizes[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                char *r = dest+j*params.memsteps[store_in];
                char *a1_ptr = (char *)(a1_base+j*a1_step);
                memcpy(r, a1_ptr, a1_len);
            }
            NEXT(); }
        TARGET(SUM_IIN) {
            // rtype=I atypes=in
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = params.mem[store_in];
            struct index_data *store_index = &(params.index_data[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = (int *)(dest + flat_index(store_index, j));
                int a1 = *(int *)(a1_base+j*a1_step);
                *r += a1;
            }
            NEXT(); }
        TARGET(SUM_LLN) {
            // rtype=L atypes=ln
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = params.mem[store_in];
            struct index_data *store_index = &(params.index_data[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = (long long *)(dest + flat_index(store_index, j));
                long long a1 = *(long long *)(a1_base+j*a1_step);
                *r += a1;
            }
            NEXT(); }
        TARGET(SUM_FFN) {
            // rtype=F atypes=fn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = params.mem[store_in];
            struct index_data *store_index = &(params.index_data[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = (float *)(dest + flat_index(store_index, j));
                float a1 = *(float *)(a1_base+j*a1_step);
                *r += a1;
            }
            NEXT(); }
        TARGET(SUM_DDN) {
            // rtype=D atypes=dn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = params.mem[store_in];
            struct index_data *store_index = &(params.index_data[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = (double *)(dest + flat_index(store_index, j));
                double a1 = *(double *)(a1_base+j*a1_step);
                *r += a1;
            }
            NEXT(); }
        TARGET(SUM_CCN) {
            // rtype=C atypes=cn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = params.mem[store_in];
            struct index_data *store_index = &(params.index_data[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = (cdouble *)(dest + flat_index(store_index, j));
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1r = a1.real;
                double a1i = a1.imag;
                r->real = r->real + a1r;
                r->imag = r->imag + a1i;
            }
            NEXT(); }
        TARGET(PROD_IIN) {
            // rtype=I atypes=in
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = params.mem[store_in];
            struct index_data *store_index = &(params.index_data[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                int *r = (int *)(dest + flat_index(store_index, j));
                int a1 = *(int *)(a1_base+j*a1_step);
                *r *= a1;
            }
            NEXT(); }
        TARGET(PROD_LLN) {
            // rtype=L atypes=ln
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = params.mem[store_in];
            struct index_data *store_index = &(params.index_data[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                long long *r = (long long *)(dest + flat_index(store_index, j));
                long long a1 = *(long long *)(a1_base+j*a1_step);
                *r *= a1;
            }
            NEXT(); }
        TARGET(PROD_FFN) {
            // rtype=F atypes=fn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = params.mem[store_in];
            struct index_data *store_index = &(params.index_data[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                float *r = (float *)(dest + flat_index(store_index, j));
                float a1 = *(float *)(a1_base+j*a1_step);
                *r *= a1;
            }
            NEXT(); }
        TARGET(PROD_DDN) {
            // rtype=D atypes=dn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = params.mem[store_in];
            struct index_data *store_index = &(params.index_data[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                double *r = (double *)(dest + flat_index(store_index, j));
                double a1 = *(double *)(a1_base+j*a1_step);
                *r *= a1;
            }
            NEXT(); }
        TARGET(PROD_CCN) {
            // rtype=C atypes=cn
            USES_STORE_IN;
            BOUNDS_CHECK(store_in);
            char *dest = params.mem[store_in];
            struct index_data *store_index = &(params.index_data[store_in]);
            USES_ARG1;
            BOUNDS_CHECK(arg1);
            char *a1_base = params.mem[arg1];
            intp a1_step = params.memsteps[arg1];
            for (j=0; j < VECTOR_SIZE; j++) {
                cdouble *r = (cdouble *)(dest + flat_index(store_index, j));
                cdouble a1 = *(cdouble *)(a1_base+j*a1_step);
                double a1r = a1.real;
                double a1i = a1.imag;
                double rr = r->real;
                r->real = rr*a1r - r->imag*a1i;
                r->imag = rr*a1i + r->imag*a1r;
            }
            NEXT(); }
#ifdef USE_COMPUTED_GOTO
        unknown_opcode:
#else
        default:
#endif
            *pc_error = pc; return -3;
        }
    }
    return 0;
}
#undef TARGET
#undef NEXT
#undef NEXT2
#undef USES_STORE_IN
#undef USES_ARG1
#undef USES_ARG2
#undef USES_ARG3
#undef VECTOR_SIZE
