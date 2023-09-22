#include <stdio.h>
#include <stdlib.h>
#include "circlist.h"

//structs;
typedef struct aluno{
    int mat;
    char nome;
} aln;

typedef struct node{
    aln index;
    no *next;
} no;

typedef struct lista{
    no *end;    //a lista aponta para o último elemento para maior e f i c i ê n c i a;
} list;


list *create(){
    list *l = (list*) calloc(1, sizeof(list));
    l->end = NULL;
    return l;
}

int insertIni(list *l, aln input){
    if (l == NULL) return 2;
    no *n = (no*) calloc(1, sizeof(no));
    n->index = input;
    if(emptyList(l) == 0){
        l->end = n;
        n->next = n;
    }
    else{
        n->next = l->end->next;
        l->end->next = n;
    }
    return 0;
}

int insertEnd(list *l, aln input){

}

int insertPos(list *l, aln input, int pos){

}

int removeIni(list *l){

}

int removeEnd(list *l){

}

int removePos(list *l, int pos){

}

int removeItem(list *l, aln input){

}

int searchKey(list *l, int key, aln *out){

}

int searchPos(list *l, int pos, aln *out){

}

int emptyList(list *l){
    if(l == NULL) return 2;
    if(l->end == NULL) return 0;
    else return 1;
}

int sizeList(list *l){

}

void clear(list *l){

}

void displayList(list *l){

}