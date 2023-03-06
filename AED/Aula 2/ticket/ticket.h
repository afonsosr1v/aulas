#ifndef TICKET_H_
#define TICKET_H_

typedef struct _carro * carro;

carro criarCarro(char mat[9]);

void apagaCarro(carro a);

void daInicio(carro a, int inicioH, int inicioM);

void daFim(carro a, int fimH, int fimM);

int tempoFinal(int inicioH, int inicioM, int fimH, int fimM);



//void tempoFinal(carro a);

#endif