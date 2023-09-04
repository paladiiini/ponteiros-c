#include <stdio.h>

struct Pessoa {
  char *nome;
  int idade;
};

typedef int (*FuncaoComparacao)(void *, void *);
typedef int (*FuncaoPredicado)(void *);
typedef void (*FuncaoOperacao)(void *);
typedef void (*FuncaoPessoa)(struct Pessoa);

void bubbleSort(void *[], int, FuncaoComparacao);

// o objetivo da função bubbleSort é ordenar os elementos do vetor em ordem crescente

void *encontrarMaior(void *[], int, FuncaoComparacao);

// o objetivo da função "encontrarMaior" é encontrar o maior elemento do vetor
// de acordo com um determinado critério de comparação

int contar(void *[], int, FuncaoPredicado);

// o objetivo da função "contar" é contabilizar a quantidade de elementos do
// vetor que atendem à um determinado predicado

void aplicarOperacao(void *dados[], int tam, FuncaoOperacao operacao);

// o objetivo da função "aplicarOperacao" é executar uma operação em cada
// elemento do vetor, alterando seu conteúdo conforme a operação aplicada

void identificarMenoresIdade(struct Pessoa pessoas[], int tam, FuncaoPessoa pfp);

// o objetivo da função "identificarMenoresIdade" é realizar o processamento das
// pessoas que tem idade menor de 18 anos. O processamento pode consistir apenas
// na impressão do nome das pessoas menores de idade, ou ser algo mais complexo,
// como a transmissão dos nomes das pessoas para outro sistema ou armazenamento
// em arquivo.

int comparaInteiros(void *info1, void *info2);

// IMPLEMENTAÇÃO DAS FUNÇÕES

void *encontrarMaior(void *dados[], int tam, FuncaoComparacao pfc) {

    bubbleSort(dados, tam, pfc);

    printf("\nO maior valor do vetor: %d\n", *((int *)dados[tam - 1]));
    
}

int contar(void *dados[], int tam, FuncaoPredicado pfp) { return 0; }

void somar(void *valor) {
    int i = 0;
    (*(int *)valor) += (*(int *)valor);
    printf("Valor de dados[%d]: %d\n", i + 1, valor);
}

void subtrair(void *valor) {
    (*(int *)valor) -= (*(int *)valor);
}

void dividir(void *valor) {
    (*(int *)valor) /= (*(int *)valor);
}

void multiplicar(void *valor) {
    (*(int *)valor) *= (*(int *)valor);
}

void aplicarOperacao(void *dados[], int tam, FuncaoOperacao operacao) {

    char *op;
    operacao(op);

    printf("\n**VETOR COM OPERACAO APLICADA**\n");

    if (op == '+') {
        for (int i = 0; i < tam; i++) {
            somar(dados[i]);
        }
    } else if (op == '-') {
        for (int i = 0; i < tam; i++) {
            subtrair(dados[i]);
        }
    } else if (op == '*') {
        for (int i = 0; i < tam; i++) {
            multiplicar(dados[i]);
        }
    } else if (op == '/') {
        for (int i = 0; i < tam; i++) {
            dividir(dados[i]);
        }
    } else {
        printf("Operacao nao reconhecida.\n");
    }
    
}

void operacao(void *op) {

    printf("\nAgora, digite o operador que voce quer aplicar a cada posicao do seu vetor:\n");
    scanf(" %c", op);

   if (op == '+') {
        op = 'somar';
    } else if (op == '-') {
        op = 'subtrair';
    } else if (op == '*') {
        op = 'multiplicar';
    } else if (op == '/') {
        op = 'dividir';
    } else {
        printf("Operacao nao reconhecida.\n");
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