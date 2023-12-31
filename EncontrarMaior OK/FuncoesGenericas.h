#include <stdio.h>

struct Pessoa {
  char *nome;
  int idade;
};

typedef int (*FuncaoComparacao)(void *, void *);
typedef int (*FuncaoPredicado)(void *);
typedef void (*FuncaoOperacao)(char *);
typedef void (*FuncaoPessoa)(struct Pessoa);

void bubbleSort(void *[], int, FuncaoComparacao);

// o objetivo da função bubbleSort é ordenar os elementos do vetor em ordem crescente

void *encontrarMaior(void *[], int, FuncaoComparacao);

// o objetivo da função "encontrarMaior" é encontrar o maior elemento do vetor
// de acordo com um determinado critério de comparação

int contar(void *[], int, FuncaoPredicado);

// o objetivo da função "contar" é contabilizar a quantidade de elementos do
// vetor que atendem à um determinado predicado

void aplicarOperacao(void *dados[], int tam, FuncaoOperacao operacao, char op);

// o objetivo da função "aplicarOperacao" é executar uma operação em cada
// elemento do vetor, alterando seu conteúdo conforme a operação aplicada

void identificarMenoresIdade(struct Pessoa pessoas[], int tam, FuncaoPessoa pfp);

// o objetivo da função "identificarMenoresIdade" é realizar o processamento das
// pessoas que tem idade menor de 18 anos. O processamento pode consistir apenas
// na impressão do nome das pessoas menores de idade, ou ser algo mais complexo,
// como a transmissão dos nomes das pessoas para outro sistema ou armazenamento
// em arquivo.

int comparaInteiros(void *info1, void *info2);

char operacao(char op);

// IMPLEMENTAÇÃO DAS FUNÇÕES

void *encontrarMaior(void *dados[], int tam, FuncaoComparacao pfc) {

    for(int i = 0;i < tam; i++){

        for(int j = 0; j < tam - 1; j++){

            if(pfc(dados[j], dados[j + 1]) > 0){

                void *temp = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = temp;

            }

        }


    }
    printf("O maior valor do vetor: %d\n", *((int *)dados[tam - 1])); 
}

int contar(void *dados[], int tam, FuncaoPredicado pfp) { return 0; }

void aplicarOperacao(void *dados[], int tam, FuncaoOperacao operacao, char op) {

    operacao(op);

    if (op == '+') {
        for (int i = 0; i < tam; i++) {
            operacao(dados);
        }
    } else if (op == '-') {
        for (int i = 0; i < tam; i++) {
            operacao(dados);
        }
    } else if (op == '*') {
        for (int i = 0; i < tam; i++) {
            operacao(dados);
        }
    } else if (op == '/') {
        for (int i = 0; i < tam; i++) {
            operacao(dados);
        }
    }

    printf("\n**VETOR COM OPERACAO APLICADA**\n");
    for (int i = 0; i < tam; i++) {
    printf("Valor de dados[%d]: %d\n", i, *((int *)dados[i]));
    }
}

char operacao(char op) {

    char funcaoOperacao;

   if (op == '+') {
        funcaoOperacao = 'somar';
    } else if (op == '-') {
        funcaoOperacao = 'subtrair';
    } else if (op == '*') {
        funcaoOperacao = 'multiplicar';
    } else if (op == '/') {
        funcaoOperacao = 'dividir';
    } else {
        printf("Operacao nao reconhecida.\n");

        return funcaoOperacao;
    }
}

void identificarMenoresIdade(struct Pessoa pessoas[], int tam,
                             FuncaoPessoa pfp) {}
int comparaInteiros(void *info1, void *info2) {
    int *i1 = (int *)info1;
    int *i2 = (int *)info2;

    if (*i1 > *i2) {
        return 1;
    } else if (*i1 < *i2) {
        return -1;
    } else {
        return 0;
    }
}

void bubbleSort(void *dados[], int tam, FuncaoComparacao pfc) {
    int i, j;
    void *temp;
    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - (i + 1); j++) {
            int r = pfc(dados[j], dados[j + 1]);
            if (r > 0) {
                temp = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = temp;
            }
        }
    }
    printf("\n**VETOR ORDENADO**\n");
    for (i = 0; i < tam; i++) {
        printf("Valor de dados[%d]: %d\n", i, *((int *)dados[i]));
    }
}