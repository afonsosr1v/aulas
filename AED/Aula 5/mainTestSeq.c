#include <stdio.h>
#include <stdlib.h>

#include "intTAD.h"
#include "iterador.h"
#include "sequencia.h"

#define MAXSEQ 10

void listaInteiros(sequencia s){
    iterador myIt;
    myint val;

    printf("Elementos: ");
    myIt = iteradorSequencia( s );
	while (temSeguinteIterador( myIt )){
		val = (myint)seguinteIterador( myIt );
		printf(" %d  ",  valorInt(val));
	}
	printf("\n");
	destroiIterador(myIt);
}

int main(){
	sequencia mySeq;
	int dimSequencia;
	myint val;
	int valor;
	int pos;

	mySeq = criaSequencia(MAXSEQ);
	printf("Criou sequencia\n");

	valor = 1;
	val = criaInt(valor);
	adicionaPosSequencia( mySeq , val , 1 );

	valor = 2;
	val = criaInt(valor);
	adicionaPosSequencia( mySeq , val , 2 );

	valor = 3;
	val = criaInt(valor);
	adicionaPosSequencia( mySeq , val , tamanhoSequencia(mySeq)+1 );

	valor = 4;
	val = criaInt(valor);
	adicionaPosSequencia( mySeq , val , tamanhoSequencia(mySeq)+1 );
    listaInteiros(mySeq);


	valor = 5;
	val = criaInt(valor);
	pos = 2;
	adicionaPosSequencia( mySeq , val , 2 );
	printf("Adicionei %d na posicao %d\n",valor, pos);

	dimSequencia = tamanhoSequencia( mySeq );
	printf("A sequencia tem %d elementos\n", dimSequencia);
    listaInteiros(mySeq);

	val = elementoPosSequencia( mySeq, 3 );
	printf(" %d\n", valorInt(val));

    pos = 3;
	val = removePosSequencia( mySeq, pos);
	dimSequencia = tamanhoSequencia( mySeq );
	printf("Retirei <%d> da posicao %d, a sequencia tem %d elementos\n",valorInt(val),pos,dimSequencia);
    listaInteiros(mySeq);


	val = elementoPosSequencia( mySeq, 3 );
	printf(" %d\n", valorInt(val));


	val = (myint)removePosSequencia( mySeq, tamanhoSequencia(mySeq) );
	printf("Retirei o da ultima posicao %d\n", valorInt(val));

	listaInteiros(mySeq);
	destroiSeqElems ( mySeq , destroiGenInt);
	printf("Destrui a sequencia e os elementos\n");

	return 0;
}
