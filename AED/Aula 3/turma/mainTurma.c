#include <stdio.h>
#include <ctype.h>


/* TADs usados */
#include "aluno.h"
#include "turma.h"

/* protótipos das funções usadas no main */

void interpretador(turma t);

/*
A numeroAluno -> Adiciona o novo aluno à turma;
R numeroAluno -> Remove o aluno da turma;
T numeroAluno tp1 tp2 -> Atribui as notas dos trabalhos ao aluno;
N numeroAluno t1 t2 -> Atribui as notas dos testes ao aluno;
F numeroAluno -> Escreve na consola a nota final do aluno;
E -> Escreve na consola o número de aprovados e reprovados na turma;
L -> Lista todos os alunos da turma;
*/
void adicionaAluno(turma t, char * linha);
void removeAluno(turma t,char * linha);
void notasTrabalhosAluno(turma t,char * linha);
void notasTestesAluno(turma t,char * linha);
void notaFinal(turma t,char * linha);
void estatisticaTurma(turma t);
void listaTurma(turma t);

int main(void){
	turma aed = criaTurma();
	interpretador(aed);
	destroiTurmaEAlunos(aed);
	return 0;
}

void interpretador(turma t){
	char linha[25], cmd;

	printf(">");
	fgets(linha,25,stdin);
	cmd = toupper(linha[0]);
	while (cmd!='S'){
		/* Tratar comando */
		switch (cmd){
			case 'A': adicionaAluno(t,linha);break;
			case 'R': removeAluno(t,linha); break;
			case 'T': notasTrabalhosAluno(t,linha);break;
			case 'N': notasTestesAluno(t,linha);break;
			case 'F': notaFinal(t,linha);break;
			case 'E': estatisticaTurma(t); break;
			case 'L': listaTurma(t); break;
			default: printf("Comando invalido\n");break;
		}
		printf(">");
		fgets(linha,25,stdin);
		cmd = toupper(linha[0]);
	}
	printf ("Fim turma AED");
}

void adicionaAluno(turma t, char * linha){
	char c;
	int numAluno;
	if (sscanf(linha,"%c %d",&c, &numAluno)!= 2)
		printf("Dados invalidos\n");
	else
		if (adicionaAlunoTurma(t,numAluno) != 1)
			printf("Aluno ja existe.\n");
}

void removeAluno(turma t,char * linha){
    char c;
    int numAluno;
    aluno a;
    if (sscanf(linha,"%c %d",&c,&numAluno)!= 2)
        printf("Dados invalidos\n");
    else {
        a = removeAlunoTurma(t,numAluno) ;
        if ( a == NULL)
            printf("Aluno nao existe.\n");
        else
            destroiAluno(a);
    }
}

void notasTrabalhosAluno(turma t,char * linha){
    char c;
    int numAluno;
	aluno a;
    float tp1, tp2;
    if (sscanf(linha,"%c %d %f %f",&c,&numAluno,&tp1,&tp2)!= 4)
        printf("Dados invalidos\n");
    else {
        a = daAlunoTurma(t, numAluno);
		if (a==NULL)
            printf("Aluno nao existe.\n");
		else
            daNotasTrabalhosAluno(a, tp1, tp2);
    }
}

void notasTestesAluno(turma t,char * linha){
	char c;
	int numAluno;
	aluno a;
	float t1, t2;
	if (sscanf(linha,"%c %d %f %f",&c,&numAluno,&t1,&t2)!= 4)
		printf("Dados invalidos\n");
    else {
		a = daAlunoTurma(t, numAluno);
		if (a==NULL)
            printf("Aluno nao existe.\n");
		else
            daNotasTestesAluno(a, t1, t2);
	}
}
void notaFinal(turma t,char * linha){
	char c;
	int numAluno;
	aluno a;
	if (sscanf(linha,"%c %d",&c,&numAluno)!= 2)
		printf("Dados invalidos\n");
	else {
        a = daAlunoTurma(t, numAluno);
		if (a == NULL)
			printf("Aluno nao existe.\n");
        else
            printf("Nota Final: %d\n", daNotaFinalAluno(a));

	}
}

void estatisticaTurma(turma t){
	if (daTamanhoTurma(t) == 0)
		printf("Nao existem alunos na turma\n");
	else {
		printf("Aprovados: %d\n", daAprovadosTurma(t));
		printf("Reprovados: %d\n", daReprovadosTurma(t));
	}
}

void listaTurma(turma t){
	int i = 1;
	int cont = daTamanhoTurma(t);
	aluno a;

	for (; i <=cont; i++){
		a = daAlunoPosTurma(t,i);
		printf("Numero: %d; Nota Final: %d\n", numeroAluno(a), daNotaFinalAluno(a));
	}
}



