/*
 * turma.h
 */

#ifndef _H_TURMA
#define _H_TURMA

/* Tipo de dados: turma */
typedef struct _turma * turma;

/* Protótipos das funções associadas a uma turma */

/***********************************************
criaTurma - Criação da instância da estrutura associada a uma turma.
Parâmetros:
Retorno: apontador para a instância criada
Pré-condições:
***********************************************/
turma criaTurma();

/***********************************************
destroiTurma - Liberta a memória ocupada pela instância da estrutura associada à turma.
Parâmetros:
	t - turma a destruir
Retorno:
Pré-condições: t != NULL
***********************************************/
void destroiTurma(turma t);

/***********************************************
destroiTurmaEAlunos - Liberta a memória ocupada pela instância da estrutura associada à turma e aos alunos na turma.
Parâmetros:
	t - turma a destruir
Retorno:
Pré-condições: t != NULL
***********************************************/
void destroiTurmaEAlunos(turma t);

/***********************************************
existeAlunoTurma - Indica o aluno com o número dado existe na turma dada.
Parâmetros:
	t - turma
	n - número do aluno
Retorno: 1 - caso exista o aluno; 0 - caso não exista o aluno
Pré-condições: t != NULL
***********************************************/
int existeAlunoTurma(turma t,int n);

/***********************************************
daAlunoTurma - Consulta o aluno  com o numero dado na turma.
Parâmetros:
	t - turma
	n - numero aluno
Retorno: aluno
Pré-condições: t != NULL
***********************************************/
aluno daAlunoTurma(turma t, int n);

/***********************************************
adicionaAlunoTurma - Adiciona o aluno com o número dado na turma dada, caso o aluno não exista.
Parâmetros:
	t - turma
	n - número do aluno
Retorno: retorna 1, caso adicionar e 0, caso contrário
Pré-condições: t != NULL
***********************************************/
int adicionaAlunoTurma(turma t,int n);

/***********************************************
removeAlunoTurma - Remove o aluno com o número dado, caso exista, da turma dada.
Parâmetros:
	t – turma		n - número do aluno
Retorno: retorna o aluno ou NULL, caso o aluno não exista
Pré-condições: t != NULL
***********************************************/
aluno removeAlunoTurma(turma t,int n);

/***********************************************
daTamanhoTurma - Indica o número de alunos na turma.
Parâmetros:
	t - turma
Retorno: número de alunos da turma
Pré-condições: t != NULL
***********************************************/
int daTamanhoTurma(turma t);

/***********************************************
daAprovadosTurma - Indica o número de alunos aprovados na turma.
Parâmetros:
	t - turma
Retorno: número de alunos aprovados na turma
Pré-condições: t != NULL && tamanhoTurma(t) != 0
***********************************************/
int daAprovadosTurma(turma t);

/***********************************************
daReprovadosTurma - Indica o número de alunos reprovados na turma.
Parâmetros:
	t - turma
Retorno: número de alunos reprovados na turma
Pré-condições: t != NULL && tamanhoTurma(t) != 0
***********************************************/
int daReprovadosTurma(turma t);

/***********************************************
alunoPosTurma - Consulta o aluno i-esimo na turma.
Parâmetros:
	t - turma
	i - inteiro
Retorno: aluno i-esimo da turma
Pré-condições: t != NULL && i > 0 && i <=tamanhoTurma(t)
***********************************************/
aluno daAlunoPosTurma(turma t, int i);

#endif /* _H_TURMA */
