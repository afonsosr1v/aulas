/*
 * iteraVector.c
 */

#include <stdlib.h>

#include "iterador.h"

/* Estrutura de dados do tipo de dados: iterador */
struct _iterador{
	void ** vector;
	int numElems;
	int corrente;
};

iterador criaIterador(void ** vector, int n){
	iterador it = malloc(sizeof(struct _iterador));
	if (it == NULL) return NULL;
	it->vector = vector;
	it->numElems = n;
	it->corrente = 0;
	return it;
}

void destroiIterador (iterador it){
	free(it->vector);
	free(it);
}

int temSeguinteIterador(iterador it){
	if (it->corrente == it->numElems)
		return 0;
	return 1;
}

void * seguinteIterador(iterador it){
	return it->vector[it->corrente++];
}
