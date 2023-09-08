#ifndef LISTAD_H
#define LISTAD_H

typedef struct aluno alu;
typedef struct lista list;

list *criar();
void limpar(list *l);
int inserirIni(list *l, alu input);
int inserirFim(list *l, alu input);
int inserirPos(list *l, alu input, int pos);
int removerIni(list *l);
int removerFim(list *l);
int removerPos(list *l, int pos);
int removerItem(list *l, alu input);
int buscChave(list *l, int key, alu *out);
int buscPos(list *l, int pos, alu *out);
int listVazia(list *l);
int tamanho(list *l);
void mostrar(list *l);
int contemItem(list *l, alu input);
int invertList(list *l, list *invert);
int itemCont(list *l, alu input);

#endif
