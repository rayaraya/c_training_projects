#include "stack0.h"

int main()
{
    struct Stack * prob = stack_create();
    Data a;
    push (prob, 2);
    push (prob, 3);
    push (prob, -10);
    push (prob, 6);
    dump (prob);
    add (prob);
    dump (prob);
    mul (prob);
    dump (prob);
    _div (prob);
    dump (prob);
    a = pop (prob);
    dump (prob);

    printf("last value = %d", a);
    return 0;
}
