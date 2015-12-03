#include "commands.h"

int main()
{
    FILE * f0 = fopen ("commands.txt", "r");
    FILE * f = fopen ("commands.bin", "wb");

    char c, k1, k2;

    int com = 0, d = 0, fl = 0;

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
                        switch (k1)
                        {
                            case 'a':
                                fscanf(f0, "%c", &c);
                                if (c == 'x')
                                {
                                    com = c_push_ax;
                                    fscanf(f0, "%c", &c);
                                    fl = 1;
                                }
                                break;
                            case '1': case '2': case '3': case '4': case '5':
                            case '6': case '7': case '8': case '9': case '0':
                                d = k1 - '0';
                                fscanf(f0, "%c", &k1);
                                while (k1 != '\n')
                                {
                                    d = d * 10 + (k1 - '0');
                                    fscanf(f0, "%c", &k1);
                                }
                                com = c_push;
                                fl = 1;
                                break;
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
                            fl = 1;
                        }
                        if (c == ' ')
                        {
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &k1);
                            if (c == 'a' && k1 == 'x')
                            {
                                com = c_pop_ax;
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
                    if ( c == 'i' && k1 == 'n' && k2 == 't')
                    {
                        fscanf(f0, "%c", &c);
                        if (c == '\n')
                        {
                            com = c_print;
                            fl = 1;
                        }
                        if (c == ' ')
                        {
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &k1);
                            if (c == 'a' && k1 == 'x')
                            {
                                com = c_print_ax;
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
                    fl = 1;
                }
                if (c == ' ')
                {
                    fscanf(f0, "%c", &c);
                    fscanf(f0, "%c", &k1);
                    if (c == 'a' && k1 == 'x')
                    {
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &k1);
                        if (c == 'b' && k1 == 'x')
                        {
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &k1);
                            if (c == 'c' && k1 == 'x')
                            {
                                com = c_add_ax_bx_cx;
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
                    fl = 1;
                }
                if (c == ' ')
                {
                    fscanf(f0, "%c", &c);
                    fscanf(f0, "%c", &k1);
                    if (c == 'a' && k1 == 'x')
                    {
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &k1);
                        if (c == 'b' && k1 == 'x')
                        {
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &k1);
                            if (c == 'c' && k1 == 'x')
                            {
                                com = c_sub_ax_bx_cx;
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
                    fl = 1;
                }
                if (c == ' ')
                {
                    fscanf(f0, "%c", &c);
                    fscanf(f0, "%c", &k1);
                    if (c == 'a' && k1 == 'x')
                    {
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &k1);
                        if (c == 'b' && k1 == 'x')
                        {
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &k1);
                            if (c == 'c' && k1 == 'x')
                            {
                                com = c_mul_ax_bx_cx;
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
                switch (c)
                {
                case 'a':
                    fscanf(f0, "%c", &c);
                    if (c == 'x')
                    {
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%d", &d);
                        com = c_mov_ax;
                        fscanf(f0, "%c", &c);
                        fl = 1;
                    }
                    break;
                 case 'b':
                    fscanf(f0, "%c", &c);
                    if (c == 'x')
                    {
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%d", &d);
                        com = c_mov_bx;
                        fscanf(f0, "%c", &c);
                        fl = 1;
                    }
                    break;
                 case 'c':
                    fscanf(f0, "%c", &c);
                    if (c == 'x')
                    {
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%d", &d);
                        com = c_mov_cx;
                        fscanf(f0, "%c", &c);
                        fl = 1;
                    }
                    break;
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
                    fl = 1;
                }
                if (c == ' ')
                {
                    fscanf(f0, "%c", &c);
                    fscanf(f0, "%c", &k1);
                    if (c == 'a' && k1 == 'x')
                    {
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &c);
                        fscanf(f0, "%c", &k1);
                        if (c == 'b' && k1 == 'x')
                        {
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &c);
                            fscanf(f0, "%c", &k1);
                            if (c == 'c' && k1 == 'x')
                            {
                                com = c_div_ax_bx_cx;
                                fl = 1;
                                fscanf(f0, "%c", &c);
                            }
                        }
                    }
                }

            }
        }

        if (com == c_push || com == c_mov_ax || com == c_mov_bx || com == c_mov_cx)
        {
            fwrite(&com, sizeof(int), 1, f);
            fwrite(&d, sizeof(int), 1, f);
            fl = 1;
        }
        else  if (com != 0)
        {
            fwrite(&com, sizeof(int), 1, f);
            fl = 1;
        }
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
