#include <stdio.h>
#include <stdlib.h>

int eucDiv(int a, int b, int *q, int *r);       //função que realiza divisão euclidiana;

int main(){
    //var;
    int a, b, q, r;

    printf("Insira os valores a e b, para o calculo de a/b.\n>> ");
    scanf("%d%d", &a, &b);
    
    if(eucDiv(a, b, &q, &r) == -1){
        printf("Impossivel realizar operacao.\n\n");
    }
    else{
        printf("Quociente: %d.\nResto: %d.\n\n", q, r);
    }

    system("pause");
    return 0;
}


int eucDiv(int a, int b, int *q, int *r){
    if(b == 0) return -1;
    else{
        *q = a / b;
        *r = a % b;
        return 0;
    }
}