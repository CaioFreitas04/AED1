#include <stdio.h>
#include <stdlib.h>

void GUI();                                         //função de interface simples;
int calc(double x, double y, char OP, double *res); //função calculadora, recebe um operando, um resultado, e duas parcelas;

int main(){
    //var. x e y são as parcelas, res o resultado, e OP o operador;
    int status = 0;
    double x, y, res;
    char OP;

    printf("\t\t--CALCULADORA--\n\n");
    while(status != 2){
        GUI();
        setbuf(stdin, NULL);
        scanf("%c%lf%lf", &OP, &x, &y);
        status = calc(x, y, OP, &res);

        switch(status){
            case 0: printf("\n\n\tRESULTADO: %lf\n\n\n\n\n", res); break;
            case 1: printf("\n\n\tERR: operacao_invalida\n\n\n\n\n"); break;
            case 2: printf("\n\n\tSaindo...\n\n\n\n\n");
        }
    }
    system("pause");
    return 0;
}


void GUI(){
    printf("\tEscreva uma expressao matematica da seguinte forma: + 4 3\n");
    printf("\tOperadores validos: +  -  *  / \n");
    printf("\n\t>> ");
}

int calc(double x, double y, char OP, double* res){
    switch(OP){
        case '+': *res = x + y; return 0;
        case '-': *res = x - y; return 0;
        case '*': *res = x * y; return 0;
        case '/':
            if(y == 0) return 1;
            else *res = x / y; return 0;
        default: return 1;
    }
}