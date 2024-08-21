#ifndef MAQUINAS_H
#define MAQUINAS_H

#define TAM_ESTADO 8
#define TAM_TRANSICAO 35

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

//estado de partida, estado de destino, entrada
typedef struct transicao{
    char estadoDePartida[TAM_ESTADO];
    char estadoDeDestino[TAM_ESTADO];
    char *caracteresDeEntrada;
}Transicao;

//estado partida, desempilha, empilha, estado de destino
typedef struct transicaoP{
    Transicao transicao;
    Pilha stack;
}TransicaoP;

typedef struct maquinaAfd{
    char **estados;
    char estadoInicial[TAM_ESTADO];
    char estadoFinal[TAM_ESTADO];
    char estadoAtual[TAM_ESTADO];
    Transicao *transicoes;
} MaquinaDeEstadosAFD;

typedef struct maquinaAP{
    char **estados;
    char estadoInicial[TAM_ESTADO];
    char estadoFinal[TAM_ESTADO];
    char estadoAtual[TAM_ESTADO];
    TransicaoP *transicoesP;

    // talvez adicionar o resto da palavra 
} MaquinaDeEstadosAP;

//3 ingredientes e transições no mínimo
void alocaEstados(MaquinaDeEstadosAFD *maquina, int numEstados);
void adicionaEstado(MaquinaDeEstadosAFD *maquina, char *estado, int indice);

#endif