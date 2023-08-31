#include <stdio.h>
#include <stdlib.h>
#include "stringprot.h"

int main(){
    //var;
    string *texto;
    int L, ocorrencias_de_t;
    char teste[6] = "teste";

    texto = strcreate(6);
    addstring(texto, teste);
    L = strlength(texto);
    ocorrencias_de_t = strcharcount(texto, 't');
    strdisplay(texto);
    printf("\nComprimento: %d.\nOcorrencias da letra 't': %d.\n\n", L, ocorrencias_de_t);
    system("pause");
    return 0;
}