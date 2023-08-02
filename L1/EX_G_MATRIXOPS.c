#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //var. mat é a matriz, linesum a soma das linhas;
    int mat[5][10], linesum[5] = {0, 0, 0, 0, 0}, i, j;

    srand(time(NULL));
    printf("Preenchendo matriz com valores aleatorios...\n\n\n");
    for(i = 0; i < 5; i++){
        printf("\t");
        for(j = 0; j < 10; j++){
            mat[i][j] = (rand() % 9) + 1;  //valores de 1-9;
            printf("%d ", mat[i][j]);
            linesum[i] += mat[i][j];
        }
        printf("\n");
    }
    printf("\nMatriz preenchida!\n");
    printf("\n\n");
    system("pause");

    printf("Operando sobre matriz...\n\n\n");
    for(i = 0; i < 5; i++){
        printf("\t");
        for(j = 0; j < 10; j++){
            mat[i][j] *= linesum[i];
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    system("pause");
    return 0;
}