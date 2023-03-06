#include <stdio.h>
#include <stdlib.h>

int main() {
    int dia, mes, ano;
    int total, bisadd, prev;

    printf("Introduza uma data (ano, mes, dia):\n");
    scanf(" %d %d %d", &ano, &mes, &dia);
    
    if(((ano%4==0)&&(ano%100!=0))||(ano%400==0)) {
            bisadd=1;
        }
    else {
            bisadd=0;
    }

    switch (mes) {
        case 1 : prev=0; break;
        case 2 : prev=31; break;
        case 3 : prev=bisadd+59; break;
        case 4 : prev=bisadd+90; break;
        case 5 : prev=bisadd+120; break;
        case 6 : prev=bisadd+151; break;
        case 7 : prev=bisadd+181; break;
        case 8 : prev=bisadd+212; break;
        case 9 : prev=bisadd+243; break;
        case 10 : prev=bisadd+273; break;
        case 11 : prev=bisadd+304; break;
        case 12 : prev=bisadd+334; break;
    }

    total=prev+dia;

    printf("%d\n", total);


    return 0;

}