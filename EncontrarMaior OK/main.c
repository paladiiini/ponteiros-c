#include <stdio.h>
#include <stdlib.h>
#include "FuncoesGenericas.h"

int main(){

    int tam;

    printf("\nOla, vamos encontrar o maior valor do seu vetor!\n\nPrimeiro, quantos digitos o seu vetor vai ter?\n");
    scanf("%d", &tam);

    int *vetor = (int *)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
        printf("\nDigite o valor da posicao %d do seu vetor:\n", i + 1);
        scanf("%d", &vetor[i]);
    }

    void *ponteiroVetor[tam];
    for (int i = 0; i < tam; i++) {
        ponteiroVetor[i] = &vetor[i];
    }

    encontrarMaior(ponteiroVetor, tam, comparaInteiros);

}