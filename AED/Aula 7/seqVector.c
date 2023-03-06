#include <stdlib.h>
#include "iterador.h"
#include "sequencia.h"

/* Estrutura de dados: sequencia implementada em vector */
struct _sequencia{
	void * * elems; // apontador para vector de enderecos de elementos - o primeiro asterisco mostra que a variável é do tipo (void *), o segundo apenas indica que é um vetor do tipo void *
	int numElems;
	int capacidade; // capacidade corrente do vector
};


sequencia criaSequencia(int cap){
	sequencia s = (sequencia) malloc(sizeof(struct _sequencia));
	if(s==NULL)
        return NULL;
    s->elems = malloc(sizeof(void *) * cap);
    if(s->elems == NULL){
        free(s);
        return NULL;
    }
    s->numElems = 0;
    s->capacidade = cap;
    return s;

}


void destroiSequencia (sequencia s ){
	free(s->elems);
	free(s);
}


void destroiSeqElems(sequencia s, void (*destroi)(void *) ){
	int i;

	for(i=0; i<s->numElems; i++){
        destroi(s->elems[i]);
	}
    free(s->elems);
	free(s);
}


int vaziaSequencia(sequencia s){
	if(s->numElems == 0)
        return 1;
    return 0;
}


int tamanhoSequencia(sequencia s){
	return s->numElems;
}


void * elementoPosSequencia(sequencia s, int i){
	return s->elems[i-1];
}


//Funçao auxiliar no caso de os elementos excederem a capacidade predefinida
void incSequencia(sequencia s) {
    void ** aux = malloc(sizeof(void *) * s->capacidade*2);
    int i;

    for(i=0; i<s->numElems; i++) {
        aux[i] = s->elems[i];
    }
    free(s->elems);
    s->elems = aux;
    s->capacidade *= 2;

}

void adicionaPosSequencia(sequencia s, void * elem, int i){
	int j;

	if(s->capacidade == s->numElems){
        incSequencia(s);
	}

	for(j=s->numElems; j>=i; j--){
        s->elems[j] = s->elems[j-1];
	}
	s->elems[i-1] = elem;
	s->numElems++;
}


void * removePosSequencia(sequencia s, int i){
	int k;
	void * aux = s->elems[i-1];

	for(k=i; k<s->numElems; k++) {
        s->elems[k-1] = s->elems[k];
	}

	s->numElems--;
	return aux;
}


iterador iteradorSequencia(sequencia s){
	//CUIDADO: DEVE DAR AO ITERADOR UMA COPIA DO VECTOR A PERCORRER
	void ** aux = malloc(sizeof(void *) * s->numElems);
    int i;

    for(i=0; i<s->numElems; i++) {
        aux[i] = s->elems[i];
    }

    return criaIterador(aux, s->numElems);

}
