#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/maquinas.h"

int contaEstados(char *string);
void guardaEstados(MaquinaDeEstadosAFD *maquina, char *string);

int main(){
    MaquinaDeEstadosAFD maquinaAFD;
    
    FILE *arq;
    char linhaQ[100];
    if((arq = fopen("receitas/entrada.txt", "r")) == NULL){
        printf("ERRO. Nao foi possivel ler o arquivo.\n");
    
    }else{
        fscanf(arq, "Q: %[^\n]s", linhaQ);
        // printf("%s\n", linhaQ);
        // printf("%d\n", contaEstados(linhaQ));

        alocaEstados(&maquinaAFD, contaEstados(linhaQ));

        fscanf(arq, "I: %s", maquinaAFD.estadoInicial);
        fscanf(arq, "F: %s", maquinaAFD.estadoFinal);
        //TODO falta a leitura do resto do arquivo
        while (!feof(arq)){
            fgets(linhaQ, 100, arq);
        }
        
    }

    return 0;
}

int contaEstados(char *string) {
    int cont = 0;
    char aux[100]; 
    strcpy(aux, string);

    char *token = strtok(aux, " ");

    while (token != NULL) {
        cont++;
        token = strtok(NULL, " ");
    }
    return cont;
}

void guardaEstados(MaquinaDeEstadosAFD *maquina, char *string) {
    int i = 0;
    char aux[100]; 
    strcpy(aux, string);

    char *token = strtok(aux, " ");

    while (token != NULL) {
        adicionaEstado(maquina, token, i);
        i++;
        token = strtok(NULL, " ");
    }
}