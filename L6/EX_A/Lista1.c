#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct aluno{
    int mat;
    char nome[30];
    float not;
} alu;

typedef struct lista{
    int total;
    alu index[MAX];
} list;

list *criar(){
    list *l  = (list*) calloc(1, sizeof(list));
    if(l != NULL) l->total = 0;
    return l;
}

void limpar(list *l){
    if(l != NULL) l->total = 0;
}

int inserirIni(list *l, alu input){
    int i;
    if(l == NULL) return 2;
    if(listCheia == 0) return 1;
    for(i = l->total; i > 0; i--){
        l->index[i] = l->index[i-1];
    }
    l->index[0] = input;
    l->total++;
    return 0;
}

int inserirFim(list *l, alu input){
    if(l == NULL) return 2;
    if(listCheia == 0) return 1;
    l->index[l->total] = input;
    l->total++;
    return 0;
}

int inserirPos(list *l, alu input, int pos){
    int i;
    if(l == NULL) return 2;
    if(listCheia == 0) return 1;
    for(i = pos; i <= l->total; i++){
        l->index[i] = l->index[i-1];
    }
    l->index[pos] = input;
    l->total++;
    return 0;
}

int removerIni(list *l){
    int i;
    if (l == NULL) return 2;
    if (listVazia(l) == 0) return 1;
    for (i=0;i<l->total-1;i++){
        l->index[i] = l->index[i+1];
    }
    l->total--;
    return 0;
}

int removerFim(list *l){
    if (l == NULL) return 2;
    if (listVazia(l) == 0) return 1;
    l->total--;
    return 0;
}

int removerPosi(list *l, int pos){
    int i;
    if (l == NULL) return 2;
    if (listVazia(l) == 0) return 1;
    for (i = pos; i < l->total-1; i++){
        l->index[i] = l->index[i+1];
    }
    l->total--;
    return 0;
}

int removerItem(list *l, alu input){
    int pos, i, j;
    if (l == NULL) return 2;
    if (listVazia(l) == 0) return 1;
    for(i = 0; i < l->total-1; i++){
        if(l->index[i].mat == input.mat){
            for (j = i; i < l->total-1; i++){
                l->index[j] = l->index[j+1];
            }
            return 0;
        }
    }
    return -1;
}

int buscChave(list *l, int key, alu *out){
    int i;
    if(l == NULL) return 2;
    if(listVazia == 0) return 1;
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
    if(listVazia == 0) return 1;
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

int listCheia(list *l){
    if (l == NULL) return 2;
    if (l->total == MAX) return 0;
    else return 1;
}

int tamanho(list *l){

}

void mostrar(list *l){
    int i;
    if(l != NULL){
        for(i = 0; i < l->total; i++){
            printf("{%s, %d, %.2f}\n", l->index[i].nome, l->index[i].mat, l->index[i].not);
        }
    }
}