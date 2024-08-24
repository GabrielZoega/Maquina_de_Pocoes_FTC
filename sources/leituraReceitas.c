#include "../headers/leituraReceitas.h"

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

void guardaEstados(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *string, int tipoAutomato) {
    int i = 0;
    char aux[100];
    strcpy(aux, string);

    char *token = strtok(aux, " ");

    while (token != NULL) {
    	if(tipoAutomato == AFD){
			if((strcmp(maquinaAFD->estadoInicial, token) != 0) && (strcmp(maquinaAFD->estadoFinal, token) != 0)){
				adicionaEstado(maquinaAFD, maquinaAP, token, i, tipoAutomato);
				i++;
			}

    	}else if(tipoAutomato == AP){
    		if((strcmp(maquinaAP->estadoInicial, token) != 0) && (strcmp(maquinaAP->estadoFinal, token) != 0)){
				adicionaEstado(maquinaAFD, maquinaAP, token, i, tipoAutomato);
				i++;
			}
    	}
        token = strtok(NULL, " ");
    }
}

void guardaTransicao(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *string, int *proximoIndice, int tipoAutomato){
    char estadoPartida[TAM_ESTADO];
    char estadoDestino[TAM_ESTADO];
    char auxLinha[100];
    char auxTransicao[50];
    char auxCaracteres[50];

    strcpy(auxLinha, string);
    char *tokenLinha = strtok(auxLinha, "|"); //token recebe a primeira string, a transicao

    strcpy(auxTransicao, tokenLinha);
    tokenLinha = strtok(NULL, "|"); //token recebe a string depois de '|', os caracteres de entrada

    char *tokenTransicao = strtok(auxTransicao, " "); //token recebe a primeira string, o estado de partida
    strcpy(estadoPartida, tokenTransicao);
    tokenTransicao = strtok(NULL, " "); //token recebe a segunda string, no caso "->"
    tokenTransicao = strtok(NULL, " "); //token recebe a terceira string, o estado de destino
    strcpy(estadoDestino, tokenTransicao);

    strcpy(auxCaracteres, tokenLinha);
    char *tokenCaracteres = strtok(auxCaracteres, " ");
    while (tokenCaracteres != NULL) {
        adicionaTransicao(maquinaAFD, maquinaAP, estadoPartida, estadoDestino, tokenCaracteres[0], *proximoIndice, tipoAutomato);
        (*proximoIndice)++;
        tokenCaracteres = strtok(NULL, " ");
    }
}

void leArquivo(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *nomeArquivo, int tipoAutomato){
    int numTransicoes = 0;
    int numEstados = 0;
    char estados[100];

    leEstados(maquinaAFD, maquinaAP, nomeArquivo, estados, &numEstados, &numTransicoes, tipoAutomato);

    inicializaAutomato(maquinaAFD, maquinaAP, numEstados, numTransicoes, tipoAutomato);
    guardaEstados(maquinaAFD, maquinaAP, estados, tipoAutomato);

    leTransicoes(maquinaAFD, maquinaAP, nomeArquivo, &numTransicoes, tipoAutomato);
}

void leEstados(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *nomeArquivo, char *estados, int *numEstados, int *numTransicoes, int tipoAutomato){
    FILE *arq;
    char linha[100];
    *numTransicoes = 0;
    if((arq = fopen(nomeArquivo, "r")) == NULL){
        printf("ERRO. Nao foi possivel ler o arquivo.\n");

    }else{
        fscanf(arq, "Q: %[^\n]s", estados);
        // printf("%s\n", linha);
        // printf("%d\n", contaEstados(linha));
        fgets(linha, 100, arq);
        *numEstados = contaEstados(estados);

        if(tipoAutomato == AFD){
			fscanf(arq, "I: %s", maquinaAFD->estadoInicial);
			fgets(linha, 100, arq);
			fscanf(arq, "F: %s", maquinaAFD->estadoFinal);

        }else if(tipoAutomato == AP){
        	fscanf(arq, "I: %s", maquinaAP->estadoInicial);
        	fgets(linha, 100, arq);
        	fscanf(arq, "F: %s", maquinaAP->estadoFinal);
        }
		fgets(linha, 100, arq); //le o \n
		fgets(linha, 100, arq); //le a linha de transicao

        while (strcmp(linha, "---") != 0){
            *numTransicoes += contaCaracteres(linha);
        	fgets(linha, 100, arq);
        }
        fclose(arq);
    }
}

void leTransicoes(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *nomeArquivo, int *numTransicoes, int tipoAutomato){
    FILE *arq;
    char linha[100];
    if((arq = fopen(nomeArquivo, "r")) == NULL){
        printf("ERRO. Nao foi possivel ler o arquivo.\n");

    }else{

        for(int i = 0; i < 3; i++){
            fgets(linha, 100, arq);
        }
        int proximoIndice = 0;

        fgets(linha, 100, arq);
        while (strcmp(linha, "---") != 0){
            guardaTransicao(maquinaAFD, maquinaAP, linha, &proximoIndice, tipoAutomato);
        	fgets(linha, 100, arq);
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
