#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
    stack *s = create();
    int out;

    push(s, 11);
    push(s, 34);
    pop(s, &out);
    pop(s, &out);
    push(s, 23);
    push(s, 45);
    pop(s, &out);
    push(s, 121);
    push(s, 22);
    pop(s, &out);
    pop(s, &out);

    seestack(s);
    printf("\n\n");
    system("pause");
    return 0;

}