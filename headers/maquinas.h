#ifndef MAQUINAS_H
#define MAQUINAS_H

#define TAM_ESTADO 8
#define TAM_POCAO 50
#define TEXT_COLOR_256(x)    "\033[38;5;" x "m"
#define RESET       "\033[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "reacoes.h"

#define AFD 1
#define AP 2

typedef struct estadoFinal{
    char nomeEstado[TAM_ESTADO];
    char nomePocao[TAM_POCAO];
}EstadoFinal;

//estado de partida, estado de destino, entrada
typedef struct transicao{
    char estadoDePartida[TAM_ESTADO];
    char estadoDeDestino[TAM_ESTADO];
    char caracterDeEntrada;
}Transicao;

//estado partida, desempilha, empilha, estado de destino
typedef struct transicaoP{
    Transicao transicao;
    char *charEmpilha;
    char charDesempilha;
}TransicaoP;

typedef struct maquinaAfd{
    char **estados;
    char estadoInicial[TAM_ESTADO];
    EstadoFinal estadoFinal;
    char estadoAtual[TAM_ESTADO];
    int numTransicoes;
    Transicao *transicoes;
} MaquinaDeEstadosAFD;

typedef struct maquinaAP{
    char **estados;
    char estadoInicial[TAM_ESTADO];
    EstadoFinal estadoFinal;
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

void adicionaTransicao(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice, int tipoAutomato, char *caractereEmpilha, char caractereDesempilha);
void adicionaTransicaoAF(MaquinaDeEstadosAFD *maquina, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice);
void adicionaTransicaoAP(MaquinaDeEstadosAP *maquina, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice,char *caractereEmpilha, char caractereDesempilha);

void fazerTransicao(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char caractereEntrada, int tipoAutomato);
void fazerTransicaoAFD(char caractereEntrada, MaquinaDeEstadosAFD * maquina);
void fazerTransicaoAPD(char caractereEntrada, MaquinaDeEstadosAP* maquina);

void resultado(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, int tipoAutomato);
void resultadoAFD(MaquinaDeEstadosAFD *maquina);
void resultadoAP(MaquinaDeEstadosAP *maquina);

#endif
