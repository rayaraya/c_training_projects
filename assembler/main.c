#include "commands.h"

int main()
{
    FILE * f0 = fopen ("commands.txt", "r");
    FILE * f = fopen ("commands.bin", "wb");

    char c, k1, k2;
    int n = 0;
    int com = 0, d = 0, fl = 0, reg = 0;

    fscanf(f0, "%c", &c);

    while (c != 0)
    {
        if (c == 'p')
        {
            fscanf(f0, "%c", &c);
            if (c == 'u')
            {
                fscanf(f0, "%c", &c);
                fscanf(f0, "%c", &k1);
                if(c == 's' && k1 == 'h')
                {
                    fscanf(f0, "%c", &c);
                    fscanf(f0, "%c", &k1);

                    if (c == ' ')
                    {
                        if (k1 <= 'z' && k1 >= 'a')
                        {
                            n = k1;
                            fscanf(f0, "%c", &c);
                            if (c == 'x')
                            {
                                com = c_push;
                                reg = fl_reg;
                                fwrite(&com, sizeof(int), 1, f);
                                fwrite(&reg, sizeof(int), 1, f);
                                fwrite(&n, sizeof(int), 1, f);
                                fscanf(f0, "%c", &c);
                                fl = 1;
                            }
                        }
                        switch (k1)
                        {
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9':
                        case '0':
                            d = k1 - '0';
                            fscanf(f0, "%c", &k1);
                            while (k1 != '\n' && k1 >= '0' && k1 <= '9')
                            {
                                d = d * 10 + (k1 - '0');
                                fscanf(f0, "%c", &k1);
                            }
                            fl = 1;
                            if (k1 != '\n') fl = 0;
                            com = c_push;
                            reg = fl_stack;
                            fwrite(&com, sizeof(int), 1, f);
                            fwrite(&reg, sizeof(int), 1, f);
                            fwrite(&d, sizeof(int), 1, f);
                            break;
                        }
                    }
                }
            }

            if (c == 'o')
            {
                fscanf(f0, "%c", &c);
                if (c == 'p')
                {
                    fscanf(f0, "%c", &c);
                    if (c == '\n')
                    {
                        com = c_pop;
                        reg = fl_stack;
                        fwrite(&com, sizeof(int), 1, f);
                        fwrite(&reg, sizeof(int), 1, f);
                        fl = 1;
                    }
                    if (c == ' ')
                    {
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &k1);
                        if (c >= 'a' && c <= 'z')
                        {
                            com = c_pop;
                            reg = fl_reg;
                            n = c;
                            fwrite(&com, sizeof(int), 1, f);
                            fwrite(&reg, sizeof(int), 1, f);
                            fwrite(&n, sizeof(int), 1, f);
                            fscanf(f0, "%c", &c);
                            fl = 1;
                        }
                    }
                }
            }

            if (c == 'r')
            {
                fscanf(f0, "%c", &c);
                fscanf(f0, "%c", &k1);
                fscanf(f0, "%c", &k2);
                if (c == 'i' && k1 == 'n' && k2 == 't')
                {
                    fscanf(f0, "%c", &c);
                    if (c == '\n')
                    {
                        com = c_print;
                        reg = fl_stack;
                        fwrite(&com, sizeof(int), 1, f);
                        fwrite(&reg, sizeof(int), 1, f);
                        fl = 1;
                    }
                    if (c == ' ')
                    {
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &k1);
                        if (c >= 'a' && c <= 'z' && k1 == 'x')
                        {
                            com = c_print;
                            reg = fl_reg;
                            n = c;
                            fwrite(&com, sizeof(int), 1, f);
                            fwrite(&reg, sizeof(int), 1, f);
                            fwrite(&n, sizeof(int), 1, f);
                            fscanf(f0, "%c", &c);
                            fl = 1;
                        }
                    }
                }
            }
        }

        if (c == 'a')
        {
            fscanf(f0, "%c", &c);
            fscanf(f0, "%c", &k1);
            if (c == 'd' && k1 =='d')
            {
                fscanf(f0, "%c", &c);
                if (c == '\n')
                {
                    com = c_add;
                    reg = fl_stack;
                    fwrite(&com, sizeof(int), 1, f);
                    fwrite(&reg, sizeof(int), 1, f);
                    fl = 1;
                }
                if (c == ' ')
                {
                    fscanf(f0, "%c", &c);
                    fscanf(f0, "%c", &k1);
                    if (c >= 'a' && c <= 'z' && k1 == 'x')
                    {
                        com = c_add;
                        reg = fl_reg;
                        n = c;
                        fwrite(&com, sizeof(int), 1, f);
                        fwrite(&reg, sizeof(int), 1, f);
                        fwrite(&n, sizeof(int), 1, f);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &k1);

                        if (c >= 'a' && c <= 'z' && k1 == 'x')
                        {
                            n = c;
                            fwrite(&n, sizeof(int), 1, f);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &k1);
                            if (c >= 'a' && c <= 'z' && k1 == 'x')
                            {
                                n = c;
                                fwrite(&n, sizeof(int), 1, f);
                                fl = 1;
                                fscanf(f0, "%c", &c);
                            }
                        }
                    }
                }
            }
        }

        if (c == 's')
        {
            fscanf(f0, "%c", &c);
            fscanf(f0, "%c", &k1);
            if (c == 'u' && k1 == 'b')
            {
                fscanf(f0, "%c", &c);
                if (c == '\n')
                {
                    com = c_sub;
                    reg = fl_stack;
                    fwrite(&com, sizeof(int), 1, f);
                    fwrite(&reg, sizeof(int), 1, f);
                    fl = 1;
                }
                if (c == ' ')
                {
                    fscanf(f0, "%c", &c);
                    fscanf(f0, "%c", &k1);
                    if (c >= 'a' && c <= 'z' && k1 == 'x')
                    {
                        com = c_sub;
                        reg = fl_reg;
                        n = c;
                        fwrite(&com, sizeof(int), 1, f);
                        fwrite(&reg, sizeof(int), 1, f);
                        fwrite(&n, sizeof(int), 1, f);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &k1);

                        if (c >= 'a' && c <= 'z' && k1 == 'x')
                        {
                            n = c;
                            fwrite(&n, sizeof(int), 1, f);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &k1);
                            if (c >= 'a' && c <= 'z' && k1 == 'x')
                            {
                                n = c;
                                fwrite(&n, sizeof(int), 1, f);
                                fl = 1;
                                fscanf(f0, "%c", &c);
                            }
                        }
                    }

                }
            }
        }
        if (c == 'm')
        {
            fscanf(f0, "%c", &c);
            fscanf(f0, "%c", &k1);
            if (c == 'u' && k1 == 'l')
            {
                fscanf(f0, "%c", &c);
                if (c == '\n')
                {
                    com = c_mul;
                    reg = fl_stack;
                    fwrite(&com, sizeof(int), 1, f);
                    fwrite(&reg, sizeof(int), 1, f);
                    fl = 1;
                }
                if (c == ' ')
                {
                    fscanf(f0, "%c", &c);
                    fscanf(f0, "%c", &k1);
                    if (c >= 'a' && c <= 'z' && k1 == 'x')
                    {
                        com = c_mul;
                        reg = fl_reg;
                        fwrite(&com, sizeof(int), 1, f);
                        fwrite(&reg, sizeof(int), 1, f);
                        n = c;
                        fwrite(&n, sizeof(int), 1, f);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &k1);

                        if (c >= 'a' && c <= 'z' && k1 == 'x')
                        {
                            n = c;
                            fwrite(&n, sizeof(int), 1, f);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &k1);
                            if (c >=  'a' && c <= 'z' && k1 == 'x')
                            {
                                n = c;
                                fwrite(&n, sizeof(int), 1, f);
                                fl = 1;
                                fscanf(f0, "%c", &c);
                            }
                        }
                    }
                }
            }
            if (c == 'o' && k1 == 'v')
            {
                fscanf(f0, "%c", &c);
                fscanf(f0, "%c", &c);
                if (c <= 'z' && c >= 'a')
                {
                    fscanf(f0, "%c", &k1);
                    if (k1 == 'x')
                    {
                        fscanf(f0, "%c", &k1);
                        if (fscanf(f0, "%d", &d) == 1)
                        {
                            com = c_mov;
                            reg = fl_reg;
                            n = c;
                            fwrite(&com, sizeof(int), 1, f);
                            fwrite(&reg, sizeof(int), 1, f);
                            fwrite(&n, sizeof(int), 1, f);
                            fwrite(&d, sizeof(int), 1, f);
                            fscanf(f0, "%c", &c);
                            fl = 1;
                        }
                    }
                }
            }
        }

        if (c == 'd')
        {
            fscanf(f0, "%c", &c);
            fscanf(f0, "%c", &k1);
            if (c == 'i' && k1 == 'v')
            {
                fscanf(f0, "%c", &c);
                if (c == '\n')
                {
                    com = c_div;
                    reg = fl_stack;
                    fwrite(&com, sizeof(int), 1, f);
                    fwrite(&reg, sizeof(int), 1, f);
                    fl = 1;
                }
                if (c == ' ')
                {
                    fscanf(f0, "%c", &c);
                    fscanf(f0, "%c", &k1);
                    if (c >= 'a' && c <= 'z' && k1 == 'x')
                    {
                        com = c_div;
                        reg = fl_reg;
                        n = c;
                        fwrite(&com, sizeof(int), 1, f);
                        fwrite(&reg, sizeof(int), 1, f);
                        fwrite(&n, sizeof(int), 1, f);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &k1);

                        if (c >= 'a' && c <= 'z' && k1 == 'x')
                        {
                            n = c;
                            fwrite(&n, sizeof(int), 1, f);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &k1);
                            if (c >=  'a' && c <= 'z' && k1 == 'x')
                            {
                                n = c;
                                fwrite(&n, sizeof(int), 1, f);
                                fl = 1;
                                fscanf(f0, "%c", &c);
                            }
                        }
                    }
                }
            }
        }

        /*if (com == c_push || com == c_mov_ax || com == c_mov_bx || com == c_mov_cx)
        {
            fwrite(&com, sizeof(int), 1, f);
            fwrite(&d, sizeof(int), 1, f);
            fl = 1;
        }
        else  if (com != 0)
        {
            fwrite(&com, sizeof(int), 1, f);
            fl = 1;
        }*/
        fscanf(f0, "%c", &c);
        if (c == '\n')
        {
            fl = 1;
            com = c_end;
            fwrite(&com, sizeof(int), 1, f);
            break;
        }
        if (fl == 0)
        {
            com = irreg_com;
            fwrite(&com, sizeof(int), 1, f);
            break;
        }

        com = 0;
        fl = 0;
    }

    fclose(f);
    fclose(f0);

    return 0;
}
