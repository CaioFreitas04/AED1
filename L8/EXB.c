#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    que *q1 = create(), *q2 = create();
    int i;

    for(i = 0; i < 10; i++){
        if(i % 2 == 0){
            insert(q1, i);
        }
        else{
            insert(q2, i);
        }
    }
    display(q1);
    printf("\n");
    display(q2);

    printf("\n\n");
    que *q = intercalarQ(q1, q2);
    display(q);

    system("pause");
    return 0;
}