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
        }
        data = 0;
        fread(&data, sizeof(int), 1, f);
    }
    fclose(f);
    fclose(f0);
    return 0;
}
