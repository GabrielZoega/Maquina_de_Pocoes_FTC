#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/maquinas.h"
#define APD 0
#define AFD 1

int contaEstados(char *string);
void guardaEstados(MaquinaDeEstadosAFD *maquina, char *string);
void guardaTransicao(MaquinaDeEstadosAFD *maquina, char *string, int *proximoIndice);
void leArquivo(MaquinaDeEstadosAFD *maquina, char *nomeArquivo, int tipoAutomano);
void leEstados(MaquinaDeEstadosAFD *maquina, char *nomeArquivo, int *numEstados, int *numTransicoes);
void leTransicoes(MaquinaDeEstadosAFD *maquina, char *nomeArquivo, int *numTransicoes);
int contaCaracteres(char *string);

int main(){
    MaquinaDeEstadosAFD maquinaAFD;
    
    leArquivo(&maquinaAFD, "receitas/entrada.txt", AFD);
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
        if(!strcmp(maquina->estadoInicial, token) && !strcmp(maquina->estadoFinal, token)){
            adicionaEstado(maquina, token, i);
            i++;
        }
        token = strtok(NULL, " ");
    }
}

void guardaTransicao(MaquinaDeEstadosAFD *maquina, char *string, int *proximoIndice){
    char estadoPartida[TAM_ESTADO];
    char estadoDestino[TAM_ESTADO];
    char aux[100]; 

    strcpy(aux, string);
    char *tokenLinha = strtok(aux, "|"); //token recebe a primeira string, a transicao

    char *tokenTransicao = strtok(tokenLinha, " "); //token recebe a primeira string, o estado de partida
    strcpy(estadoPartida, tokenTransicao);
    tokenTransicao = strtok(NULL, " "); //token recebe a segunda string, no caso "->"
    tokenTransicao = strtok(NULL, " "); //token recebe a terceira string, o estado de destino
    strcpy(estadoDestino, tokenTransicao);

    tokenLinha = strtok(NULL, "|"); //token recebe a string depois de '|', os caracteres de entrada
    strcpy(aux, tokenLinha);
    char *tokenCaracteres = strtok(aux, " ");
    while (tokenCaracteres != NULL) {
        adicionaTransicao(maquina, estadoPartida, estadoDestino, tokenCaracteres[0], *proximoIndice);
        (*proximoIndice)++;
        tokenCaracteres = strtok(NULL, " ");
    }
}

void leArquivo(MaquinaDeEstadosAFD *maquina, char *nomeArquivo, int tipoAutomato){
    int numTransicoes = 0;
    int numEstados = 0;
    leEstados(maquina, nomeArquivo, &numEstados, &numTransicoes);
    leTransicoes(maquina, nomeArquivo, &numTransicoes);
    if(tipoAutomato == AFD){
        inicializaAFD(maquina, numEstados, numTransicoes);
    
    }else if(tipoAutomato == APD){
        inicializaAP(maquina, numEstados, numTransicoes);
    }
}

void leEstados(MaquinaDeEstadosAFD *maquina, char *nomeArquivo, int *numEstados, int *numTransicoes){
    FILE *arq;
    char linha[100];
    *numTransicoes = 0;
    if((arq = fopen(nomeArquivo, "r")) == NULL){
        printf("ERRO. Nao foi possivel ler o arquivo.\n");
    
    }else{
        fscanf(arq, "Q: %[^\n]s", linha);
        // printf("%s\n", linha);
        // printf("%d\n", contaEstados(linha));

        *numEstados = contaEstados(linha);

        fscanf(arq, "I: %s", maquina->estadoInicial);
        fscanf(arq, "F: %s", maquina->estadoFinal);

        guardaEstados(maquina, linha);

        while (!strcmp(linha, "---")){
            fgets(linha, 100, arq);
            numTransicoes += contaCaracteres(linha);
        }
        fclose(arq);        
    }
}

void leTransicoes(MaquinaDeEstadosAFD *maquina, char *nomeArquivo, int *numTransicoes, int tipoAutomato){
    FILE *arq;
    char linha[100];
    if((arq = fopen(nomeArquivo, "r")) == NULL){
        printf("ERRO. Nao foi possivel ler o arquivo.\n");
    
    }else{
        
        for(int i = 0; i < 3; i++){
            fgets(linha, 100, arq);
        }
        int proximoIndice = 0;
        while (!strcmp(linha, "---")){            
            fgets(linha, 100, arq);
            guardaTransicao(maquina, linha, &proximoIndice);
        }
        fclose(arq);        
    }
}

int contaCaracteres(char *string){
    int qtCaracteres = 0;
    char aux[100]; 

    strcpy(aux, string);
    char *tokenLinha = strtok(aux, "|");
    tokenLinha = strtok(NULL, "|"); //token recebe a string depois de '|'

    strcpy(aux, tokenLinha);
    char *tokenCaracteres = strtok(aux, " ");
    while (tokenCaracteres != NULL) {
        qtCaracteres++;
        tokenCaracteres = strtok(NULL, " ");
    }
    return qtCaracteres;
}
