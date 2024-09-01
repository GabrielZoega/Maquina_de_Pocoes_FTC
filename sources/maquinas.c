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
    alocaEstadosAP(maquina, numEstados);
    alocaTransicoesAP(maquina, numTransicoes);
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
    strcpy(maquina->estadoAtual, maquina->estadoInicial);
}

void alocaEstadosAP(MaquinaDeEstadosAP *maquina, int numEstados){
    maquina->estados = (char**) malloc (sizeof(char*) * numEstados);
    for(int i = 0; i < numEstados; i++){
        maquina->estados[i] = (char*) malloc(sizeof(char) * TAM_ESTADO);
        strcpy(maquina->estados[i], "");
    }
    strcpy(maquina->estadoAtual, maquina->estadoInicial);
}

void alocaTransicoes(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, int numTransicoes, int tipoAutomato){
	if(tipoAutomato == AFD) alocaTransicoesAF(maquinaAFD, numTransicoes);
	else if(tipoAutomato == AP) alocaTransicoesAP(maquinaAP, numTransicoes);
}

void alocaTransicoesAF(MaquinaDeEstadosAFD *maquina, int numTransicoes){
    maquina->numTransicoes = numTransicoes;
    maquina->transicoes = (Transicao*) malloc(sizeof(Transicao) * numTransicoes);
    for(int i = 0; i < numTransicoes; i++){
        maquina->transicoes[i].caracterDeEntrada = '\0';
        strcpy(maquina->transicoes[i].estadoDeDestino, "");
        strcpy(maquina->transicoes[i].estadoDePartida, "");
    }
}

void alocaTransicoesAP(MaquinaDeEstadosAP *maquina, int numTransicoes){
    maquina->numTransicoes = numTransicoes;
    maquina->transicoesP = (TransicaoP*) malloc (sizeof(TransicaoP) * numTransicoes);
    for(int i = 0; i < numTransicoes; i++){
        maquina->transicoesP[i].transicao.caracterDeEntrada = '\0';
        strcpy(maquina->transicoesP[i].transicao.estadoDeDestino, "");
        strcpy(maquina->transicoesP[i].transicao.estadoDePartida, "");
        maquina->transicoesP->charDesempilha = '\0';
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

void adicionaTransicao(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char *estadoPartida, char *estadoDestino,
char caractereEntrada, int indice, int tipoAutomato, char *caractereEmpilha, char caractereDesempilha){

	if(tipoAutomato == AFD) adicionaTransicaoAF(maquinaAFD, estadoPartida, estadoDestino, caractereEntrada, indice);
	else if(tipoAutomato == AP) adicionaTransicaoAP(maquinaAP, estadoPartida, estadoDestino, caractereEntrada, indice, caractereEmpilha, caractereDesempilha);
}

void adicionaTransicaoAF(MaquinaDeEstadosAFD *maquina, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice){
    maquina->transicoes[indice].caracterDeEntrada = caractereEntrada;
    strcpy(maquina->transicoes[indice].estadoDeDestino, estadoDestino);
    strcpy(maquina->transicoes[indice].estadoDePartida, estadoPartida);
}

void adicionaTransicaoAP(MaquinaDeEstadosAP *maquina, char *estadoPartida, char *estadoDestino, char caractereEntrada, int indice, char *caractereEmpilha, char caractereDesempilha){
    maquina->transicoesP[indice].transicao.caracterDeEntrada = caractereEntrada;
    strcpy(maquina->transicoesP[indice].transicao.estadoDeDestino, estadoDestino);
    strcpy(maquina->transicoesP[indice].transicao.estadoDePartida, estadoPartida);
    maquina->transicoesP[indice].charDesempilha = caractereDesempilha;
    maquina->transicoesP[indice].charEmpilha = (char*) malloc (sizeof(char) * strlen(caractereEmpilha));
    for(int k = 0; k < strlen(caractereEmpilha); k++){
        maquina->transicoesP[indice].charEmpilha[k] = caractereEmpilha[k]; // tem que conferir onde tá alocando o espaço pra esses caracteres de entrada.
    }
}

void fazerTransicao(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, char caractereEntrada, int tipoAutomato){
	if(tipoAutomato == AFD) fazerTransicaoAFD(caractereEntrada, maquinaAFD);
	else if(tipoAutomato == AP) fazerTransicaoAPD(caractereEntrada, maquinaAP);
}

void fazerTransicaoAFD(char caractereEntrada, MaquinaDeEstadosAFD *maquina){
    int fezTransicao = 0;
    for(int i = 0; i < maquina->numTransicoes; i++){
        
        if((strcmp(maquina->transicoes[i].estadoDePartida, maquina->estadoAtual) == 0) && (maquina->transicoes[i].caracterDeEntrada == caractereEntrada)){
            strcpy(maquina->estadoAtual, maquina->transicoes[i].estadoDeDestino);
            printf(TEXT_COLOR_256("197")  "Transição: ");
            printf("%s -> ",maquina->transicoes[i].estadoDePartida);
            printf("%s\n" RESET, maquina->transicoes[i].estadoDeDestino);
            fezTransicao = 1;
            break;
        }
    }
    if(fezTransicao == 0){
        printf(TEXT_COLOR_256("197")  "Transição: ");
        printf("%s -> ",maquina->estadoAtual);
        printf("erro\n" RESET);
        strcpy(maquina->estadoAtual, "erro");
    }
}

void fazerTransicaoAPD(char caractereEntrada, MaquinaDeEstadosAP* maquina){
    char caractereDesempilha;
    int fezTransicao = 0;
    for(int i = 0; i < maquina->numTransicoes; i++){
        caractereDesempilha = PDesempilha(&maquina->stack);
        PEmpilha(&(maquina->stack), caractereDesempilha);

        if((strcmp(maquina->transicoesP[i].transicao.estadoDePartida, maquina->estadoAtual) == 0)
        && (maquina->transicoesP[i].transicao.caracterDeEntrada == caractereEntrada)
        && ((maquina->transicoesP[i].charDesempilha == caractereDesempilha) || (maquina->transicoesP[i].charDesempilha == '\0'))){
            
            PDesempilha(&(maquina->stack));
            for(int j = 0; j < strlen(maquina->transicoesP[i].charEmpilha);j++){
                PEmpilha(&(maquina->stack), maquina->transicoesP[i].charEmpilha[j]);
                imprimeReacao(maquina->transicoesP[i].charEmpilha[j]);
            }
            strcpy(maquina->estadoAtual, maquina->transicoesP[i].transicao.estadoDeDestino);
            printf(TEXT_COLOR_256("197")  "Transição: ");
            printf("%s -> ",maquina->transicoesP[i].transicao.estadoDePartida);
            printf("%s\n" RESET, maquina->transicoesP[i].transicao.estadoDeDestino);
            fezTransicao = 1;
            break;
        }
    }
    if(fezTransicao == 0){
        printf(TEXT_COLOR_256("197")  "Transição: ");
        printf("%s -> ",maquina->estadoAtual);
        printf("erro\n" RESET);
        strcpy(maquina->estadoAtual, "erro");
    }
}

void resultado(MaquinaDeEstadosAFD *maquinaAFD, MaquinaDeEstadosAP *maquinaAP, int tipoAutomato){
	if(tipoAutomato == AFD) resultadoAFD(maquinaAFD);
	else if(tipoAutomato == AP) resultadoAP(maquinaAP);
}

void resultadoAFD(MaquinaDeEstadosAFD *maquina){
    if(strcmp(maquina->estadoFinal.nomeEstado, maquina->estadoAtual) == 0){
        printf("%s criada!\n", maquina->estadoFinal.nomePocao);
    
    }else{
        printf("Erro na mistura\n");
    }
}

void resultadoAP(MaquinaDeEstadosAP *maquina){
    if(strcmp(maquina->estadoFinal.nomeEstado, maquina->estadoAtual) == 0){
        printf("%s criada\n", maquina->estadoFinal.nomePocao);
    
    }else{
        printf("Erro na mistura\n");
    }
}