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
    c_print = 16,
    irreg_com = 90,
    c_end = 99
};

enum cmds_regs
{
    c_mov_ax = 20,
    c_mov_bx = 21,
    c_mov_cx = 22,
    c_add_ax_bx_cx = 23,
    c_sub_ax_bx_cx = 24,
    c_mul_ax_bx_cx = 25,
    c_div_ax_bx_cx = 26,
    c_push_ax = 27,
    c_pop_ax = 28,
    c_print_ax = 29
};
