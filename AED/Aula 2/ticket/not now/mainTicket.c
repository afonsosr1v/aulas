#include <stdio.h>

#include "ticket.h"

#define SIZEMAT 9
void lerCarro(char* mat, int* inicioH, int* inicioM, int* fimH, int* fimM);
void escreverResultado(int estadia, char* mat);

struct _carro{
    char mat[SIZEMAT];
    int inicioH, inicioM;
    int fimH, fimM;
    int estadia;
};

int main(void) {
    char mat[SIZEMAT];
    int inicioH, inicioM, fimH, fimM;
    int estadia;
    carro a;

    lerCarro(mat,&inicioH,&inicioM,&fimH,&fimM);

    a = criarCarro(mat);

    daInicio(a,inicioH,inicioM);
    daFim(a,fimH,fimM);

    estadia=tempoFinal(inicioH, inicioM, fimH, fimM);
    //tempoFinal(a);

    escreverResultado(estadia, mat);

    apagaCarro(a);

    return 0;
}

void lerCarro(char* mat, int* inicioH, int* inicioM, int* fimH, int* fimM) {
    printf("Matricula: ");
    scanf(" %s", mat);
    printf("Entrada (hh:mm): ");
    scanf(" %d:%d", inicioH, inicioM);
    printf("Saida (hh:mm): ");
    scanf(" %d:%d", fimH, fimM);
}

void escreverResultado(int estadia, char* mat) {
    printf("O carro com matricula %s teve uma estadia de %d horas\n", mat, estadia);

}