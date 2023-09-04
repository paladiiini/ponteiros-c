#include <stdio.h>
#include <stdlib.h>
#include "FuncoesGenericas.h"
#include <string.h>

int main() {

    printf("Vamos cadastrar um vetor com pessoas!\n\nQuantas pessoas tera o seu vetor?\n");
    int tam;
    scanf("%d", &tam);

    struct Pessoa *v = (struct Pessoa *)malloc(tam * sizeof(struct Pessoa));
    
    printf("\nCerto, o seu vetor cabe %d pessoa(s)!\n", tam);

    for (int i = 0; i < tam; i++) {
     v[i].nome = (char *)malloc(50 * sizeof(char));
        printf("\nInsira o %do nome:\n", i + 1);
        scanf("%s", v[i].nome);

        printf("\nInsira a idade da %da pessoa:\n", i + 1);
        scanf("%d", &v[i].idade);
    }

    identificarMenoresIdade(v, tam, FunPessoa);

    free(v);

    return 0;
}
