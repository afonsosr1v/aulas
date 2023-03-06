#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "intTAD.h"
#include "iterador.h"
#include "sequencia.h"

#include "ticket.h"
#include "parque.h"

#define SIZEMAT 9
#define CAP 100

void interpretador(sequencia t);
void adicionaCarro(sequencia t);
void removeCarro(sequencia t);
void listaParque(sequencia t);
void saida(sequencia t);
char* matricula(myint a);
void consultaDinheiro(sequencia t);

int main(void) {
    sequencia t = criaSequencia(CAP);
    interpretador(t);
    destroiSeqElems(t);
    return 0;
}

void interpretador(sequencia t) {
    char cmd;
    

    while(cmd!='P'){
        scanf(" %c", &cmd);
        switch(cmd) {
            case 'e' : adicionaCarro(t); break;
            case 's' : removeCarro(t); break;
            case 'l' : listaParque(t); break;
            case 'c' : consultaDinheiro(t); break;
            case 'x' : saida(t); break;
            default : printf("Comando invalido.\n"); break;
        }
    }
}

/* carro lerCarro(parque t, char mat[9]) {
    int pos = posParque(t, mat);
    if(pos==-1) {
        printf("Carro nao existe no parque.\n");
    }
    else {
    return t->carros[pos];
    }
} */

void adicionaCarro(sequencia t) {
    int inicioH, inicioM;
    char mat[9];
    carro a;
    if(scanf("%s %d:%d", mat, &inicioH, &inicioM)!=3) {
        printf("Dados invalidos.\n");
    }
    else {
        if (adicionaPosSequencia(t, mat)!=1) {
            printf("Carro ja no parque.\n");
        }
        else {
            a = adicionaCarros(t, mat);
            daInicio(a, inicioH, inicioM);
            printf("Entrada autorizada.\n");
        }
    
    }
}

void removeCarro(sequencia t) {
    int fimH, fimM;
    char mat[9];
    float caixa;
    carro a;
    // printf("%s\n %d\n %d\n", a->mat, a->inicioH, a->inicioM);
    if (scanf("%s %d:%d", mat, &fimH, &fimM)!=3)
        printf("Dados invalidos.\n");
    else {
        a = removeCarroParque(t, mat);
        if (a == NULL) {
            printf("Carro nao existe no parque.\n");
        }
        else {
        daFim(a, fimH, fimM);
        caixa = aPagar(t, a);
        printf("Carro com matricula %s deve pagar %.2f euros.\n", mat, caixa);
        a = destroiGenInt(t, mat);
        destroiInt(a);
        }
    }
}

void listaParque(sequencia t) {
    int i = 1;
    int cont = daTamanhoParque(t);
    carro a;
    if (t->numElems==0) {
        printf("Parque sem carros.\n");
    }
    else {
        for (; i <=cont; i++){
            a = elementoPosSequencia(t, i);
            printf("Matricula: %s\n", matricula(a));
        }
    }
}

void consultaDinheiro(sequencia t) {
    printf("Dinheiro em caixa : %.2f euros.\n", t->caixa);
    
}

int sair(){
    exit(0);
}

void saida(sequencia t) {
    consultaDinheiro(t);
    printf("%d carros no parque.\n", t->numCarros);
    sair();
}
