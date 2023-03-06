#include <stdlib.h>

#include "aluno.h"

/* Constantes do TAD aluno */

#define PERT1 0.15
#define PERT2 0.45
#define PERTP1 0.25
#define PERTP2 0.15
#define APROVADO 10
#define CENTENAS 100
#define ARREDONDA 45

/* Estrutura de dados do TAD aluno */
struct _aluno{
	int numero;         //Numero aluno
	float t1, t2;       //Notas testes
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
	a->t1 = 0;
	a->t2 = 0;
	a->tp1 = 0;
	a->tp2 = 0;
	return a;
}

/***********************************************
destroiAluno - Liberta a memória ocupada pela instância da estrutura associada ao aluno.
Parâmetros:
	a - aluno a destruir
Retorno:
Pré-condições: a != NULL
***********************************************/
void destroiAluno(aluno a){
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
daNotasTestesAluno - Atribuição das notas dos testes ao aluno.
Parâmetros:
	a - aluno
	t1 - nota teste 1
	t2 - nota teste 2
Retorno:
Pré-condições: a != NULL && 0<=t1<=20 && 0<=t2<=20
***********************************************/
void daNotasTestesAluno(aluno a, float t1, float t2){
	a->t1 = t1;
	a->t2 = t2;
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
daNotaFinalAluno - da a nota final do aluno arredondada unidades
Parâmetros:		a - aluno
Retorno: nota final
Pré-condições: a != NULL
***********************************************/
int daNotaFinalAluno(aluno a){
	float nota =  a->t1*PERT1 + a->t2*PERT2 + a->tp1*PERTP1 + a->tp2*PERTP2;
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
	if (daNotaFinalAluno(a) >= APROVADO)
		return 1;
	return 0;
}

/***********************************************
igualAluno - Indica se dois alunos sao iguais (tem o mesmo numero)
Parâmetros:		a - aluno
Retorno: 0 - nao; 1 - sim
Pré-condições: a1 != NULL && a2 != NULL
***********************************************/
int igualAluno(aluno a1, aluno a2){
    int igual = 0;
    if (a1->numero == a2->numero)
        igual = 1;
    return igual;
}
