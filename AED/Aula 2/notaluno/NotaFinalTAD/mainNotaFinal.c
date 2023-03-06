/*
 * mainNota.c
 */

#include <stdio.h>

/* TADs usados */
#include "aluno.h"

/* Protótipos das funções utilizadas no main */
void lerNotasAluno(int* n, float* p,float* t, float* tp1,float* tp2);
void escreverResultado(int aprovado, int notaF, aluno a);

int main(void) {
	int numAluno, notaFinal, aprovado;
	float p, t, tp1, tp2;
	aluno a;

    /* Leitura notas do aluno */
	lerNotasAluno(&numAluno,&p,&t,&tp1,&tp2);

	/* Criação de um aluno */
	a = criaAluno(numAluno);

	/* Atribuição das notas ao aluno */
	daNotasTrabalhosAluno(a,tp1,tp2);
	daNotasTestesAluno(a,p,t);

	/* Calcula nota final e aprovação */
	notaFinal = notaFinalAluno(a);
	aprovado = aprovadoAluno(a);
	numAluno = numeroAluno(a);

	/* Escreve mensagem de nota de aluno */
	escreverResultado(aprovado, notaFinal, a);

	apagaAluno(a);
	return 0;
}

void lerNotasAluno(int* n,float* p, float* t, float* tp1, float* tp2){
	printf("Numero de aluno: ");
	scanf("%d", n);
	printf("Notas dos testes (dois valores reais): ");
	scanf("%f %f",p,t);
	printf("Notas dos trabalhos (dois valores reais): ");
	scanf("%f %f",tp1,tp2);
}

void escreverResultado(int ap, int notaF, aluno a){
    if (ap)
		printf("O aluno %d aprovou com nota de %d valores\n",numeroAluno(a), notaF);
	else
		printf("O aluno %d reprovou com nota de %d valores\n",numeroAluno(a), notaF);
}

