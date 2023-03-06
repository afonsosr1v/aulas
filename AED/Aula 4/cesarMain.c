#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cesar.h"

#define TAM_MSG 100
#define MAX_LINHA 100

void ler_mensagem(char * mensagem, int linhas);
int ler_codigo();
int ler_linhas();


int main(void) {
    int deslocamento;
    int linhas;
    char mensagem[100];
    char matriz[100] = "";
    cifra c;
    int i;

    printf("Codigo: ");
    scanf("%d", &deslocamento);
    printf("Linhas: ");
    scanf("%d", &linhas);
    printf("Texto:\n");
    for(i=0;i<=linhas;i++) {
        fgets(mensagem, 100, stdin);
        mensagem[strlen(mensagem)-1]='\0';
        //strtok(mensagem, '\n');
        strcat(matriz, mensagem);
    }
    // printf("%s", matriz);

    /*i=0;
    for(i=0;i<100;i++) {
        printf("%c", matriz[i]);
    } */

    c=criarCifra(matriz, deslocamento, linhas);

    atualizarMensagem(c);

    apresentarResultado(c);

    destroiCifra(c);

    return 0;
}

void apresentarResultado(cifra c){
    printf("Texto cifrado: %s\n", passarMensagem(c));
}

/* int ler_codigo() {
    int deslocamento;
    printf("Codigo: ");
    scanf("%d", deslocamento);
    return deslocamento;
}

int ler_linhas() {
    int linhas;
    printf("Linhas: ");
    scanf("%d", linhas);
    return linhas;
}

void ler_mensagem(char * mensagem, int linhas) {
    int i, j;
    printf("Texto:\n");
    i=0;
    j=0;
    for(j=0;j<linhas;j++) {
        fgets(mensagem, 20, stdin);
        mensagem[strlen(mensagem)-1] = '\0';
    }
} */

