#include <stdio.h>
#include <stdlib.h>

int main() {
    int lado, comp;
    int ladoaz;
    int ladototal, comptotal;
    int total;

    scanf("%d", &ladoaz);
    scanf("%d %d", &comp, &lado);
    ladototal=lado/ladoaz;
    comptotal=comp/ladoaz;

    total=ladototal*comptotal;
    printf("Azulejos inteiros: %d\n", total);
    
    return 0;

}