#include "../headers/maquinas.h"

void inicializaAutomato(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, int numEstados, int numTransicoes, int tipoAutomato){
	if(tipoAutomato == AFD) inicializaAFD(maquinaAFD, numEstados, numTransicoes);
	else if(tipoAutomato == AP) inicializaAP(maquinaAP, numEstados, numTransicoes);
}

void inicializaAFD(MaquinaDeEstadosAFD *maquina, int numEstados, int numTransicoes){
    alocaEstadosAF(maquina, numEstados);
    alocaTransicoesAF(maquina, numTransicoes);
}

void inicializaAP(MaquinaDeEstadosAP *maquina, int numEstados, int numTransicoes){
    Pilha pilha;// nao precisa de declarar essa pilha aqui pro stack receber, pode sóusar o FPVazia direto
    alocaEstadosAP(maquina, numEstados);
    alocaTransicoesAP(maquina, numTransicoes);
    maquina->stack = pilha;
    FPVazia(&(maquina->stack));
}

void alocaEstados(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, int numEstados, int tipoAutomato){
	if(tipoAutomato == AFD) alocaEstadosAF(maquinaAFD, numEstados);
	else if(tipoAutomato == AP) alocaEstadosAP(maquinaAP, numEstados);
}

void alocaEstadosAF(MaquinaDeEstadosAFD *maquina, int numEstados){
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

void alocaTransicoes(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, int numTransicoes, int tipoAutomato){
	if(tipoAutomato == AFD) alocaTransicoesAF(maquinaAFD, numTransicoes);
	else if(tipoAutomato == AP) alocaTransicoesAP(maquinaAP, numTransicoes);
}

void alocaTransicoesAF(MaquinaDeEstadosAFD *maquina, int numTransicoes){
    maquina->transicoes = (Transicao*) malloc(sizeof(Transicao) * numTransicoes);
    for(int i = 0; i < numTransicoes; i++){
        maquina->transicoes[i].caracterDeEntrada = '\0';
        strcpy(maquina->transicoes[i].estadoDeDestino, "");
        strcpy(maquina->transicoes[i].estadoDePartida, "");
    }
}

void alocaTransicoesAP(MaquinaDeEstadosAP *maquina, int numTransicoes){
    maquina->transicoesP = (TransicaoP*) malloc (sizeof(TransicaoP) * numTransicoes);
    for(int i = 0; i < numTransicoes; i++){
        maquina->transicoesP[i].transicao.caracterDeEntrada = '\0';
        strcpy(maquina->transicoesP[i].transicao.estadoDeDestino, "");
        strcpy(maquina->transicoesP[i].transicao.estadoDePartida, "");
        maquina->transicoesP->charDesempilha = '\0';
        maquina->transicoesP->charEmpilha = '\0';
    }
}

void adicionaEstado(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *estado, int indice, int tipoAutomato){
	if(tipoAutomato == AFD) adicionaEstadoAF(maquinaAFD, estado, indice);
	else if(tipoAutomato == AP) adicionaEstadoAP(maquinaAP, estado, indice);
}

void adicionaEstadoAF(MaquinaDeEstadosAFD *maquina, char *estado, int indice){
    strcpy(maquina->estados[indice], estado);
}

void adicionaEstadoAP(MaquinaDeEstadosAP *maquina, char *estado, int indice){
    strcpy(maquina->estados[indice], estado);
}

void adicionaTransicao(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice, int tipoAutomato){
	if(tipoAutomato == AFD) adicionaTransicaoAF(maquinaAFD, estadoPartida, estadoDestino, caractereEntrada, indice);
	else if(tipoAutomato == AP) adicionaTransicaoAP(maquinaAP, estadoPartida, estadoDestino, caractereEntrada, indice);
}

void adicionaTransicaoAF(MaquinaDeEstadosAFD *maquina, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice){
    maquina->transicoes[indice].caracterDeEntrada = caractereEntrada;
    strcpy(maquina->transicoes[indice].estadoDeDestino, estadoDestino);
    strcpy(maquina->transicoes[indice].estadoDePartida, estadoPartida);
}

void adicionaTransicaoAP(MaquinaDeEstadosAP *maquina, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice){
    maquina->transicoesP[indice].transicao.caracterDeEntrada = caractereEntrada;
    strcpy(maquina->transicoesP[indice].transicao.estadoDeDestino, estadoDestino);
    strcpy(maquina->transicoesP[indice].transicao.estadoDePartida, estadoPartida);
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
    for(int i = 0; i < maquina->numTransicoes; i++){ //aqui vcs estavam tratando transicoesP como ponteiro direto, sendo que ele é um vetor, aí eu mudei pro jeito que eu acho que estaria certo
        if((strcmp(maquina->transicoesP[i].transicao.estadoDePartida, maquina->estadoAtual) == 0)
        && (maquina->transicoesP[i].transicao.caracterDeEntrada == caractereEntrada)
        && (maquina->transicoesP[i].charEmpilha == caractereEmpilha)){ // aqui eu nao sei se charEmpilha era pra ser um vetor ou nao, se não for vai ter que tirar o ponteiro la nos parametros,
        	//se for e vcs querem comparar com todos os caracteres do vetor com o charEmpilha, aí vcs podem usar um for de 0 até strlen(caracterEmpilha) com um if dentro dele comparando
            if(maquina->stack.pTopo->caractere == caractereDesempilha){
                PDesempilha(&(maquina->stack));
            }
            for(int j = 0; j < strlen(caractereEmpilha);j++){
                PEmpilha(&(maquina->stack),caractereEmpilha[j]);
            }
            strcpy(maquina->estadoAtual, maquina->transicoesP[i].transicao.estadoDeDestino);
                
            if(strcmp(maquina->estadoAtual, "erro") == 0) printf("Erro na mistura\n");
            if(strcmp(maquina->estadoAtual, maquina->estadoFinal) == 0 && (PEhVazia(&maquina->stack))) printf("%s\n", nomePocao);
        }
    }  
}
//transicao(e,a,b) e transicao(e',a',b') são compatíveis <=> 
//((a=a')or(a=lambda) or a'=lambda) and(b=b' or b = lambda or b' = lambda))
//e, e' são estados; a,a' são entradas; b,b' desempilha de cada transição
