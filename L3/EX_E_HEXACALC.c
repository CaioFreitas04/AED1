#include <stdio.h>
#include <stdlib.h>

#define SQRT3 1.732                 //definindo raíz de 3;

void calculaHexagono(float l, float *area, float *perimetro);

int main(){
    //var;
    float L, a, p;

    printf("Insira o comprimento do lado de seu hexagono.\n>> ");
    while(1){
        scanf("%f", &L);
        if(L > 0) break;
        else printf("Valor invalido!\n\n");
    }

    calculaHexagono(L, &a, &p);

    printf("Area: %f u.a..\nPerimetro: %f u.c..\n\n", a, p);
    system("pause");
    return 0;
}

void calculaHexagono(float l, float *area, float *perimetro){
    
    *area = 6 * ((l * l * SQRT3) / 4);
    *perimetro = 6 * l;
}