#include <stdlib.h>
#include "iterador.h"
#include "sequencia.h"

/* Estrutura de dados: sequencia implementada em vector */
struct _sequencia{
	void * * elems; // apontador para vector de enderecos de elementos
	int numElems;
	int capacidade; // capacidade corrente do vector
};


sequencia criaSequencia(int cap){
	sequencia s = malloc(sizeof(struct _sequencia));
    if (s==NULL) return NULL;
    s->numElems = 0;
    s->capacidade = cap;
    s->elems = {0};
    return s;
}

void destroiSequencia (sequencia s ){
    free(s);
}


void destroiSeqElems(sequencia s, void (*destroi)(void *) ){
	free(s->elems);
}


int vaziaSequencia(sequencia s){
	//Fazer
}


int tamanhoSequencia(sequencia s){
	//Fazer
}


void * elementoPosSequencia(sequencia s, int i){
	//Fazer
}


void adicionaPosSequencia(sequencia s, void * elem, int i){
	//Fazer
}


void * removePosSequencia(sequencia s, int i){
	//Fazer
}


iterador iteradorSequencia(sequencia s){
	//CUIDADO: DEVE DAR AO ITERADOR UMA COPIA DO VECTOR A PERCORRER
	//Fazer
}