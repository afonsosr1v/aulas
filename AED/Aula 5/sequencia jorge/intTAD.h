#ifndef INTTAD_H_
#define INTTAD_H_

/* Tipo de dados: myint */
typedef struct _myint * myint;

/***********************************************
criaInt - Criacao da instancia da estrutura associada ao tipo myint.
Parametros: valor do inteiro
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
myint criaInt(int valor);

/***********************************************
valorInt - consulta o valor inteiro do myint.
Parametros: m - myint do qual se quer consultar o valor inteiro
Retorno: enderco do elemento
Pre-condicoes:
***********************************************/
int valorInt(myint m);


/***********************************************
destroiInt - Liberta a memoria ocupada pela instancia da estrutura associada ao tipo myint.
Parametros: elemento myint a ser destruido
Retorno:
Pre-condicoes: m!=NULL
***********************************************/
void destroiInt(myint m);

/***********************************************
destroiGenInt - Liberta a memoria ocupada pela instancia da estrutura associada ao tipo myint.
Parametros: elemento myint a ser destruido
Retorno:
Pre-condicoes: m!=NULL
***********************************************/
void destroiGenInt(void * m);

#endif /*INTTAD_H_*/
