/*
 * turma.c
 */
#include "aluno.h"
#include "turma.h"

#include <stdlib.h>

#define CAP 100

/* Estrutura de dados do tipo de dados: turma */
struct _turma{
	aluno * alunos;
	int numAlunos;
	int capacidade;
};

/* Implementação das funções associadas a uma turma */

turma criaTurma(){
	turma t = (turma) malloc (sizeof(struct _turma));
	if (t == NULL) return NULL;
	t->alunos = (aluno *) malloc (sizeof(aluno) * CAP);
	if (t->alunos == NULL){
		free(t);
		return NULL;
	}
	t->numAlunos = 0;
	t->capacidade = CAP;
	return t;
}

void destroiTurma(turma t){
	free (t->alunos);
	free(t);
}

void destroiTurmaEAlunos(turma t){
	int i = 0;
	for(; i< t->numAlunos; i++)
		destroiAluno(t->alunos[i]);
	free(t->alunos);
	free(t);
}
/* procura posicao na turma (vector) do aluno com numero n */
int posTurma (turma t, int n){
	int pos =-1, i = 0;
	while ((i< t->numAlunos) && (pos == -1)){
		if (n == numeroAluno(t->alunos[i]))
			pos = i;
		i++;
	}
	return pos;
}
int existeAlunoTurma(turma t,int n){
	if (posTurma(t,n) == -1)
		return 0;
	return 1;
}

aluno daAlunoTurma(turma t, int n){
	int pos = posTurma(t,n);
	if (pos == -1)
		return NULL;
	return t->alunos[pos];
}

/* Incrementa o tamanho do vector da turma */
void incCapacidadeTurma(turma t){
	int i = 0;
	/* Cria um vector com o dobro do tamanho */
	aluno * aux = (aluno *) malloc(sizeof (aluno)* t->capacidade * 2);
	for(;i<t->numAlunos;i++)
		aux[i] = t->alunos[i];
	free(t->alunos);
	t->alunos = aux;
	t->capacidade = t->capacidade * 2;
}

int adicionaAlunoTurma(turma t,int n){
	if (existeAlunoTurma(t,n) == 1)
		return 0;
	if (t->numAlunos == t->capacidade)
		incCapacidadeTurma(t);
	t->alunos[t->numAlunos++] = criaAluno(n);
	return 1;
}

aluno removeAlunoTurma(turma t,int n){
	aluno a;
	int pos = posTurma (t,n);
	if (pos == -1) return NULL;
	a = t->alunos[pos];
	t->alunos[pos] = t->alunos[t->numAlunos-1];
	t->numAlunos--;
	return a;
}

int daTamanhoTurma(turma t){
	return t->numAlunos;
}

int daAprovadosTurma(turma t){
	int i = 0,cont = 0;
	for(;i<t->numAlunos; i++)
		if (aprovadoAluno(t->alunos[i]) == 1)
			cont++;
	return cont;
}

int daReprovadosTurma(turma t){
	int i = 0,cont = 0;
		for(;i<t->numAlunos; i++)
			if (aprovadoAluno(t->alunos[i]) != 1)
				cont++;
		return cont;
}

aluno daAlunoPosTurma(turma t, int i){
	return t->alunos[i-1];
}

