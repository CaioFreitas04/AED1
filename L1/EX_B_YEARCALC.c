#include <stdio.h>
#include <stdlib.h>

int main(){
    //var. nasc é o ano de nascimento e curryr é o ano atual;
    int nasc, curryr;

    printf("Insira o ano de seu nascimento.\n>> ");
    scanf("%d", &nasc);
    printf("Insira o ano atual.\n>> ");
    scanf("%d", &curryr);

    printf("\nSua idade hoje eh %d, e sua idade em 2030 sera %d.\n\n", curryr-nasc, 2030-nasc);

    system("pause");
    return 0;
}