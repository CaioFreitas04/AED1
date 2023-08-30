#ifndef STRINGPROT_H
#define STRINGPROT_H

typedef struct string string;

string *strcreate(unsigned L);
void addstring(string *str, char *text);
int strlength(string *str);
int strcharcount(string *str, char c);
void strdisplay(string *str);

#endif