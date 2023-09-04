#include <stdio.h>
#include <stdlib.h>
#include "FuncoesGenericas.h"

int main(){

    int tam;

    printf("\nOla, vamos realizar operacoes com os valores do seu vetor!\n\nPrimeiro, quantos digitos o seu vetor vai ter?\n");
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

    aplicarOperacao(ponteiroVetor, tam, operacao);

    printf("\n**VETOR COM OPERACAO APLICADA**\n");
    for (int i = 0; i < tam; i++) {
        printf("\nvetor[%d]: %d", i+1, vetor[i]);
    }
}