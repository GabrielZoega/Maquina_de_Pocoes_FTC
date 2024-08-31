#include "../headers/pilha.h"
#include <stdio.h>
#include <stdlib.h>

void FPVazia(Pilha *pilha){
    pilha->pTopo = NULL;
    pilha->tamanho = 0;
}

int PEhVazia(Pilha *pilha){
    return (pilha->pTopo == NULL);
}

void PEmpilha(Pilha *pilha, char caractere){
    apontador pNovo;
    pNovo = (apontador) malloc (sizeof(Celula));
    if(pNovo == NULL) return;

    pNovo->caractere = caractere;
    pNovo->pProx = pilha->pTopo;
    pilha->pTopo = pNovo;
    pilha->tamanho++;
}

char PDesempilha(Pilha* pilha){

    apontador pAux;
    char caractere;
    if (PEhVazia(pilha)) return '\0';

    pAux = pilha->pTopo;
    pilha->pTopo = pAux->pProx;
    caractere = pAux->caractere;
    free(pAux);
    pilha->tamanho--;

    return caractere;
}


int PTamanho(Pilha* pilha){
    return (pilha->tamanho);
}