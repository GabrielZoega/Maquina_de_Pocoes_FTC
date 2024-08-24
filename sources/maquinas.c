#include "../headers/maquinas.h"

void alocaEstados(MaquinaDeEstadosAFD *maquina, int numEstados){
    maquina->estados = (char**) malloc (sizeof(char*) * numEstados);
    for(int i = 0; i < numEstados; i++){
        maquina->estados[i] = (char*) malloc(sizeof(char) * TAM_ESTADO);
        strcpy(maquina->estados[i], "");
    }
    strcpy(maquina->estadoAtual, "");
    strcpy(maquina->estadoFinal, "");
    strcpy(maquina->estadoInicial, "");
}

void alocaEstadosAP(MaquinaDeEstadosAP *maquina, int numEstados){
    maquina->estados = (char**) malloc (sizeof(char*) * numEstados);
    for(int i = 0; i < numEstados; i++){
        maquina->estados[i] = (char*) malloc(sizeof(char) * TAM_ESTADO);
        strcpy(maquina->estados[i], "");
    }
    strcpy(maquina->estadoAtual, "");
    strcpy(maquina->estadoFinal, "");
    strcpy(maquina->estadoInicial, "");
}

void alocaTransicoesAF(MaquinaDeEstadosAFD *maquina, int numTransicao){
    maquina->transicoes = (Transicao*) malloc(sizeof(Transicao) * numTransicao);
    for(int i = 0; i < numTransicao; i++){
        maquina->transicoes[i].caracterDeEntrada = '\0';
        strcpy(maquina->transicoes[i].estadoDeDestino, "");
        strcpy(maquina->transicoes[i].estadoDePartida, "");
    }
}

void alocaTransicoesAP(MaquinaDeEstadosAP *maquina, int numTransicao){
    maquina->transicoesP = (TransicaoP*) malloc (sizeof(TransicaoP) * numTransicao);
    for(int i = 0; i < numTransicao; i++){
        maquina->transicoesP[i].transicao.caracterDeEntrada = '\0';
        strcpy(maquina->transicoesP[i].transicao.estadoDeDestino, "");
        strcpy(maquina->transicoesP[i].transicao.estadoDePartida, "");
        maquina->transicoesP->charDesempilha = '\0';
        maquina->transicoesP->charEmpilha = '\0';
    }
}

void inicializaAFD(MaquinaDeEstadosAFD *maquina, int numEstados, int numTransicoes){
    alocaEstados(maquina, numEstados);
    alocaTransicoesAF(maquina, numTransicoes);
}

void inicializaAP(MaquinaDeEstadosAP *maquina, int numEstados, int numTransicoes){
    Pilha pilha;
    alocaEstadosAP(maquina, numEstados);
    alocaTransicoesAP(maquina, numTransicoes);
    maquina->stack = pilha;
    FPVazia(&(maquina->stack));
}

void adicionaEstado(MaquinaDeEstadosAFD *maquina, char *estado, int indice){
    strcpy(maquina->estados[indice], estado);
}

void adicionaTransicao(MaquinaDeEstadosAFD *maquina, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice){
    maquina->transicoes[indice].caracterDeEntrada = caractereEntrada;
    strcpy(maquina->transicoes[indice].estadoDeDestino, estadoDestino);
    strcpy(maquina->transicoes[indice].estadoDePartida, estadoPartida);
}

void fazerTransicaoAFD(char caractereEntrada, MaquinaDeEstadosAFD *maquina, char *nomePocao){
    
    for(int i = 0; i < maquina->numTransicoes; i++){
        if((strcmp(maquina->transicoes->estadoDePartida, maquina->estadoAtual) == 0) && (maquina->transicoes->caracterDeEntrada == caractereEntrada)){
            strcpy(maquina->estadoAtual, maquina->transicoes->estadoDeDestino);
            if(strcmp(maquina->estadoAtual, "erro") == 0) printf("Erro na mistura\n");
            if(strcmp(maquina->estadoAtual, maquina->estadoFinal) == 0) printf("%s\n", nomePocao);
        }
    }
    
}

//TODO: vamo ter que ver como fazer essa comparação (maquina->transicoesP->charEmpilha == caractereEmpilha) pra mais de um caractere
void fazerTransicaoAPD(char caractereEntrada, char *caractereEmpilha, char caractereDesempilha, MaquinaDeEstadosAP* maquina, char *nomePocao){
    for(int i = 0; i < maquina->numTransicoes; i++){
        if((strcmp(maquina->transicoesP->transicao.estadoDePartida, maquina->estadoAtual) == 0) 
        && (maquina->transicoesP->transicao.caracterDeEntrada == caractereEntrada) 
        && (maquina->transicoesP->charEmpilha == caractereEmpilha)){ 
            if(maquina->stack.pTopo->caractere == caractereDesempilha){
                PDesempilha(&(maquina->stack));
            }
            for(int j = 0; j < strlen(caractereEmpilha);j++){
                PEmpilha(&(maquina->stack),caractereEmpilha[j]);
            }
            strcpy(maquina->estadoAtual, maquina->transicoesP->transicao.estadoDeDestino);
                
            if(strcmp(maquina->estadoAtual, "erro") == 0) printf("Erro na mistura\n");
            if(strcmp(maquina->estadoAtual, maquina->estadoFinal) == 0 && (PEhVazia(&maquina->stack))) printf("%s\n", nomePocao);
        }
    }  
}
//transicao(e,a,b) e transicao(e',a',b') são compatíveis <=> 
//((a=a')or(a=lambda) or a'=lambda) and(b=b' or b = lambda or b' = lambda))
//e, e' são estados; a,a' são entradas; b,b' desempilha de cada transição