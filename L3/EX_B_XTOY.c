#include <stdio.h>
#include <stdlib.h>


double xey(double x, int y);         //função expoente;


int main(){
    //var;
    int y;
    double x, res;

    printf("Insira a base e o expoente.\n>> ");
    scanf("%lf%d", &x, &y);
    res = xey(x, y);
    printf("Resultado: %lf\n\n", res);

    system("pause");
    return 0;
}


double xey(double x, int y){

    int i;
    double res = 1;

    if(y == 0) return 1;
    else{
        for(i = 0; i < y; i++){
            res *= x;
        }
    }

    return res;
}