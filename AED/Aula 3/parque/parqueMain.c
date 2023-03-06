#include <stdio.h>
#include <stdlib.h>
#include "parque.h"

#define SIZEMAT 9

struct _carro{
    char mat[SIZEMAT];
    int inicioH, inicioM;
    int fimH, fimM;
    int estadia;
    int valor;
};

int main(void) {
    char mat[SIZEMAT];
    int inicioH, inicioM, fimH, fimM;
    int estadia;
    carro a;
    char select;

    scanf(" %c", &select);
    
    switch(select) {
        case 'e' : //comando de entrada
            scanf(" %s %d:%d", mat, &inicioH, &inicioM);
            a = criarCarro(mat);
            daInicio(a, inicioH, inicioM);
            break;
        case 's' : //comando de saida
            scanf(" %s %d:%d", mat, &fimH, &fimM);
            tempoFinal(a);
            break;
        case 'l' : //comando de lista
            lista();
            break;
        case 'c' : //consultar dinheiro
            dinheiro();
            break;
        case 'x' : //saida
            return 0;
        default :
            printf("Comando invalido.\n"); break;
    }

}