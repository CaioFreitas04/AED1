#ifndef STACK_H
#define STACK_H

typedef struct node{
    int index;
    struct node *next;
} no;

typedef struct pilha {
    no *top;
} stack;


stack *create();
void clear(stack *s);
int peek(stack *s, int *it);
int stacksize(stack *s);
int emptystack(stack *s);
int fullstack(stack *s);
int push(stack *s, int in);
int pop (stack *s, int *out);

#endif
