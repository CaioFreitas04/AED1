#include <stdio.h>
#include <stdlib.h>

int main(){
    //var. input é o valor atual, men10 é a contagem dos valores menores do que 10, e sum a soma dos maiores do que 10;
    int input, men10 = 0, sum = 0;

    printf("Insira numeros inteiros em sequencia: valores menores que 10 serao contados, e maiores do que 10 serao somados. Encerre com 10.\n\n");
    while(1){
        scanf("%d", &input);
        if(input < 10) men10++;
        else if(input > 10) sum += input;
        else break;
    }

    printf("\n\nNumeros menores do que dez: %d\n", men10);
    printf("Soma dos numeros maiores do que dez: %d\n\n", sum);

    system("pause");
    return 0;
}