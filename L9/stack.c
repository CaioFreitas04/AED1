#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack *create() {
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = NULL;
    return s;
}

void clear(stack *s) {
    int *d;
    while(emptystack(s) !=0){
        pop(s, d);
    }
    free(s);
    s = NULL;
}

int peek(stack *s, int *it){
    if(s == NULL) return 2;
    if(emptystack(s) == 0) return 1;
    no *temp = s->top;
    *it = temp->index;
    return 0;
}

int stacksize(stack *s) {
    if(s == NULL) return -2;
    int ct = 0;
    no *no = s->top;
    while (no != NULL) {
        ct++;
        no = no->next;
    }
    return ct;
}

int emptystack(stack *s){
    if(s == NULL) return 2;
    if(s->top == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

int fullstack(stack *s) {
    return 1;
}

int push(stack *s, int in){
    if(s == NULL) return 2;
    no *n = (no*) malloc(sizeof(no));
    n->index = in;
    n->next = s->top;
    s->top = n;
    return 0;
}

int pop(stack *s, int *out){
    if(s == NULL) return 2;
    if(emptystack(s) == 0)return 1;
    no *temp = s->top;
    *out = temp->index;
    s->top = temp->next;
    free(temp);
    return 0;
}
