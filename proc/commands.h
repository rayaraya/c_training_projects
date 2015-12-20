#include <stdio.h>
#include <stdlib.h>

enum cmds_stack
{
    c_push = 10,
    c_pop = 11,
    c_add = 12,
    c_sub = 13,
    c_mul = 14,
    c_div = 15,
    c_print = 16, //print full stack content or stack is empty
    irreg_com = 90,
    c_end = 999,
    fl_stack = 60
};

enum cmds_regs
{
    fl_reg = 70,
    c_mov = 17
};
