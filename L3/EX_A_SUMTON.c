#include <stdio.h>
#include <stdlib.h>


void sumuptoN(int *N);          //retorna a soma de todos os números de 1 a N;


int main(){
    //var;
    unsigned int N;

    printf("Insira seu valor N.\n>> ");
    scanf("%u", &N);
    sumuptoN(&N);

    printf("\n\nSoma de todos os numeros de 1 a N: %u.\n\n", N);

    system("pause");
    return 0;
}


void sumuptoN(int *N){
    int n = *N - 1;

    if(n == 0) return;
    else{
        sumuptoN(&n);
        *N += n;
        return;
    }
}