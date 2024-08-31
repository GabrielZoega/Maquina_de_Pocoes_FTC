#ifndef LEITURARECEITAS_H
#define LEITURARECEITAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maquinas.h"
#define AFD 1
#define AP 2


int contaEstados(char *string);
void guardaEstados(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *string, int tipoAutomato);
void guardaTransicao(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *string, int *proximoIndice, int tipoAutomato);
void guardaTransicaoAF(MaquinaDeEstadosAFD *maquinaAFD, char *string, int *proximoIndice);
void guardaTransicaoAP(MaquinaDeEstadosAP *maquinaAP, char *string, int *proximoIndice);
void leArquivo(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *nomeArquivo, int tipoAutomano);
void leEstados(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *nomeArquivo, char *estados, int *numEstados, int *numTransicoes, int tipoAutomato);
void leTransicoes(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *nomeArquivo, int *numTransicoes, int tipoAutomato);
int contaCaracteres(char *string);

#endif
