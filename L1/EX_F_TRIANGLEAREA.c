#include <stdio.h>
#include <stdlib.h>

int main(){
    //var. b, h, A são a base, altura, e área do triângulo;
    double b, h, A;
    printf("Insira a base e a altura de um triangulo.\n>> ");
    while(1){
        scanf("%lf%lf", &b, &h);
        if(b > 0 && h > 0) break;
        printf("Valor(es) invalido(s)!\n\n");
    }

    A = b * h / 2;
    printf("\n\nEsse triangulo tem area: %lf u.a.\n\n", A);

    system("pause");
    return 0;
}