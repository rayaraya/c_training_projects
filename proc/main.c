#include "commands.h"
#include "stack0.h"

int main()
{
    FILE *f = fopen("commands.bin", "rb");

    struct Stack * s;
    s = stack_create();

    int com = 0, d = 0;

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
        }
        fread(&com, sizeof(int), 1, f);
    }
    fclose(f);
    return 0;
}
