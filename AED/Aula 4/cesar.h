#ifndef CESAR_H_INCLUDED
#define CESAR_H_INCLUDED

typedef struct _cifra * cifra;

cifra criarCifra(char *msg, int deslocamento, int linhas);

void atualizarMensagem(cifra c);

void destroiCifra(cifra c);

void apresentarResultado(cifra c);

char * passarMensagem(cifra c);


#endif