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
                        fscanf(f0, "%d", &d);
                        com = c_push;
                        fscanf(f0, "%c", &c);
                        fl = 1;
                    }
                }

                if (c == 'o')
                {
                    fscanf(f0, "%c", &c);
                    if (c == 'p')
                    {
                        com = c_pop;
                        fscanf(f0, "%c", &c);
                        fl = 1;
                    }
                }

                if (c == 'r')
                {
                    fscanf(f0, "%c", &c);
                    fscanf(f0, "%c", &k1);
                    fscanf(f0, "%c", &k2);
                    if ( c == 'i' && k1 == 'n' && k2 == 't')
                    {
                        com = c_print;
                        fscanf(f0, "%c", &c);
                        fl = 1;
                    }
                }
        }

        if (c == 'a')
        {
            fscanf(f0, "%c", &c);
            fscanf(f0, "%c", &k1);
            if (c == 'd' && k1 =='d')
            {
                com = c_add;
                fscanf(f0, "%c", &c);
                fl = 1;
            }
        }

        if (c == 's')
        {
            fscanf(f0, "%c", &c);
            fscanf(f0, "%c", &k1);
            if (c == 'u' && k1 == 'b')
            {
                com = c_sub;
                fscanf(f0, "%c", &c);
                fl = 1;
            }
        }

        if (c == 'm')
        {
            fscanf(f0, "%c", &c);
            fscanf(f0, "%c", &k1);
            if (c == 'u' && k1 == 'l')
            {
                com = c_mul;
                fscanf(f0, "%c", &c);
                fl = 1;
            }
        }

        if (c == 'd')
        {
            fscanf(f0, "%c", &c);
            fscanf(f0, "%c", &k1);
            if (c == 'i' && k1 == 'v')
            {
                com = c_div;
                fscanf(f0, "%c", &c);
                fl = 1;
            }
        }

        if (com == c_push)
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
