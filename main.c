#include "headers/leituraReceitas.h"


int main(){
    MaquinaDeEstadosAFD maquinaAFD;
    MaquinaDeEstadosAP maquinaAP;

    leArquivo(&maquinaAFD, &maquinaAP, "receitas/entrada.txt", AFD);
    return 0;
}
