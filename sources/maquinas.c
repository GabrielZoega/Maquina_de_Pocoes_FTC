#include "../headers/maquinas.h"

void alocaEstados(MaquinaDeEstadosAFD *maquina, int numEstados){
    maquina->estados = (char**) malloc (sizeof(char*) * numEstados);
    for(int i = 0; i < numEstados; i++){
        maquina->estados[i] = (char*) malloc(sizeof(char) * TAM_ESTADO);
        strcpy(maquina->estados[i], "");
    }
}

void alocaTransicao(MaquinaDeEstadosAFD *maquina, int numTransicao){
    maquina->estados = (char**) malloc (sizeof(char*) * numTransicao);
    for(int i = 0; i < numTransicao; i++){
        maquina->estados[i] = (char*) malloc(sizeof(char) * TAM_TRANSICAO);
        strcpy(maquina->transicoes[i], "");
    }
}

void adicionaEstado(MaquinaDeEstadosAFD *maquina, char *estado, int indice){
    strcpy(maquina->estados[indice], estado);
}

void adicionaTransicao(MaquinaDeEstadosAFD *maquina, char *transicao, int indice){
    strcpy(maquina->transicoes[indice], transicao);
}