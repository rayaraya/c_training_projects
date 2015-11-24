#ifndef stack
#define stack
#define START_SIZE 20
typedef int Data;

struct Stack {
    int n;
    int size;
    Data * a;
};

struct Stack * stack_create();

void push(struct Stack * s, Data x);

Data pop(struct Stack * s);

Data get(struct Stack * s);

void add (struct Stack *s);

void sub (struct Stack *s);

void mul (struct Stack *s);

void _div (struct Stack *s);

int is_Empty(struct Stack * s);

void dump(struct Stack * s);

int stack_size (struct Stack * s);

void stack_clear (struct Stack * s);

void stack_destroy (struct Stack * s);

#endif
