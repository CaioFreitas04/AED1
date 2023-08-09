#include <stdio.h>
#include <stdlib.h>

int main(){
    //var;
    int i, *ip;

    ip = (int*) calloc(5, sizeof(int));
    if(ip == NULL){
        printf("FALHA AO ALOCAR MEMORIA.\n\n");
        system("pause");
        exit(1);
    }

    printf("Insira numeros inteiros no vetor.\n");
    for(i = 0; i < 5; i++){
        printf("ip[%d]: >> ", i);
        scanf("%d", ip+i);
    }

    printf("\n\n");
    for(i = 0; i < 5; i++){
        printf("[%d] ", *(ip+i));
    }

    printf("\n\n");
    free(ip);
    system("pause");
    return 0;
}