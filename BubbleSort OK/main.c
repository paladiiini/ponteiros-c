#include <stdio.h>
#include <stdlib.h>
#include "FuncoesGenericas.h"

int main() {
    printf("Vamos alinhar o seu vetor em ordem crescente!\n\nQuantos numeros tu quer inserir no vetor?\n");
    int tam;
    scanf("%d", &tam);

    int *v = (int *)malloc(tam * sizeof(int));

    printf("\nCerto, o seu vetor possui %d numero(s)!\n", tam);

    for (int i = 0; i < tam; i++) {
        printf("\nInsira o %do valor:\n", i + 1);
        scanf("%d", &v[i]);
    }

    void *ponteiroVetor[tam];
    for (int i = 0; i < tam; i++) {
        ponteiroVetor[i] = &v[i];
    }
    
    bubbleSort(ponteiroVetor, tam, comparaInteiros);

    free(v);

    return 0;
}
