#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    que *q = create();
    int out;

    insert(q, 10);
    display(q);
    printf("\n");
    insert(q, 20);
    display(q);
    printf("\n");
    removeQ(q, &out);
    display(q);
    printf("\n");
    insert(q, 30);
    display(q);
    printf("\n");
    insert(q, 45);
    display(q);
    printf("\n");
    insert(q, 21);
    display(q);
    printf("\n");
    removeQ(q, &out);
    display(q);
    printf("\n");
    removeQ(q, &out);
    display(q);
    printf("\n");

    system("pause");
    return 0;
}