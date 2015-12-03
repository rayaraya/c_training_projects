#include "commands.h"

int main()
{
    FILE *f = fopen("commands.bin", "rb");
    FILE *f0 = fopen ("commands.txt", "w");

    int data = 0;

    fread(&data, sizeof(int), 1, f);
    while (data != 0)
    {
        switch (data)
        {
            case c_push:
                fprintf(f0, "push ");
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%d\n", data);
                break;
            case c_pop: fprintf(f0, "pop\n"); break;
            case c_add: fprintf(f0, "add\n"); break;
            case c_sub: fprintf(f0, "sub\n"); break;
            case c_mul: fprintf(f0, "mul\n"); break;
            case c_div: fprintf(f0, "div\n"); break;
            case c_print: fprintf(f0, "print\n"); break;
            case irreg_com: fprintf(f0, "irreg_com\n"); break;
            case c_end: fprintf(f0, "end\n"); break;
            case c_mov_ax:
                fprintf(f0, "mov ax ");
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%d\n", data);
                break;
            case c_mov_bx:
                fprintf(f0, "mov bx ");
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%d\n", data);
                break;
            case c_mov_cx:
                fprintf(f0, "mov cx ");
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%d\n", data);
                break;
            case c_add_ax_bx_cx: fprintf(f0, "add ax bx cx\n"); break;
            case c_sub_ax_bx_cx: fprintf(f0, "sub ax bx cx\n"); break;
            case c_mul_ax_bx_cx: fprintf(f0, "mul ax bx cx\n"); break;
            case c_div_ax_bx_cx: fprintf(f0, "div ax bx cx\n"); break;
            case c_push_ax: fprintf(f0, "push ax\n"); break;
            case c_pop_ax: fprintf(f0, "pop ax\n"); break;
            case c_print_ax: fprintf(f0, "print ax\n"); break;

        }
        data = 0;
        fread(&data, sizeof(int), 1, f);
    }
    fclose(f);
    fclose(f0);
    return 0;
}
