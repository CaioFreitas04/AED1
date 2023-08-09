#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //var;
    int i, j, **m1i, **m2i, **m3i;


    srand(time(NULL));


    //alocando as três matrizes;
    m1i = (int**) calloc(3, sizeof(int*));
    for(i = 0; i < 3; i++){
        m1i[i] = (int*) calloc(3, sizeof(int));
    }
    if(m1i == NULL){
        printf("FALHA AO ALOCAR MEMORIA PARA MATRIZ.\n\n");
        system("pause");
        exit(1);
    }

    m2i = (int**) calloc(3, sizeof(int*));
    for(i = 0; i < 3; i++){
        m2i[i] = (int*) calloc(3, sizeof(int));
    }
    if(m2i == NULL){
        printf("FALHA AO ALOCAR MEMORIA PARA MATRIZ.\n\n");
        system("pause");
        exit(2);
    }

    m3i = (int**) calloc(3, sizeof(int*));
    for(i = 0; i < 3; i++){
        m3i[i] = (int*) calloc(3, sizeof(int));
    }
    if(m3i == NULL){
        printf("FALHA AO ALOCAR MEMORIA PARA MATRIZ.\n\n");
        system("pause");
        exit(3);
    }

    //aritmética;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            m1i[i][j] = (rand() % 4) + 1;
            m2i[i][j] = (rand() % 5) + 1;
            m3i[i][j] = m1i[i][j] + m2i[i][j];
        }
    }

    //impressão;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("[%d] ", m1i[i][j]);
        }
        if(i == 1) printf(" +  ");
        else printf("    ");
        for(j = 0; j < 3; j++){
            printf("[%d] ", m2i[i][j]);
        }
        if(i == 1) printf(" =  ");
        else printf("    ");
        for(j = 0; j < 3; j++){
            printf("[%d] ", m3i[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    system("pause");
    return 0;
}