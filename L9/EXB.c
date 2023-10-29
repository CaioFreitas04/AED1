#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int samestacks(stack *s1, stack *s2){
    if(s1 == NULL || s2 == NULL) return 2;
    if(stacksize(s1) != stacksize(s2)) return 1;

    int s1out, s2out;
    pop(s1, &s1out);
    pop(s2, &s2out);

    if(s1out == s2out){
        if(emptystack(s1) == 0) return 0;

        else return samestacks(s1, s2);
    }
    else return 1;    
}

void seestack(stack *s){
    if(s != NULL){
        no *nlist = s->top;

        while(nlist != NULL){
            printf("%d ", nlist->index);
            nlist = nlist->next;
        }
    }
}

int main(){
    stack *s1 = create(), *s2 = create();

    for(int i = 0; i < 10; i++){
        push(s1, i);
        push(s2, i);
    }

    seestack(s1);
    printf("\n");
    seestack(s2);
    printf("\n");

    if(samestacks(s1, s2) == 0){
        printf("As pilhas sao iguais!\n");
    }
    else{
        printf("As pilhas sao diferentes!\n");
    }

    for(int i = 10; i < 19; i++){
        push(s1, i);
        push(s2, i);
    }
    push(s1, 1337);
    push(s2, -1337);

    printf("\n");
    seestack(s1);
    printf("\n");
    seestack(s2);
    printf("\n");

    if(samestacks(s1, s2) == 0){
        printf("As pilhas sao iguais!\n");
    }
    else{
        printf("As pilhas sao diferentes!\n");
    }

    system("pause");
    return 0;
}