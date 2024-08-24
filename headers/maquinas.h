#ifndef MAQUINAS_H
#define MAQUINAS_H

#define TAM_ESTADO 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define AP 0
#define AFD 1

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
void inicializaAutomato(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, int numEstados, int numTransicoes, int tipoAutomato);
void inicializaAFD(MaquinaDeEstadosAFD *maquina, int numEstados, int numTransicoes);
void inicializaAP(MaquinaDeEstadosAP* maquina, int numEstados, int numTransicoes);

void alocaEstados(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, int numEstados, int tipoAutomato);
void alocaEstadosAF(MaquinaDeEstadosAFD *maquina, int numEstados);
void alocaEstadosAP(MaquinaDeEstadosAP *maquina, int numEstados);

void alocaTransicoes(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, int numTransicoes, int tipoAutomato);
void alocaTransicoesAF(MaquinaDeEstadosAFD *maquina, int numTransicao);
void alocaTransicoesAP(MaquinaDeEstadosAP *maquina, int numTransicao);

void adicionaEstado(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *estado, int indice, int tipoAutomato);
void adicionaEstadoAF(MaquinaDeEstadosAFD *maquina, char *estado, int indice);
void adicionaEstadoAP(MaquinaDeEstadosAP *maquina, char *estado, int indice);

void adicionaTransicao(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice, int tipoAutomato);
void adicionaTransicaoAF(MaquinaDeEstadosAFD *maquina, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice);
void adicionaTransicaoAP(MaquinaDeEstadosAP *maquina, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice);

void fazerTransicaoAFD(char caractereEntrada, MaquinaDeEstadosAFD * maquina, char *nomePocao);
void fazerTransicaoAPD(char caractereEntrada, char* caractereEmpilha, char caractereDesempilha, MaquinaDeEstadosAP* maquina,char *nomePocao);

#endif
