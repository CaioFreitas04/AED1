#include <stdio.h>
#include <stdlib.h>

int main(){
    //var;
    int i;
    float notas[3], media = 0, final;
    printf("Insira as tres notas do aluno.\n");
    for(i = 0; i < 3; i++){
        scanf("%f", &notas[i]);
        media += notas[i];
    }
    media /= 3;
    printf("\n");

    if(media <= 3) printf("REPROVADO!\n\n");
    else if(media < 6){
        //                      6 = (media + nota_final) / 2;
        final = 12 - media;
        printf("EXAME FINAL: o aluno deve tirar, no minimo, %.2f para passar!\n\n", final);
    }
    else printf("APROVADO!\n\n");

    system("pause");
    return 0;
}