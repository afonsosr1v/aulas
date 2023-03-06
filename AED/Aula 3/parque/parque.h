#ifndef PARQUE_H_
#define PARQUE_H_

typedef struct _carro* carro;

carro criarCarro(char mat[9]);

void daInicio(carro a, int inicioH, int inicioM);

void daFim(carro a, int fimH, int fimM);

int tempoFinal(carro a);

int pagar(carro a);

void lista(void);

void dinheiro();


#endif