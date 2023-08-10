#include <stdio.h>
#include <stdlib.h>

int main(){
    //var;
    int i, j, n, n1, *ip;

    printf("Insira quantos numeros seu vetor devera armazenar.\n");
    //pequena interface;
    while(1){
        printf(">> ");
        scanf("%d", &n);
        if(n > 0) break;
        else printf("Valor invalido.\n\n");
    }

    //alocando memória e preenchendo vetor;
    ip = (int*) calloc(n, sizeof(int));
    for(i = 0; i < n; i++){
        printf("ip[%d]: ", i);
        scanf("%d", &ip[i]);
    }

    //operando sobre o vetor;
    n1 = n;
    for(i = 0; i < n1; i++){
        while(ip[i] % 2){
            for(j = i; j < n1; j++){
                ip[j] = ip[j+1];
            }
            n--;
        }
    }

    //realocando memória e exibindo vetor;
    if(n <= 0) printf("\nSeu vetor so tinha valores impares!\n\n");
    else{
        ip = realloc(ip, n);
        printf("\nNumeros pares: ");
        for(i = 0; i < n; i++){
            printf("[%d] ", ip[i]);
        }
        printf("\n\n");
    }
    free(ip);
    system("pause");
    return 0;
}