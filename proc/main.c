#include "commands.h"
#include "stack0.h"

int main()
{
    FILE *f = fopen("commands.bin", "rb");

    struct Stack * s;
    s = stack_create();

    int n_register[26] = { };

    int com = 0, com_1 = 0, d = 0;

    fread(&com, sizeof(int), 1, f);

    while (com != c_end && com != irreg_com && com != 0)
    {
        switch (com)
        {
        case c_push:
            fread(&com, sizeof(int), 1, f);
            if (com == fl_stack)
            {
                fread(&d, sizeof(int), 1, f);
                push(s, d);
            }
            else if (com == fl_reg)
            {
                fread(&com, sizeof(int), 1, f);
                com = com - 'a';
                push(s, n_register[com]);
            }
            break;
        case c_pop:
            fread(&com, sizeof(int), 1, f);
            if (com == fl_stack)
            {
                pop(s);
            }
            else if (com == fl_reg)
            {
                fread(&com, sizeof(int), 1, f);
                com = com - 'a';
                n_register[com] = pop(s);
            }
            break;

        case c_add:
            fread(&com, sizeof(int), 1, f);
            if (com == fl_stack)
            {
                add(s);
            }
            else if (com == fl_reg)
            {
                fread(&com, sizeof(int), 1, f);
                fread(&com_1, sizeof(int), 1, f);
                com = com - 'a';
                com_1 = com_1 - 'a';
                n_register[com] = n_register[com_1];
                fread(&com_1, sizeof(int), 1, f);
                com_1 = com_1 - 'a';
                n_register[com] += n_register[com_1];
            }
            break;

        case c_sub:
            fread(&com, sizeof(int), 1, f);
            if (com == fl_stack)
            {
                sub(s);
            }
            else if (com == fl_reg)
            {
                fread(&com, sizeof(int), 1, f);
                fread(&com_1, sizeof(int), 1, f);
                com = com - 'a';
                com_1 = com_1 - 'a';
                n_register[com] = n_register[com_1];
                fread(&com_1, sizeof(int), 1, f);
                com_1 = com_1 - 'a';
                n_register[com] -= n_register[com_1];
            }
            break;

        case c_mul:
            fread(&com, sizeof(int), 1, f);
            if (com == fl_stack)
            {
                mul(s);
            }
            else if (com == fl_reg)
            {
                fread(&com, sizeof(int), 1, f);
                fread(&com_1, sizeof(int), 1, f);
                com = com - 'a';
                com_1 = com_1 - 'a';
                n_register[com] = n_register[com_1];
                fread(&com_1, sizeof(int), 1, f);
                com_1 = com_1 - 'a';
                n_register[com] *= n_register[com_1];
            }
            break;

        case c_div:
            fread(&com, sizeof(int), 1, f);
            if (com == fl_stack)
            {
                _div(s);
            }
            else if (com == fl_reg)
            {
                fread(&com, sizeof(int), 1, f);
                fread(&com_1, sizeof(int), 1, f);
                com = com - 'a';
                com_1 = com_1 - 'a';
                n_register[com] = n_register[com_1];
                fread(&com_1, sizeof(int), 1, f);
                com_1 = com_1 - 'a';
                n_register[com] /= n_register[com_1];
            }
            break;

        case c_print:
            fread(&com, sizeof(int), 1, f);
            if (com == fl_stack)
            {
                dump(s);
            }
            else if (com == fl_reg)
            {
                fread(&com, sizeof(int), 1, f);
                com = com - 'a';
                printf("%d\n", n_register[com]);
            }
            break;

        case c_mov:
            fread(&com, sizeof(int), 1, f);
            fread(&com, sizeof(int), 1, f);
            fread(&d, sizeof(int), 1, f);
            com = com - 'a';
            n_register[com] = d;
            break;
        }
        com = 0;
        fread(&com, sizeof(int), 1, f);
    }
    fclose(f);

    stack_clear(s);
    stack_destroy(s);
    return 0;
}
