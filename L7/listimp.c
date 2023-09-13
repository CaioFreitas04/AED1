#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//structs;
typedef struct lista{
    no *ini;
} list;

typedef struct node{
    aln index;
    no *next;
} no;

typedef struct aluno{
    int mat;
    char nome[30];
    float not;
} aln;

//funções;
list *create(){
    list *l = (list*) calloc(1, sizeof(list));
    l->ini = NULL;
    return l;
}

int insertIni(list *l, aln input){
    no *n1 = (no*) calloc(1, sizeof(no));

    if(l == NULL) return 2;
    n1->index = input;
    n1->next = l->ini;
    l->ini = n1;
    return 0;
}

int insertEnd(list *l, aln input){
    no *nlist = (no*) calloc(1, sizeof(no));
    no *n = (no*) calloc(1, sizeof(no));

    if(l == NULL) return 2;
    if(emptyList(l) == 0) return insertIni(l, input);
    while(nlist->next != NULL){
        nlist = nlist->next;
    }
    n->index = input;
    n->next = nlist->next;
    nlist->next = n;
    return 0;
}

int insertPos(list *l, aln input, int pos){
    int i = 0;
    no *nlist = l->ini;
    no *n = (no*) calloc(1, sizeof(no));

    if(l == NULL) return 2;
    if (pos <= 0 || (emptyList(l) == 0)) return insertIni(l, input);
    while((nlist->next != NULL) && (i != pos)){
        i++;
        nlist = nlist->next;
    }
    n->index = input;
    n->next = nlist->next;
    nlist->next = n;
    return 0;
}

int removeIni(list *l){
    no *nlist = l->ini;

    if(l == NULL) return 2;
    if(emptyList(l) == 0) return 1;
    l->ini = nlist->next;
    free(nlist);
    return 0;
}

int removeEnd(list *l){
    no *nlist = l->ini, *naux = NULL;

    if(l == NULL) return 2;
    if(emptyList(l) == 0) return 1;
    while(nlist->next != NULL){
        naux = nlist;
        nlist = nlist->next;
    }
    if(naux == NULL) l->ini = NULL;
    else naux->next = NULL;
    free(nlist);
    return 0;
}

int removePos(list *l, int pos){
    no *nlist = l->ini, *naux = NULL;
    int i = 0;

    if(l == NULL) return 2;
    if(emptyList(l) == 0) return 1;
    if(pos <= 0) return removeIni(l);
    while((nlist->next != NULL) && (i != pos)){
        naux = nlist;
        nlist = nlist->next;
    }
    if(naux == NULL) return removeIni(l);
    else naux->next = nlist->next;
    free(nlist);
    return 0;
}

int removeItem(list *l, aln input){
    no *nlist = l->ini;
    int i = 0;

    if(l == NULL) return 2;
    if(emptyList(l) == 0) return 1;
    while((nlist->next != NULL)){
        if(nlist->index.mat == input.mat){
            return removePos(l, i);
        }
        nlist = nlist->next;
        i++;
    }
    return -1;
}

int searchKey(list *l, int key, aln *out){
    no *nlist = l->ini;

    if(l == NULL) return 2;
    while(nlist != NULL){
        if(nlist->index.mat == key){
            *out = nlist->index;
            return 0;
        }
        nlist = nlist->next;
    }

    return 1;
}

int searchPos(list *l, int pos, aln *out){

}

int emptyList(list *l){
    if(l == NULL) return 2;
    if(l->ini == NULL) return 0;
    else return 1;
}

int sizeList(list *l){

}

void clear(list *l){
    while(emptyList(l) != 0) removeIni(l);
}

void displayList(list *l){
    no *nlist = l->ini;

    if(l != NULL){
        while(nlist != NULL){
            printf("[%d, %s, %.2f]\n", nlist->index.mat, nlist->index.nome, nlist->index.not);
            nlist = nlist->next;
        }
    }
}