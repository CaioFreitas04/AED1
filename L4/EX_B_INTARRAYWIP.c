#include <stdio.h>
#include <stdlib.h>

int main(){
    //var;
    int **arr, i = 0, j, k, l, input, currsize = 0;

    //alocando o vetor **arr;
    arr = (int**) calloc(1, sizeof(int*));

    printf("Preencha seu primeiro vetor (-1 encerra o preenchimento).\n\n");

    while(1){
        j = 1;
        while(1){
            printf(">> ");
            scanf("%d", &input);
            if(input == -1){
                break;
            }
            else{
                arr[i] = (int*) realloc(arr[i], j);
                arr[i][j-1] = input;
                j++;
            }
        }
        //imprimindo o vetor antes;
        for(k = 0; k < j; k++){
            printf("%d ", arr[i][k]);
        }

        for(k = 0; k < j; k++){
            while(arr[i][k] == arr[i][k+1]){
                for(l = k; l < j-1; l++){
                    arr[i][l] = arr[i][l+1];
                    j--;
                }
            }
        }

        //imprimindo o vetor depois;
        printf("\n\n");
        for(k = 0; k < j; k++){
            printf("%d ", arr[i][k]);
        }

        arr[i] = (int*) realloc(arr, j);
        currsize += j;

        printf("\n\nESPACO ATUALMENTE OCUPADO: %d BYTES.\nINSERIR OUTRO VETOR?\n1. SIM\n2. NAO\n\n>> ", currsize*4);
        scanf("%d", &input);
        if(input != 1) break;
        else{
            i++;
            arr = (int**) realloc(arr, i+1);
            printf("Preencha seu proximo vetor.\n\n");
        }
    }

    printf("\n\nEncerrando...\n");
    return 0;
}
