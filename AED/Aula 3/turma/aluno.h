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
destroiAluno - Liberta a memória ocupada pela instância da estrutura associada ao aluno.
Parâmetros:
	a - aluno a destruir
Retorno:
Pré-condições: a != NULL
***********************************************/
void destroiAluno(aluno a);

/***********************************************
daNotasTrabalhosAluno - Atribuição das notas dos trabalhos práticos ao aluno.
Parâmetros:
	a - aluno
	tp1 - nota trabalho 1
	tp2 - nota trabalho 2
Retorno:
Pré-condições: a != NULL && 0<=tp1<=20 && 0<=tp2<=20
***********************************************/
void daNotasTrabalhosAluno(aluno a, float tp1, float tp2);

/***********************************************
daNotasTestesAluno - Atribuição das notas dos testes ao aluno.
Parâmetros:
	a - aluno
	t1 - nota teste 1
	t2 - nota teste 2
Retorno:
Pré-condições: a != NULL && 0<=t1<=20 && 0<=t2<=20
***********************************************/
void daNotasTestesAluno(aluno a, float t1, float t2);

/***********************************************
numeroAluno - Consulta o número do aluno.
Parâmetros:		a - aluno
Retorno: número do aluno
Pré-condições: a != NULL
***********************************************/
int numeroAluno(aluno a);

/***********************************************
daNotaFinalAluno - da a nota final do aluno.
Parâmetros:		a - aluno
Retorno: nota final
Pré-condições: a != NULL
***********************************************/
int daNotaFinalAluno(aluno a);

/***********************************************
aprovadoAluno - Indica se o aluno obteve aprovação.
Parâmetros:		a - aluno
Retorno: 1 - caso aprovado; 0 - caso contrário
Pré-condições: a != NULL
***********************************************/
int aprovadoAluno(aluno a);

/***********************************************
igualAluno - Indica se dois alunos sao iguais (tem o mesmo numero)
Parâmetros:		a - aluno
Retorno: 0 - nao; 1 - sim
Pré-condições: a1 != NULL && a2 != NULL
***********************************************/
int igualAluno(aluno a1, aluno a2);

#endif /* ALUNO_H_ */

