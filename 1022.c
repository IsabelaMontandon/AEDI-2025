#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numerador;
    int denominador;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila *f) {
    f->inicio = f->fim = NULL;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *f) {
    return f->inicio == NULL;
}

// Função para enfileirar um elemento
void enfileirar(Fila *f, int numerador, int denominador) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    novo->numerador = numerador;
    novo->denominador = denominador;
    novo->proximo = NULL;
    if (filaVazia(f)) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
}

// Função para desenfileirar um elemento
void desenfileirar(Fila *f, int *numerador, int *denominador) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        exit(1);
    }
    No *temporario = f->inicio;
    *numerador = temporario->numerador;
    *denominador = temporario->denominador;
    f->inicio = temporario->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temporario);
}

// Função para calcular o máximo divisor comum (MDC) usando o algoritmo de Euclides
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para simplificar uma fração
void simplificar(int *numerador, int *denominador) {
    int divisor = mdc(abs(*numerador), abs(*denominador));
    *numerador /= divisor;
    *denominador /= divisor;
}

// Função principal para processar a entrada e realizar as operações
int main() {
    int numOperacoes;
    scanf("%d", &numOperacoes);
    while (numOperacoes--) {
        int numerador1, denominador1, numerador2, denominador2;
        char operador;
        scanf("%d / %d %c %d / %d", &numerador1, &denominador1, &operador, &numerador2, &denominador2);
        int resultadoNumerador, resultadoDenominador;
        switch (operador) {
            case '+':
                resultadoNumerador = numerador1 * denominador2 + numerador2 * denominador1;
                resultadoDenominador = denominador1 * denominador2;
                break;
            case '-':
                resultadoNumerador = numerador1 * denominador2 - numerador2 * denominador1;
                resultadoDenominador = denominador1 * denominador2;
                break;
            case '*':
                resultadoNumerador = numerador1 * numerador2;
                resultadoDenominador = denominador1 * denominador2;
                break;
            case '/':
                resultadoNumerador = numerador1 * denominador2;
                resultadoDenominador = numerador2 * denominador1;
                break;
        }
        int numeradorOriginal = resultadoNumerador;
        int denominadorOriginal = resultadoDenominador;
        simplificar(&resultadoNumerador, &resultadoDenominador);
        printf("%d/%d = %d/%d\n", numeradorOriginal, denominadorOriginal, resultadoNumerador, resultadoDenominador);
    }
    return 0;
}
