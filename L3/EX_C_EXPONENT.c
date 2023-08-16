#include <stdio.h>
#include <stdlib.h>

typedef long long int loong;

double xey(double x, int y);            //função expoente;
loong fact(int x);                      //função fatorial;
double ex(int x, int N);                //função exponencial e^x;

int main(){
    //var;
    int x, N;
    double e;

    printf("e^x, insira x.\n>> ");
    do{
        scanf("%d", &x);
        if(x > 0) break;
        else printf("Insira um valor maior do que 0!\n");
    }while(1);
    printf("Insira quantas parcelas, N, serao usadas para a aproximacao.\n>> ");
    do{
        scanf("%d", &N);
        if(N > 1) break;
        else printf("Insira um valor maior do que 1!\n");
    }while(1);
    
    e = ex(x, N);

    printf("\ne^%d = %lf\n\n", x, e);

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

loong fact(int x){
    if(x == 0) return 1;
    else{
        return x * fact(x - 1);
    }
}

double ex(int x, int N){
    double e = x + 1;
    int i;

    if(x == 1) return 2.71828182846;

    for(i = 1; i < N; i++){
        e += (xey(x, i+1)/fact(i+1));
    }

    return e;
}