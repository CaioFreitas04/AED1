#ifndef LIST_H
#define LIST_H

typedef struct lista list;
typedef struct node no;
typedef struct aluno aln;

list *create();
int insertIni(list *l, aln input);
int insertEnd(list *l, aln input);
int insertPos(list *l, aln input, int pos);
int removeIni(list *l);
int removeEnd(list *l);
int removePos(list *l, int pos);
int removeItem(list *l, aln input);
int searchKey(list *l, int key, aln *out);
int searchPos(list *l, int pos, aln *out);
int emptyList(list *l);
int sizeList(list *l);
void clear(list *l);
void displayList(list *l);

#endif