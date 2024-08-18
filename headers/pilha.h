#ifndef PILHA_H
#define PILHA_H

typedef struct Celula* apontador;
typedef struct Celula{
    char caractere;
    apontador pProx;
} Celula;

typedef struct pilha{
    apontador pTopo;
    int tamanho;
}Pilha;

void FPVazia(Pilha *pilha);
int PEhVazia(Pilha *pilha);
void PEmpilha(Pilha *pilha, char caractere);
char PDesempilha(Pilha *pilha);
int PTamanho(Pilha *pilha);

#endif