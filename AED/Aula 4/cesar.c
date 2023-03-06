#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "cesar.h"

#define MAX_MSG 100
#define MAX_LINHAS 100

struct _cifra {
    char mensagem[MAX_MSG];
    char mensagem_cifrada[MAX_MSG];
    int codigo;
    int linhas;
};

cifra criarCifra(char * msg, int deslocamento, int linhas) {
    cifra c;
    c = (cifra) malloc(sizeof(struct _cifra));
    if (c==NULL)
        return NULL;
    strcpy(c->mensagem, msg);
    c->codigo = deslocamento;
    c->linhas = linhas;
    
    return c;
}

/* void atualizarMensagem(cifra c){

    for(int i=0; i<=strlen(c->mensagem);i++) {
        if(c->mensagem[i]>='a' && c->mensagem[i]<='z') {
            c->mensagem_cifrada[i] = c->mensagem[i] + c-> codigo;
            if(c->mensagem_cifrada[i]>'z') {
                c->mensagem_cifrada[i] -= 26;
            }
        }
        else {
            c->mensagem_cifrada[i] = c->mensagem[i];
        }
    }
}*/

int lenHelper(unsigned x) {
    if (x >= 1000000000) return 10;
    if (x >= 100000000)  return 9;
    if (x >= 10000000)   return 8;
    if (x >= 1000000)    return 7;
    if (x >= 100000)     return 6;
    if (x >= 10000)      return 5;
    if (x >= 1000)       return 4;
    if (x >= 100)        return 3;
    if (x >= 10)         return 2;
    return 1;
}



void atualizarMensagem(cifra c) {
    //printf("%s", c->mensagem);
    int codigo[10] = {};
    int j=lenHelper(c->codigo);
    int jinicial = j;
    j=jinicial-1;

    for(j=jinicial-1;j>=0;j--) {
        codigo[j]=c->codigo%10;
        c->codigo /= 10;
        //printf("%d", codigo[j]);
    }

    j=0;
    for(int i=0; i<=strlen(c->mensagem); i++) {
        if(c->mensagem[i]>='a' && c->mensagem[i]<='z') {
            c->mensagem_cifrada[i] = c->mensagem[i] + codigo[j];
            if(c->mensagem_cifrada[i]>'z') {
                c->mensagem_cifrada[i] -= 26;
            }
        }
        else {
             c->mensagem_cifrada[i] = c->mensagem[i];
        }
        j++;
        if(j==jinicial) {
                j=0;
        }
    }
}


void destroiCifra(cifra c){
    free(c);
}

char * passarMensagem(cifra c){
    return c->mensagem_cifrada;
}


