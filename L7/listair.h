#ifndef LIST_H
#define LIST_H

typedef struct lista list;
typedef struct node no;
typedef struct aeroporto aer;

list *create(char *sigla);
int insertIni(list *l, aer input);
int insertEnd(list *l, aer input);
int insertPos(list *l, aer input, int pos);
int removeIni(list *l);
int removeEnd(list *l);
int removePos(list *l, int pos);
int removeItem(list *l, aer input);
int searchKey(list *l, char *key, aer *out);
int emptyList(list *l);
int sizeList(list *l);
void clear(list *l);
void displayList(list *l);
int contItem(list *l, aer input);
int displayCaraBarata(list *l);
int showPrice(list *l, char *destin);


#endif