#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listair.h"


//structs;
typedef struct lista{
    char sigla[5];   //essa string foi armazenada para que a lista codifique qual o aeroporto-origem;
    no *ini;
} list;

typedef struct aeroporto{
    char nome[30], sigla[5];
    float prec;
} aer;

typedef struct node{
    aer index;
    no *next;
} no;

//funções;
list *create(char *sigla){
    list *l = (list*) calloc(1, sizeof(list));
    l->ini = NULL;
    strcpy(l->sigla, sigla);
    return l;
}

int insertIni(list *l, aer input){
    no *n1 = (no*) calloc(1, sizeof(no));

    if(l == NULL) return 2;
    n1->index = input;
    n1->next = l->ini;
    l->ini = n1;
    return 0;
}

int insertEnd(list *l, aer input){
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

int insertPos(list *l, aer input, int pos){
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

int removeItem(list *l, aer input){
    no *nlist = l->ini;
    int i = 0;

    if(l == NULL) return 2;
    if(emptyList(l) == 0) return 1;
    while((nlist->next != NULL)){
        if(strcmp(nlist->index.sigla, input.sigla) == 0){
            return removePos(l, i);
        }
        nlist = nlist->next;
        i++;
    }
    return -1;
}

int searchKey(list *l, char *key, aer *out){
    no *nlist = l->ini;

    if(l == NULL) return 2;
    while(nlist != NULL){
        if(strcmp(nlist->index.sigla, key) == 0){
            *out = nlist->index;
            return 0;
        }
        printf("%d\n", strcmp(nlist->index.sigla, key));
        nlist = nlist->next;
    }

    return 1;
}

int emptyList(list *l){
    if(l == NULL) return 2;
    if(l->ini == NULL) return 0;
    else return 1;
}

int sizeList(list *l){
    int i = 0;
    no *nlist = l->ini;
    if(l == NULL) return -2;
    if(emptyList(l) == 0) return 0; 
    while(nlist->next != NULL){
        nlist = nlist->next;
        i++;
    }
    return i;
}

void clear(list *l){
    while(emptyList(l) != 0) removeIni(l);
}

//como cada lista representará uma cidade, essa função servirá para mostrar todas as rotas da cidade da lista até as cidades com as quais está conectada;
void displayList(list *l){
    no *nlist = l->ini;

    if(l != NULL){
        while(nlist != NULL){
            printf("[%s - %s: %.2f]\n", nlist->index.nome, nlist->index.sigla, nlist->index.prec);
            nlist = nlist->next;
        }
    }
}

int contItem(list *l, aer input){
    aer dummy;
    return searchKey(l, input.sigla, &dummy);
}

int displayCaraBarata(list *l){
    no *nlist = l->ini;
    aer mcar, mbar;
    if(l == NULL) return 2;
    if(emptyList(l) == 0) return 1;
    mcar = nlist->index;
    mbar = mcar;
    while(nlist != NULL){
        nlist = nlist->next;
        if(mcar.prec < nlist->index.prec) mcar = nlist->index;
        if(mbar.prec > nlist->index.prec) mbar = nlist->index;
    }
    printf("ROTA MAIS CARA: [%s -> %s, %.2f]\n", l->sigla, mcar.sigla, mcar.prec);
    printf("ROTA MAIS BARATA: [%s -> %s, %.2f]\n", l->sigla, mbar.sigla, mbar.prec);
    return 0;
}

int showPrice(list *l, char *destin){
    aer out;
    if(l == NULL) return 2;
    if(emptyList(l) == 0) return 1;
    if(searchKey(l, destin, &out) != 0){
        return -1;
    }
    printf("[%s -> %s, %.2f]\n", l->sigla, out.sigla, out.prec);
    return 0;
}