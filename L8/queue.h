#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100

typedef struct fila{
    int ini, end, qtd;
    int val[MAX];
} que;

que *create();
void clear(que *q);
int insert(que *q, int in);
int removeQ(que *q, int *out);
int peek(que *q, int *out);
int size(que *q);
int emptyQ(que *q);
int fullQ(que *q);
void display(que *q);

//EX_B;
que *intercalarQ(que *q1, que *q2);

#endif