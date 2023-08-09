#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //var;
    char carlafaria[12] = "Carla Faria";
    double dbl[10];
    int i;

    srand(time(NULL));

    for(i = 0; i < 12; i++){
        printf("%c", *(carlafaria+i));
    }
    printf("\n\n");

    for(i = 0; i < 10; i++){
        *(dbl+i) = (rand() % 10) * 3.1415 - ((rand() % 3) * 0.365); //preenchendo com valores aleatórios;
        printf(" %lf ", *(dbl+i));
    }

    printf("\n\n");
    system("pause");
    return 0;
}