#include <stdio.h>
#include <stdlib.h>
#include "ListaD.h"

typedef struct aluno{
    int mat;
    char nome[30];
    float not;
} alu;

typedef struct lista{
    int total;
    alu *index;
} list;

list *criar(){
    list *l  = (list*) calloc(1, sizeof(list));
    if(l != NULL){
        l->total = 0;
        if(l->index = (alu*) calloc(0, sizeof(alu)) == NULL){
            free(l);
            l = NULL;
        }
    }
    return l;
}

void limpar(list *l){
    if(l != NULL){
        l->total = 0;
        free(l->index);
    }
}

int inserirIni(list *l, alu input){
    int i;
    list *dummy;
    if(l == NULL) return 2;

    if(dummy = criar() == NULL) return 2;
    else{
        dummy->index = (alu*) realloc(l, l->total+1);
        if(dummy == NULL) return 3;
        else l = dummy;
    }

    for(i = l->total; i > 0; i--){
        l->index[i] = l->index[i-1];
    }
    l->index[0] = input;
    l->total++;
    return 0;
}

int inserirFim(list *l, alu input){
    list *dummy;
    if(l == NULL) return 2;

    if(dummy = criar() == NULL) return 2;
    else{
        dummy->index = (alu*) realloc(l, l->total+1);
        if(dummy == NULL) return 3;
        else l = dummy;
    }
    l->index[l->total] = input;
    l->total++;
    return 0;
}

int inserirPos(list *l, alu input, int pos){
    int i;
    list *dummy;
    if(l == NULL) return 2;

    if(dummy = criar() == NULL) return 2;
    else{
        dummy->index = (alu*) realloc(l, l->total+1);
        if(dummy == NULL) return 3;
        else l = dummy;
    }

    for(i = l->total; i > pos; i--){
        l->index[i] = l->index[i-1];
    }
    l->index[pos] = input;
    l->total++;
    return 0;
}

int removerIni(list *l){
    int i;
    list *dummy;
    if (l == NULL) return 2;
    if (listVazia(l) == 0) return 1;
    for (i = 0; i < l->total-1; i++){
        l->index[i] = l->index[i+1];
    }

    if(dummy = criar() == NULL) return 2;
    else{
        dummy->index = (alu*) realloc(l, l->total-1);
        if(dummy == NULL) return 3;
        else l = dummy;
    }
    l->total--;
    return 0;
}

int removerFim(list *l){
    list *dummy;
    if (l == NULL) return 2;
    if (listVazia(l) == 0) return 1;

    if(dummy = criar() == NULL) return 2;
    else{
        dummy->index = (alu*) realloc(l, l->total-1);
        if(dummy == NULL) return 3;
        else l = dummy;
    }
    l->total--;
    return 0;
}

int removerPos(list *l, int pos){
    list *dummy;
    int i;
    if (l == NULL) return 2;
    if (listVazia(l) == 0) return 1;
    for(i = l->total; i > pos; i--){
        l->index[i] = l->index[i-1];
    }

    if(dummy = criar() == NULL) return 2;
    else{
        dummy->index = (alu*) realloc(l, l->total-1);
        if(dummy == NULL) return 3;
        else l = dummy;
    }
    l->total--;
    return 0;
}

int removerItem(list *l, alu input){
    int i;
    for(i = 0; i < l->total; i++){
        if(l->index[i].mat == input.mat){
            removerPos(l, i);
            break;
        }
    }
    return -1;
}

int buscChave(list *l, int key, alu *out){
    int i;
    if(l == NULL) return 2;
    if(listVazia(l) == 0) return 1;
    for(i = 0; i < l->total; i++){
        if(l->index[i].mat == key){
            *out = l->index[i];
            return 0;
        }
    }
    return -1;
}

int buscPos(list *l, int pos, alu *out){
    if(l == NULL) return 2;
    if(listVazia(l) == 0) return 1;
    if(l->total < pos && pos < 0) return -1;
    else{
        *out = l->index[pos];
        return 0;
    }
}

int listVazia(list *l){
    if(l == NULL) return 2;
    if(l->total == 0) return 0;
    else return 1;
}

int tamanho(list *l){
    if(l == NULL) return -1;
    else return l->total;
}

void mostrar(list *l){
    int i;
    if(l != NULL){
        for(i = 0; i < l->total; i++){
            printf("{%s, %d, %.2f}\n", l->index[i].nome, l->index[i].mat, l->index[i].not);
        }
    }
}

int invertList(list *l, list *invert){
    int i;
    if(l == NULL && invert == NULL) return 2;
    if(listVazia(l) == 0) return 1;
    limpar(invert);
    if(invert != NULL){
        for(i = 0; i < (l->total); i++){
            inserirIni(invert, l->index[i]);
        }
    }
    return 0;
}

int itemCont(list *l, alu input){
    int i, count = 0;
    if(l == NULL) return -2;
    if(listVazia(l) == 0) return -1;
    for(i = 0; i < l->total; i++){
        if(l->index[i].mat = input.mat){
            count++;
        }
    }
    return count;
}