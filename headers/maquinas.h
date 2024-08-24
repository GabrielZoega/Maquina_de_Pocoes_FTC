#ifndef MAQUINAS_H
#define MAQUINAS_H

#define TAM_ESTADO 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

//estado de partida, estado de destino, entrada
typedef struct transicao{
    char estadoDePartida[TAM_ESTADO];
    char estadoDeDestino[TAM_ESTADO];
    char caracterDeEntrada;
}Transicao;

//estado partida, desempilha, empilha, estado de destino
typedef struct transicaoP{
    Transicao transicao;
    char charEmpilha;
    char charDesempilha;
}TransicaoP;

typedef struct maquinaAfd{
    char **estados;
    char estadoInicial[TAM_ESTADO];
    char estadoFinal[TAM_ESTADO];
    char estadoAtual[TAM_ESTADO];
    int numTransicoes;
    Transicao *transicoes;
} MaquinaDeEstadosAFD;

typedef struct maquinaAP{
    char **estados;
    char estadoInicial[TAM_ESTADO];
    char estadoFinal[TAM_ESTADO];
    char estadoAtual[TAM_ESTADO];
    int numTransicoes;
    Pilha stack;
    TransicaoP *transicoesP;
    // talvez adicionar o resto da palavra 
} MaquinaDeEstadosAP;

//3 ingredientes e transições no mínimo
void alocaEstados(MaquinaDeEstadosAFD *maquina, int numEstados);
void alocaEstadosAP(MaquinaDeEstadosAP *maquina, int numEstados);
void adicionaEstado(MaquinaDeEstadosAFD *maquina, char *estado, int indice);
void alocaTransicoesAF(MaquinaDeEstadosAFD *maquina, int numTransicao);
void alocaTransicoesAP(MaquinaDeEstadosAP *maquina, int numTransicao);
void adicionaTransicao(MaquinaDeEstadosAFD *maquina, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice);
void fazerTransicaoAFD(char caractereEntrada, MaquinaDeEstadosAFD * maquina, char *nomePocao);
void fazerTransicaoAPD(char caractereEntrada, char* caractereEmpilha, char caractereDesempilha, MaquinaDeEstadosAP* maquina,char *nomePocao);
void inicializaAFD(MaquinaDeEstadosAFD *maquina, int numEstados, int numTransicoes);
void inicializaAP(MaquinaDeEstadosAP* maquina, int numEstados, int numTransicoes);

#endif