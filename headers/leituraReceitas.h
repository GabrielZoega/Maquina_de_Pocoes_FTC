#ifndef LEITURARECEITAS_H
#define LEITURARECEITAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maquinas.h"


int contaEstados(char *string);
void guardaEstados(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *string, int tipoAutomato);
void guardaTransicao(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *string, int *proximoIndice, int tipoAutomato);
void leArquivo(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *nomeArquivo, int tipoAutomano);
void leEstados(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *nomeArquivo, char *estados, int *numEstados, int *numTransicoes, int tipoAutomato);
void leTransicoes(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *nomeArquivo, int *numTransicoes, int tipoAutomato);
int contaCaracteres(char *string);

#endif
