#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listair.h"

typedef struct lista{
    char sigla[5];   //essa string foi armazenada para que a lista codifique qual o aeroporto-origem;
    no *ini;
} list;

typedef struct aeroporto{
    char nome[30], sigla[5];
    float prec;
} aer;

typedef struct node{
    aer index;
    no *next;
} no;

int main(){
    list **cidades = (list**) calloc(0, sizeof(list*)), **dummy;
    char inputc[30], inputc2[30];
    aer inputa;
    int i, ltotal = 0, MODE;

    while(1){
        printf("\n\n\tAEROPORTO\n\n");
        printf("1. Cadastrar cidade.\n");
        printf("2. Cadastrar rotas de cidade.\n");
        printf("3. Remover cidade.\n");
        printf("4. Remover rota.\n");
        printf("5. Exibir rotas de cidade.\n");
        printf("6. Consultar preco de rota.\n");
        printf("7. Exibir as rotas mais cara e mais barata de uma cidade.\n");
        printf("8. Sair.\n");
        printf("\n>> ");
        scanf("%d", &MODE);
        switch(MODE){
            case 1: //cadastrar cidade;
                dummy = (list**) realloc(cidades, ltotal+1);
                if(dummy != NULL) cidades = dummy;
                printf("Insira a sigla do aeroporto da cidade.\n>> ");
                setbuf(stdin, NULL);
                fgets(inputc, 5, stdin);
                inputc[strlen(inputc)-1] = '\0';
                cidades[ltotal] = create(inputc);
                ltotal++;
                printf("Cidade cadastrada.\n");
                break;

            case 2: //cadastrar rota;
                printf("Insira a sigla do aeroporto da cidade.\n>> ");
                setbuf(stdin, NULL);
                fgets(inputc, 5, stdin);
                inputc[strlen(inputc)-1] = '\0';
                for(i = 0; i < ltotal; i++){
                    if(strcmp(cidades[i]->sigla, inputc) == 0){
                        printf("Insira o nome do aeroporto-destino.\n>> ");
                        setbuf(stdin, NULL);
                        fgets(inputa.nome, 30, stdin);
                        inputa.nome[strlen(inputa.nome)-1] = '\0';

                        printf("Insira a sigla do aeroporto-destino.\n>> ");
                        setbuf(stdin, NULL);
                        fgets(inputa.sigla, 5, stdin);
                        inputa.sigla[strlen(inputa.sigla)-1] = '\0';

                        printf("Insira o preco da passagem.\n>> ");
                        scanf("%f", &inputa.prec);

                        insertIni(cidades[i], inputa);
                        i = -1;
                        printf("Cidade inserida.\n");
                    }
                    if(i == -1) break;
                }
                if(i != -1) printf("Cidade nao encontrada.\n");
                break;

            case 3: //remover cidade;
                printf("Insira a sigla da cidade.\n>> ");
                setbuf(stdin, NULL);
                fgets(inputc, 5, stdin);
                inputc[strlen(inputc)-1] = '\0';
                for(i = 0; i < ltotal; i++){
                    if(strcmp(cidades[i]->sigla, inputc) == 0){
                        clear(cidades[i]);
                        free(cidades[i]);
                        i = -1;
                        printf("Cidade removida.\n");
                    }
                    if(i == -1) break;
                }
                if(i != -1) printf("Cidade nao encontrada.\n");
                break;

            case 4: //remover rota;
                printf("Insira a sigla da cidade.\n>> ");
                setbuf(stdin, NULL);
                fgets(inputc, 5, stdin);
                inputc[strlen(inputc)-1] = '\0';
                for(i = 0; i < ltotal; i++){
                    if(strcmp(cidades[i]->sigla, inputc) == 0){
                        printf("Insira a sigla da cidade-destino.\n>> ");
                        setbuf(stdin, NULL);
                        fgets(inputa.sigla, 5, stdin);
                        inputa.sigla[strlen(inputa.sigla)-1] = '\0';
                        switch(removeItem(cidades[i], inputa)){
                            case 0:
                                printf("Removida com sucesso.\n");
                                break;
                            case -1:
                                printf("Rota nao encontrada.\n");
                                break;
                            default:
                                printf("Falha ao remover.\n");
                                break;
                        }
                        i = -1;
                    }
                    if(i == -1) break;
                }
                if(i != -1) printf("Cidade nao encontrada.\n");
                break;
            case 5: //exibir rotas;
                printf("Insira a sigla da cidade.\n>> ");
                setbuf(stdin, NULL);
                fgets(inputc, 5, stdin);
                inputc[strlen(inputc)-1] = '\0';
                for(i = 0; i < ltotal; i++){
                    if(strcmp(cidades[i]->sigla, inputc) == 0){
                        displayList(cidades[i]);
                        i = -1;
                    }
                    if(i == -1) break;
                }
                if(i != -1) printf("Cidade nao encontrada.\n");
                break;

            case 6: //consultar preço de rota;
                printf("Insira as siglas de seu aeroporto de saida, e seu aeroporto de destino.\n>> ");
                setbuf(stdin, NULL);
                fgets(inputc, 5, stdin);
                inputc[strlen(inputc)-1] = '\0';
                printf(">> ");
                setbuf(stdin, NULL);
                fgets(inputc2, 5, stdin);
                inputc2[strlen(inputc2)-1] = '\0';
                for(i = 0; i < ltotal; i++){
                    if(strcmp(cidades[i]->sigla, inputc) == 0){
                        if(showPrice(cidades[i], inputc2) != 0){
                            printf("Nao ha rota ate o destino especificado.\n");
                        }
                        i = -1;
                    }
                    if(i == -1) break;
                }
                if(i != -1) printf("Cidade de saida invalida.\n");
                break;

            case 7: //rota mais cara e mais barata;
                printf("Insira a sigla da cidade.\n>> ");
                setbuf(stdin, NULL);
                fgets(inputc, 5, stdin);
                inputc[strlen(inputc)-1] = '\0';
                for(i = 0; i < ltotal; i++){
                    if(strcmp(cidades[i]->sigla, inputc) == 0){
                        if(displayCaraBarata(cidades[i]) != 0){
                            printf("Nao ha rotas cadastradas nessa cidade.\n");
                        }
                        i = -1;
                    }
                    if(i == -1) break;
                }
                if(i != -1) printf("Cidade nao encontrada.\n");
                break;

            case 8: //sair;
                printf("Encerrando...\n\n");
                system("pause");
                return 0;

            default:
                printf("Comando invalido.\n");
                break;
        }
        printf("\n");
        system("pause");
    }
}