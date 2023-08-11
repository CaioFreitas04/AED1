#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cliente{ //estado civil, CPF, matriz de filiação;
    int estCiv, nfil;
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
    
    //alocando memória;
    clVec = (clt*) calloc(vecL, sizeof(clt));

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
                system("pause");
                break;
            case 2:
                switch(remClient(clVec, vecL)){
                    case 0:
                        printf("\n\tCliente removido com sucesso!\n\n");
                        break;
                    
                    case 1:
                        printf("\n\tBanco de clientes ja vazio!\n\n");
                        break;
                    
                    case 2:
                        printf("\n\tImpossivel realizar operacao.\n\n");
                        break;
                }
                system("pause");
                break;
            case 3:
                if(dplClient(clVec, vecL)){
                    printf("\n\tNenhum cliente registrado!\n\n");
                }
                else{
                    printf("\n");
                }
                system("pause");
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
    int i = 0, j;
    //encontrando um slot vazio no array;
    while(strlen(clVec[i].CPF) != 0 && i < vecL){
        i++;
    }
    if(i == vecL) return 1;

    //coletando dados;
    //CPF;
    printf("\n\nInsira o CPF do cliente.\n>> ");
    setbuf(stdin, NULL);
    fgets(clVec[i].CPF, 16, stdin);
    clVec[i].CPF[strcspn(clVec[i].CPF, "\n")] = 0;
    //estado civil;
    printf("Insira o estado civil do cliente.\n");
    printf("1: solteiro\n2: casado\n3: separado\n4: divorciado\n5: viuvo\n0: nao-informado.\n\n>> ");
    scanf("%d", &clVec[i].estCiv);
    //filhos;
    printf("Quantos filhos tem o cliente?\n>> ");
    scanf("%d", &clVec[i].nfil);
    //se o cliente não tem filhos, a função retorna para a main;
    if(clVec[i].nfil <= 0){
        clVec[i].nfil = 0;
    }
    //senão, é alocada uma matriz de caracteres preenchida com o nome dos filhos;
    else{
        clVec[i].fil = (char**) calloc(clVec[i].nfil, sizeof(char*));
        for(j = 0; j < clVec[i].nfil; j++){
            clVec[i].fil[j] = (char*) calloc(64, sizeof(char));
            printf("Insira o nome do filho %d: ", (j+1));
            setbuf(stdin, NULL);
            fgets(clVec[i].fil[j], 64, stdin);
            clVec[i].fil[j][strcspn(clVec[i].CPF, "\n")] = 0;
        }
    }
    return 0;
}

int remClient(clt *clVec, int vecL){
    int i, *clarr, input = 0;

    //armazenando dados no vetor clarr, que diz se um dado slot está ocupado ou não;
    clarr = (int*) calloc(vecL, sizeof(int));
    for(i = 0; i < vecL; i++){
        clarr[i] = 0;
        if(strlen(clVec[i].CPF) != 0){
            clarr[i] = 1;
            input = 1;      //a variável input está sendo reciclada para servir de flag, indicando se o vetor está vazio;
        }
    }
    if(input == 0) return 1;

    printf("\n\nIndique qual cliente voce deseja remover.\n");
    for(i = 0; i < vecL; i++){
        if(clarr[i]) printf("%d -> CPF: %s\n", i, clVec[i].CPF);
    }
    printf(">> ");
    scanf("%d", &input);

    //detectando se o usuário fez algo de errado.
    if(clarr[input] == 0 || (input > vecL || input < 0)){
        return 2;
    }
    else{
        for(i = 0; i < strlen(clVec[input].CPF); i++){
            clVec[input].CPF[i] = '\0';
        }
        for(i = 0; i < clVec[input].nfil; i++){
            free(clVec[input].fil[i]);
        }
        free(clVec[input].fil);
        return 0;
    }
}

int dplClient(clt *clVec, int vecL){
    int i, count = 0;

    printf("\n\n");
    for(i = 0; i < vecL; i++){
        if(strlen(clVec[i].CPF) == 0) continue;     //ignorar os slots vazios;
        else{
            printf("\t%d -> CPF: %s.\n", i, clVec[i].CPF);
            count++;
        }
    }
    if(count == 0) return 1;
    else return 0;
}
