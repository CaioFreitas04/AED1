#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cliente{ //estado civil, CPF, matriz de filiação;
    int estCiv;
    char CPF[16], **fil;
} clt;


void GUI();                                 //menuzinho;
int addClient(clt *clVec, int vecL);        //adiciona um cliente ao vetor;
int remClient(clt *clVec, int vecL);        //remove um cliente do vetor;
int dplClient(clt *clVec, int vecL);        //exibe informações sobre os clientes do vetor;


int main(){
    //var;
    int i, vecL, MODE;
    clt *clVec;

    printf("\t\t--GERENCIADOR DE CLIENTES--\n\n");
    printf("Insira quantos clientes deseja armazenar.\n");
    while(1){
        printf(">> ");
        scanf("%d", &vecL);
        if(vecL > 0) break;
        printf("Valor invalido.\n\n");
    }
    
    //inicializando CPFs;
    for(i = 0; i < vecL; i++){
        clVec[i].CPF[0] = '\0';
    }

    //loop principal;
    while(1){
        printf("\n\n");
        GUI();
        while(1){
            printf("\t>> ");
            scanf("%d", &MODE);
            if(MODE > 0 && MODE < 5) break;
            else printf("Comando invalido.\n");
        }
        if(MODE == 4) break;
        switch(MODE){
            case 1:
                if(addClient(clVec, vecL)) printf("\n\tSeu vetor ja esta completamente preenchido!\n\n");
                else printf("\n\tCliente adicionado com sucesso!\n\n");
                break;
            case 2:
                if(remClient(clVec, vecL)) printf("\n\tSeu vetor ja esta completamente vazio!\n\n");
                else printf("\n\tCliente removido com sucesso!\n\n");
                break;
            case 3:
                if(dplClient(clVec, vecL)) printf("\n\tNenhum cliente registrado!\n\n");
                else continue;
        }
    }

    printf("\n\n\tEncerrando...\n\n");
    system("pause");
    return 0;
}


void GUI(){
    printf("\t\t--Menu--\n\n");
    printf("\t1. Adicionar cliente.\n");
    printf("\t2. Remover cliente.\n");
    printf("\t3. Visualizar clientes.\n");
    printf("\t4. Sair.\n");
    printf("\n\tComando?\n");
}

int addClient(clt *clVec, int vecL){
    int i = 0;
    while(strlen(clVec[i].CPF) == 0){
        //terminar depois;
    }
}