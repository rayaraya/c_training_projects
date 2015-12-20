#include "commands.h"

int main()
{
    FILE *f = fopen("commands.bin", "rb");
    FILE *f0 = fopen ("commands.txt", "w");

    int data = 0;
    int num = 0;

    fread(&data, sizeof(int), 1, f);

    while (data != 0)
    {
        switch (data)
        {
        case c_push:
            fread(&data, sizeof(int), 1, f);
            if (data == fl_stack)
            {
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "push %d\n", data);
            }
            else if (data == fl_reg)
            {
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "push %cx\n", data);
            }
            break;
        case c_pop:
            fread(&data, sizeof(int), 1, f);
            if (data == fl_stack)
            {
                fprintf(f0, "pop\n");
            }
            else if (data == fl_reg)
            {
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "pop %cx\n", data);
            }
            break;

        case c_add:
            fread(&data, sizeof(int), 1, f);
            if (data == fl_stack)
            {
                fprintf(f0, "add\n");
            }
            else if (data == fl_reg)
            {
                fprintf(f0, "add ");
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx ", data);
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx ", data);
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx\n", data);
            }
            break;

        case c_sub:
            fread(&data, sizeof(int), 1, f);
            if (data == fl_stack)
            {
                fprintf(f0, "sub\n");
            }
            else if (data == fl_reg)
            {
                fprintf(f0, "sub ");
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx ", data);
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx ", data);
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx\n", data);
            }
            break;

        case c_mul:
            fread(&data, sizeof(int), 1, f);
            if (data == fl_stack)
            {
                fprintf(f0, "mul\n");
            }
            else if (data == fl_reg)
            {
                fprintf(f0, "mul ");
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx ", data);
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx ", data);
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx\n", data);
            }
            break;

        case c_div:
            fread(&data, sizeof(int), 1, f);
            if (data == fl_stack)
            {
                fprintf(f0, "div\n");
            }
            else if (data == fl_reg)
            {
                fprintf(f0, "div ");
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx ", data);
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx ", data);
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "%cx\n", data);
            }
            break;

        case c_print:
            fread(&data, sizeof(int), 1, f);
            if (data == fl_stack)
            {
                fprintf(f0, "print\n");
            }
            else if (data == fl_reg)
            {
                fread(&data, sizeof(int), 1, f);
                fprintf(f0, "print %cx\n", data);
            }
            break;

        case irreg_com:
            fprintf(f0, "irreg_com\n");
            break;

        case c_end:
            fprintf(f0, "end\n");
            break;

        case c_mov:
            fread(&data, sizeof(int), 1, f);
            fread(&data, sizeof(int), 1, f);
            fread(&num, sizeof(int), 1, f);
            fprintf(f0, "mov %cx ", data);
            fprintf(f0, "%d\n", num);
            break;
        }
        data = 0;
        fread(&data, sizeof(int), 1, f);
    }
    fclose(f);
    fclose(f0);
    return 0;
}
