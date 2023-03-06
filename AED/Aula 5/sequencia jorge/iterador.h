#ifndef _H_ITERADOR
#define _H_ITERADOR

/* Tipo de dados: iterador */
typedef struct _iterador * iterador;

/* Prototipos das funcoes associadas a um iterador */

/***********************************************
criaIterador - Criacao da instancia da estrutura associada a um iterador para um vector com n elementos.
Parametros:
	vector - endereco da copia do vector a iterar
	n - numero de elementos no vector
Retorno: apontador para a  instancia criada
Pre-condicoes:  vector != NULL && n > 0
***********************************************/
iterador criaIterador(void ** vector, int n);

/***********************************************
destroiIterador - Liberta a memoria ocupada pela instancia da estrutura associada ao iterador.
Parametros:
	it - iterador a destruir
Retorno:
Pre-condicoes: it != NULL
***********************************************/
void destroiIterador (iterador it);

/***********************************************
temSeguinteIterador - Indica se existe mais elementos para iterar no iterador.
Parametros:
	it - iterador
Retorno: 1- caso exista mais elementos; 0- caso contrario
Pre-condicoes: it != NULL
***********************************************/
int temSeguinteIterador(iterador it);

/***********************************************
seguinteIterador - Consulta o seguinte elemento no iterador.
Parametros:
	it - iterador
Retorno: enderco do elemento
Pre-condicoes: it != NULL && temSeguinteIterador(it) == 1
***********************************************/
void * seguinteIterador(iterador it);

#endif

