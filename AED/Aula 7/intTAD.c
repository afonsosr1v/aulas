#include <stdlib.h>
#include "intTAD.h"

struct _myint{
    int num;
};


myint criaInt(int valor) {
	myint m =(myint)malloc(sizeof(struct _myint));

	if (m==NULL) return NULL;
	m->num = valor;

	return m;
}

int valorInt(myint m){
    return m->num;
}

void destroiInt( myint m ) {
	free(m);
}

void destroiGenInt( void * m ) {
    destroiInt((myint) m);
}
