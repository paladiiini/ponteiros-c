#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FuncoesGenericas.h"

int main(){

    int n, tam;

    printf("\nInforme o tamanho do seu vetor:\n");
    scanf("%d", &tam);

    printf("\nCerto, o seu vetor tem %d valor(es)!\n", tam);

    int* v = (int *)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){

        printf("\nInforme o %do valor:\n", i+1);
        scanf("%d", &v[i]);

    }

   void** ptrs = (void**)malloc(tam * sizeof(int*));
    for(int i = 0; i < tam; i++){
        ptrs[i] = &v[i]; 
    }

    n = contar(ptrs, tam, serPar);
    printf("\nQuantidade de números pares no vetor = %d\n", n);

    n = contar(ptrs, tam, serImpar);
    printf("\nQuantidade de números ímpares no vetor = %d\n", n);

    n = contar(ptrs, tam, serPrimo);
    printf("\nQuantidade de números primos no vetor = %d\n", n);

}