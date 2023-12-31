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

int serImpar(void* info);
int serPar(void* info);
int serPrimo(void* info);

// o objetivo da função "contar" é contabilizar a quantidade de elementos do
// vetor que atendem à um determinado predic

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

int serPar(void* info){

int* p = (int*) info;
if (*p % 2 == 0)
    return 1;

return 0;
}

int serImpar(void* info){

int* p = (int*) info;
if (*p % 2 == 1)
    return 1;

return 0;
}

int serPrimo(void* info) {
    int* p = (int*) info;
    if (*p <= 1)
        return 0; // Números menores ou iguais a 1 não são primos

    if (*p == 2)
        return 1; // 2 é primo

    if (*p % 2 == 0)
        return 0; // Números pares maiores que 2 não são primos

    for (int i = 3; i <= sqrt(*p); i += 2) {
        if (*p % i == 0)
            return 0; // Se for divisível por algum número ímpar, não é primo
    }

    return 1; // Se não foi encontrado divisor, é primo
}


int contar(void *dados[], int tam, FuncaoPredicado pfp) { 
    
    int contador = 0;

    for(int i = 0; i < tam; i++){

        if(pfp(dados[i]) == 1){
        contador++;
        }
    }
    
    return contador; 
}

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