/*
 * mainNota.c
 *
 *  Created on: 29 de Fev
 *  Author: AED 2º semestre
 */

#include <stdio.h>

#define PERT1 0.15
#define PERT2 0.45
#define PERTP1 0.25
#define PERTP2 0.15
#define APROVADO 10
#define CENTENAS 100
#define ARREDONDA 45

/* leitura dos dados */
void lerNotasAluno(int * n, float* t1,float* t2, float* tp1,float* tp2);

/* calcula a nota final */
int calculaNota(float t1, float t2, float tp1, float tp2);

/* indica se a nota é aprovada */
int eAprovado(int nota);

int main(void) {
	int numAluno, notaFinal, aprovado;
	float t1, t2, tp1, tp2;

    /* Leitura dos dados de entrada */
	lerNotasAluno(&numAluno,&t1,&t2,&tp1,&tp2);
	
    /* Calculo de resultados */
	notaFinal = calculaNota(t1,t2,tp1,tp2);
	aprovado = eAprovado(notaFinal);
	
    /* Escrita dos resultados */
	if (aprovado) printf("O aluno %d foi aprovado com nota de %d valores\n",numAluno,notaFinal);
	else printf("O aluno %d foi reprovado com nota de %d valores\n",numAluno,notaFinal);
	return 0;
}

int calculaNota(float t1, float t2, float tp1, float tp2){
	float nota =  t1*PERT1 + t2*PERT2 + tp1*PERTP1 + tp2*PERTP2;
	int resto = (int)((nota - (int) nota) * CENTENAS);
	if (resto <= ARREDONDA)
        return (int) nota;
	return (int) (nota+1);
}

int eAprovado(int nota){
	if (nota >= APROVADO)
        return 1;
	return 0;
}

void lerNotasAluno(int * n,float * t1, float * t2, float * tp1, float * tp2){
	printf("Numero de aluno: ");
    scanf("%d", n);
	printf("Notas dos testes (dois valores reais): ");
    scanf("%f %f",t1,t2);
	printf("Notas dos trabalhos (dois valores reais): ");
    scanf("%f %f",tp1,tp2);
}


