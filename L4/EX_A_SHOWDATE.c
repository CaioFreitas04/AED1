#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int dd, mm, yyyy;
} dat;

void displayData(dat x);        //recebe uma data e imprime ela no formato dd/mm/yyyy;

int main(){
    //var;
    dat data;

    printf("Insira uma data para ser impressa (dia, mes, ano, em numeros).\n>> ");
    scanf("%d%d%d", &data.dd, &data.mm, &data.yyyy);
    printf("\n\n\t");
    displayData(data);
    printf("\n\n");
    system("pause");
    return 0;
}

void displayData(dat x){
    printf("%d/%d/%d", x.dd, x.mm, x.yyyy);
}
