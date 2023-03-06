#ifndef ALUNO_H_
#define ALUNO_H_

/* Tipo do TAD aluno */
typedef struct _aluno * aluno;

/* Protótipos das funções associadas a um aluno - TAD aluno */

/***********************************************
criaAluno - Criação da instância da estrutura associada a um aluno.
Parâmetros:
	num - número de aluno
Retorno: apontador para a instância criada
Pré-condições: num > 0
***********************************************/
aluno criaAluno(int num);

/***********************************************
apagaAluno - Liberta a memória ocupada pela instância da estrutura associada ao aluno.
Parâmetros:
	a - aluno a apagar
Retorno:
Pré-condições: a != NULL
***********************************************/
void apagaAluno(aluno a);

/***********************************************
daNotasTrabalhosAluno - Atribuição das notas dos trabalhos práticos ao aluno.
Parâmetros:
	a - aluno
	tp1 - nota trabalho prático 1
	tp2 - nota trabalho prático 2
Retorno:
Pré-condições: a != NULL && 0<=tp1<=20 && 0<=tp2<=20
***********************************************/
void daNotasTrabalhosAluno(aluno a, float tp1, float tp2);

/***********************************************
daNotasTestesAluno - Atribuição da nota teórico-prática ao aluno.
Parâmetros:
	a - aluno
	p - nota projecto
	t - nota teste
Retorno:
Pré-condições: a != NULL && 0<=p<=20 && 0<=t<=20
***********************************************/
void daNotasTestesAluno(aluno a, float p, float t);

/***********************************************
numeroAluno - Consulta o número do aluno.
Parâmetros:		a - aluno
Retorno: número do aluno
Pré-condições: a != NULL
***********************************************/
int numeroAluno(aluno a);

/***********************************************
notaFinalAluno - dá a nota final do aluno.
Parâmetros:		a - aluno
Retorno: nota final
Pré-condições: a != NULL
***********************************************/
int notaFinalAluno(aluno a);

/***********************************************
aprovadoAluno - Indica se o aluno obteve aprovação.
Parâmetros:		a - aluno
Retorno: 1 - caso aprovado; 0 - caso contrário
Pré-condições: a != NULL
***********************************************/
int aprovadoAluno(aluno a);

/***********************************************
igualAluno - Indica se dois alunos são o mesmo (têm o mesmo número)
Parâmetros:		a - aluno
Retorno: 0 - não; 1 - sim
Pré-condições: a1 != NULL && a2 != NULL
***********************************************/
int igualAluno(aluno a1, aluno a2);

#endif /* ALUNO_H_ */