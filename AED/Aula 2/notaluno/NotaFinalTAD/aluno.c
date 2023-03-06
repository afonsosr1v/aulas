#include <stdlib.h>
#include "aluno.h"

/* Constantes do TAD aluno */

#define PER_P 0.15
#define PER_T 0.45
#define PER_TP1 0.25
#define PER_TP2 0.15
#define APROVADO 10
#define CENTENAS 100
#define ARREDONDA 45

/* Estrutura de dados do TAD aluno */
struct _aluno{
	int numero;         //Numero aluno
	float p, t;         //Notas teórico-práticas
	float tp1, tp2;     //Notas trabalhos
};

/* Implementações das funcões do TAD aluno */
/***********************************************
criaAluno - Criação da instância da estrutura associada a um aluno.
Parâmetros:
	num - número de aluno
Retorno: apontador para a instância criada
Pré-condições: num > 0
***********************************************/
aluno criaAluno(int num){
	aluno a;
	a = (aluno) malloc(sizeof(struct _aluno));
	if (a == NULL) return NULL;
	a->numero = num;
	a->p = 0;
	a->t = 0;
	a->tp1 = 0;
	a->tp2 = 0;
	return a;
}

/***********************************************
apagaAluno - Liberta a memória ocupada pela instância da estrutura associada ao aluno.
Parâmetros:
	a - aluno a apagar
Retorno:
Pré-condições: a != NULL
***********************************************/
void apagaAluno(aluno a){
	free(a);
}

/***********************************************
daNotasTrabalhosAluno - Atribuição das notas dos trabalhos práticos ao aluno.
Parâmetros:
	a - aluno
	tp1 - nota trabalho 1
	tp2 - nota trabalho 2
Retorno:
Pré-condições: a != NULL && 0<=tp1<=20 && 0<=tp2<=20
***********************************************/
void daNotasTrabalhosAluno(aluno a, float tp1, float tp2){
	a->tp1 = tp1;
	a->tp2 = tp2;
}

/***********************************************
daNotasTestesAluno - Atribuição da nota teórico-prática ao aluno.
Parâmetros:
	a - aluno
	p - nota projecto
	t - nota teste
Retorno:
Pré-condições: a != NULL && 0<=t1<=20 && 0<=t2<=20
***********************************************/
void daNotasTestesAluno(aluno a, float p, float t){
	a->p = p;
	a->t = t;
}

/***********************************************
numeroAluno - Consulta o número do aluno.
Parâmetros:		a - aluno
Retorno: número do aluno
Pré-condições: a != NULL
***********************************************/
int numeroAluno(aluno a){
	return a->numero;
}

/***********************************************
notaFinalAluno - dá a nota final do aluno arredondada unidades
Parâmetros:		a - aluno
Retorno: nota final
Pré-condições: a != NULL
***********************************************/
int notaFinalAluno(aluno a){
	float nota =  a->p*PER_P + a->t*PER_T + a->tp1*PER_TP1 + a->tp2*PER_TP2;
	int resto = (int)((nota - (int) nota) * CENTENAS);
	if (resto <= ARREDONDA)
		return (int) nota;
	return (int) (nota+1);
}

/***********************************************
aprovadoAluno - Indica se o aluno obteve aprovação.
Parâmetros:		a - aluno
Retorno: 1 - caso aprovado; 0 - caso contrário
Pré-condições: a != NULL
***********************************************/
int aprovadoAluno(aluno a){
	return notaFinalAluno(a) >= APROVADO;
}

/***********************************************
igualAluno - Indica se dois alunos são o mesmo (têm o mesmo número)
Parâmetros:		a - aluno
Retorno: 0 - não; 1 - sim
Pré-condições: a1 != NULL && a2 != NULL
***********************************************/
int igualAluno(aluno a1, aluno a2){
    return a1->numero == a2->numero;
}