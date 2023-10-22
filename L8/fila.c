#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

que *create(){
    que *q = (que*) malloc(sizeof(que));

    q->ini = 0;
    q->end = 0;
    q->qtd = 0;

    return q;
}

void clear(que *q){
    if(q != NULL){
        int *dummy = (int*) malloc(sizeof(int));
        while(emptyQ(q) != 0){
            removeQ(q, dummy);
        }
    }
}

int insert(que *q, int in){
    if (q == NULL) return 2;
    if(fullQ(q) == 0) return 1;

    q->val[q->end] = in;
    q->end = (q->end + 1) % MAX;
    q->qtd++;

    return 0;
}

int removeQ(que *q, int *out){
    if(q == NULL) return 2;
    if(emptyQ(q) == 0) return 1;

    *out = q->val[q->ini];
    q->qtd--;
    q->ini = (q->ini+1) % MAX;

    return 0;
}

int peek(que *q, int *out){
    if(q == NULL) return 2;
    if(emptyQ(q) == 0) return 1;

    *out = q->val[q->ini];

    return 0;
}

int size(que *q){
    if(q == NULL) return 2;
    else return q->qtd;
}

int emptyQ(que *q){
    if(q == NULL) return 2;
    if(q->qtd == 0) return 0;
    else return 1;
}

int fullQ(que *q){
    if(q == NULL) return 2;
    if(q->qtd == MAX) return 0;
    else return 1;
}

void display(que *q){
    if(q != NULL){
        printf("[\n");

        int i = q->ini;
        int j = q->qtd;

        while(j > 0){
            printf("%d\n", q->val[i]);
            i = (i+1) % MAX;
            j--;
        }

        printf("]\n");
    }
}

que *intercalarQ(que *q1, que *q2){
    if(q1 == NULL || q2 == NULL) return NULL;
    if(emptyQ(q1) == 0 && emptyQ(q2) == 0) return NULL;

    que *qout = create();
    int *dummy = (int*) malloc(sizeof(int));


    while(emptyQ(q1) != 0 && emptyQ(q2) != 0){
        if(removeQ(q1, dummy) == 0){
            insert(qout, *dummy);
        }
        if(removeQ(q2, dummy) == 0){
            insert(qout, *dummy);
        }
    }

    return qout;
}