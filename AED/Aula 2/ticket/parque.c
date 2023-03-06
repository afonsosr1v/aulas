#include "ticket.h"
#include "parque.h"

#include <stdlib.h>
#include <string.h>

#define CAP 150
#define SIZEMAT 9

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

parque criaParque(){
    parque t = (parque) malloc(sizeof(struct _parque));
    if (t==NULL) return NULL;
    t->carros = (carro *) malloc (sizeof(carro) * CAP);
    if (t->carros == NULL) {
        free(t);
        return NULL;
    }
    t->numCarros = 0;
    t->capacidade = CAP;
    t->caixa=0;
    return t;
}

char * matricula(carro a){
    return a->mat;
}

void apagaParque(parque t){
    free (t->carros);
    free (t);
}

void apagaParqueECarros(parque t){
    int i = 0;
    for(;i<t->numCarros; i++)
        apagaCarro(t->carros[i]);
    free(t->carros);
    free(t);
}

int posParque(parque t, char mat[9]) {
    int pos =-1, i=0;
    while((i< t->numCarros)&&(pos==-1)){
        if (strcmp(mat, matricula(t->carros[i]))==0)
            pos = i;
        else{
            i++;
        }
    }
    return pos;
}

void incCapacidadeParque(parque t) {
    int i = 0;
    carro * aux = (carro *) malloc(sizeof(carro)* t->capacidade * 2);
    for (;i<t->numCarros;i++)
        aux[i]=t->carros[i];
    free(t->carros);
    t->carros = aux;
    t->capacidade = t->capacidade * 2;
}

int existeCarroParque(parque t, char mat[9]) {
    //int pos = posParque(t, mat);
    if (posParque(t, mat) == -1)
        return 0;
    return 1;
}

int adicionaCarroParque(parque t, char mat[9]) {
    if(existeCarroParque(t, mat)==1)
        return 0;
    if(t->numCarros == t->capacidade)
        incCapacidadeParque(t);
    t->carros[t->numCarros++]=criarCarro(mat);
    return 1;
}

void atras(int pos, parque t) {
    int i;
    i = pos;
    for(i=pos; i<=t->numCarros; i++) {
        t->carros[pos] = t->carros[pos+1];
    }
}


carro removeCarroParque(parque t, char mat[9]) {
    carro a;
    int i;
    int pos = posParque(t, mat);
    if(pos==-1) return NULL;
    a=t->carros[pos];
    i=pos;
    for(i=pos;i<=t->numCarros;i++) {
    t->carros[i]=t->carros[i+1];
    }
    //t->carros[pos] = criarCarro(mrd);
    // atras(pos, t);
    t->numCarros--;
    return a;
}

carro adicionaCarros(parque t, char mat[9]) {
    carro a;
    int pos = posParque(t, mat);
    if(pos==-1) return NULL;
    a=t->carros[pos];
   /* t->carros[pos]=t->carros[t->numCarros-1]; */
    // t->numCarros++
    return a;
}

int daTamanhoParque(parque t) {
    return t->numCarros;
}

carro daCarroPosParque(parque t, int i) {
    return t->carros[i-1];
}

float aPagar(parque t, carro a) {
    float valor;
    int fimH=a->fimH;
    int fimM=a->fimM;
    int inicioH=a->inicioH;
    int inicioM=a->inicioM;

    int estadia = tempoFinal(inicioH, inicioM, fimH, fimM);

    if (estadia==1) {
        valor = 1.5;
    }
    else {
            if((estadia==2)||(estadia==3)){
                valor = 1.5 + (estadia-1)*1;
            }
            else {
                valor = 3.5 + (estadia-3)*0.75;
            }
    }
    t->caixa=t->caixa+valor;
    return valor;
}