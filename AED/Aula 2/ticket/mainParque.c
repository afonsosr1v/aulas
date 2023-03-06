#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "ticket.h"
#include "parque.h"

#define SIZEMAT 9

void interpretador(parque t);
void adicionaCarro(parque t);
void removeCarro(parque t);
void listaParque(parque t);
void saida(parque t);
char* matricula(carro a);
void consultaDinheiro(parque t);

struct _parque{
    carro * carros;
    int numCarros;
    int capacidade;
    float caixa;
};

struct _carro{
    char mat[SIZEMAT];
    int inicioH, inicioM;
    int fimH, fimM;
    int estadia;
};

int main(void) {
    parque t = criaParque();
    interpretador(t);
    apagaParqueECarros(t);
    return 0;
}

void interpretador(parque t) {
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

void adicionaCarro(parque t) {
    int inicioH, inicioM;
    char mat[9];
    carro a;
    if(scanf("%s %d:%d", mat, &inicioH, &inicioM)!=3) {
        printf("Dados invalidos.\n");
    }
    else {
        if (adicionaCarroParque(t, mat)!=1) {
            printf("Carro ja no parque.\n");
        }
        else {
            a = adicionaCarros(t, mat);
            daInicio(a, inicioH, inicioM);
            printf("Entrada autorizada.\n");
        }
    
    }
}

void removeCarro(parque t) {
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
        a = removeCarroParque(t, mat);
        apagaCarro(a);
        }
    }
}

void listaParque(parque t) {
    int i = 1;
    int cont = daTamanhoParque(t);
    carro a;
    if (t->numCarros==0) {
        printf("Parque sem carros.\n");
    }
    else {
        for (; i <=cont; i++){
            a = daCarroPosParque(t, i);
            printf("Matricula: %s\n", matricula(a));
        }
    }
}

void consultaDinheiro(parque t) {
    printf("Dinheiro em caixa : %.2f euros.\n", t->caixa);
    
}

int sair(){
    exit(0);
}

void saida(parque t) {
    consultaDinheiro(t);
    printf("%d carros no parque.\n", t->numCarros);
    sair();
}
