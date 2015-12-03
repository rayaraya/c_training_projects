#include "commands.h"
#include "stack0.h"

int main()
{
    FILE *f = fopen("commands.bin", "rb");

    struct Stack * s;
    s = stack_create();

    int com = 0, d = 0;

    int ax = 0;
    int bx = 0;
    int cx = 0;

    fread(&com, sizeof(int), 1, f);

    while (com != c_end && com != irreg_com && com != 0)
    {
        switch (com)
        {
            case c_push:
                fread(&d, sizeof(int), 1, f);
                push(s, d);
                break;
            case c_pop: pop(s); break;
            case c_add: add(s); break;
            case c_sub: sub(s); break;
            case c_mul: mul(s); break;
            case c_div: _div(s); break;
            case c_print: dump(s); break;
            case c_mov_ax:
                fread(&d, sizeof(int), 1, f);
                ax = d;
                break;
            case c_mov_bx:
                fread(&d, sizeof(int), 1, f);
                bx = d;
                break;
            case c_mov_cx:
                fread(&d, sizeof(int), 1, f);
                cx = d;
                break;
            case c_add_ax_bx_cx: ax = bx + cx; break;
            case c_sub_ax_bx_cx: ax = bx - cx; break;
            case c_mul_ax_bx_cx: ax = bx * cx; break;
            case c_div_ax_bx_cx: ax = bx / cx; break;
            case c_push_ax: push(s, ax); break;
            case c_pop_ax: ax = pop(s); break;
            case c_print_ax: printf("%d\n", ax); break;
        }
        fread(&com, sizeof(int), 1, f);
    }
    fclose(f);
    return 0;
}
