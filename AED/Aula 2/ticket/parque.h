#ifndef _H_PARQUE
#define _H_PARQUE

typedef struct _parque * parque;

parque criaParque();

char* matricula(carro a);

void apagaParque(parque t);

void apagaParqueECarros(parque t);

int existeCarroParque(parque t, char mat[9]);

int daCarroParque(parque t, char mat[9]);

int adicionaCarroParque(parque t, char mat[9]);

carro adicionaCarros(parque t, char mat[9]);

float aPagar(parque t, carro a);

void incCapacidadeParque(parque t);

carro removeCarroParque(parque t, char mat[9]);

int daTamanhoParque(parque t);

carro daCarroPosParque(parque t, int i);

carro lerCarro(parque t, char mat[9]);

int posParque(parque t, char mat[9]);

int sair();

void atras(int pos, parque t);

#endif