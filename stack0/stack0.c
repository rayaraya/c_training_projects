#include "stack0.h"

#include <stdio.h>
#include <stdlib.h>


struct Stack * stack_create()
{
    struct Stack *s = NULL;

    s = calloc(1, sizeof(struct Stack));

    s -> size = START_SIZE;
    s -> n = 0;

    s -> a = calloc (START_SIZE, sizeof(Data));

    return s;
}

void push(struct Stack * s, Data x)
{
    if (s -> size == s -> n)
    {
        s -> size = s -> size * 2;
        s -> a = realloc(s -> a, (s -> size) * sizeof(Data));
    }

    s -> a[s -> n] = x;

    s -> n ++;
}

Data pop(struct Stack * s)
{
    Data h;
    h = s -> a[(s -> n) - 1];
    s -> n--;
    return h;
}

Data get(struct Stack * s)
{
    return s -> a[(s -> n) - 1];
}

void add (struct Stack *s)
{
    push(s, pop(s) + pop(s));
}

void sub (struct Stack *s)
{
    push(s, - pop (s) + pop (s));
}


void mul (struct Stack *s)
{
    push(s, pop(s) * pop(s));
}

void _div (struct Stack *s)
{
    Data a, b;
    a = pop(s);
    b = pop(s);

    if (b == 0)
        printf("Incorrect data");
    else
        push(s, a / b);
}


int is_Empty(struct Stack * s)
{
    if (s -> n == 0) return 1;

    return 0;
}

void dump(struct Stack * s)
{
    int i;

    if (is_Empty(s))
        printf("Empty stack");
    else
        for ( i = 0; i < (s -> n); i++ )
        {
            printf("%d ", s -> a[i]);
        }
    printf("\n");
}


int stack_size (struct Stack * s)
{
    return s -> n;
}


void stack_clear (struct Stack * s)
{
     s -> n = 0;
}

void stack_destroy (struct Stack * s)
{
    free(s -> a);
    free(s);
    s = NULL;
}
