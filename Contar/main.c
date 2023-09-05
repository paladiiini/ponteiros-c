#include <stdio.h>
#include <string.h>
#include "FuncoesGenericas.h"

int main(){

    int n, tam;

    printf("\nInforme o tamanho do seu vetor:");
    scanf("%d", &tam);

    printf("\nCerto, o seu vetor tem %d valor(es)!\n", tam);

    int* v = (int *)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){

        printf("\nInforme o %do valor:\n", i+1);
        scanf("%d", &v[i]);

    }

    n = contar(v, tam, serPar);
    printf("\nQuantidade de pares = %d\n", n);

    n = contar(v, tam, serImpar);
    printf("\nQuantidade de impares = %d\n", n);

    n = contar(v, tam, serPrimo);
    printf("\nQuantidade de primos = %d\n", n);

}