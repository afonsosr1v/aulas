#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket.h"

#define SIZEMAT 9

struct _carro{
    char mat[SIZEMAT];
    int inicioH, inicioM;
    int fimH, fimM;
    int estadia;
    int valor;
};

carro criarCarro(char* mat) {
    carro a;
        a = (carro) malloc(sizeof(struct _carro));
        if (a==NULL) return NULL;
        strcpy(a->mat, mat);
        a->inicioH = 0;
        a->inicioM = 0;
        a->fimH = 0;
        a->fimM = 0;
        a->estadia = 0;
    
    return a;
    
}

void daInicio(carro a, int inicioH, int inicioM) {
    a->inicioH = inicioH;
    a->inicioM = inicioM;
}

void daFim(carro a, int fimH, int fimM) {
    a->fimH = fimH;
    a->fimM = fimM;
}

