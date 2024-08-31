#include "headers/leituraReceitas.h"

void execucao(MaquinaDeEstadosAFD *maquinaAF, MaquinaDeEstadosAP *maquinaAP, int tipoAutomato);


int main(){
    MaquinaDeEstadosAFD maquinaAFD;
    MaquinaDeEstadosAP maquinaAP;
    int opcao;
    printf("Informe o tipo de automato a ser lido:\n");
    printf("Automato finito\t\t%d\n", AFD);
    printf("Automato de pilha\t%d\n", AP);
    printf("Digite a opcao escolhida: ");
    scanf("%d", &opcao);
    
    execucao(&maquinaAFD, &maquinaAP, opcao);

    return 0;
}

void execucao(MaquinaDeEstadosAFD *maquinaAF, MaquinaDeEstadosAP *maquinaAP, int tipoAutomato){
    char ingrediente,simOuNao;  
    int controle = 0;
    //realiza a leitura 
    if(tipoAutomato == AFD) leArquivo(maquinaAF, maquinaAP, "receitas/entrada.txt", AFD);    
    else if(tipoAutomato == AP) leArquivo(maquinaAF, maquinaAP, "receitas/pocao do amor.txt", AP);

    printf("Insira o símbolo do primeiro ingrediente da receita: ");
    scanf(" %c", &ingrediente);
    fazerTransicao(maquinaAF, maquinaAP, ingrediente, "teste", tipoAutomato);

    while(controle == 0){
        printf("\nDeseja inserir mais um ingrediente(s/n)?\n");
        scanf(" %c", &simOuNao);
        
        //usuario digita s
        if(simOuNao == 's' || simOuNao == 'S'){
            printf("Qual ingrediente será inserido: ");
            scanf(" %c", &ingrediente);
            fazerTransicao(maquinaAF, maquinaAP, ingrediente, "teste", tipoAutomato);

        // usuario digita n
        }else if (simOuNao != 's' && simOuNao != 'S'){
            resultado(maquinaAF, maquinaAP, tipoAutomato);
            printf("Programa Encerrado !!!!");
            controle = 1;
        }
    }   
}