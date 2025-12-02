#include <stdio.h>
#include <stdlib.h>

typedef struct filaIngresso {
    int id;
    struct filaIngresso *prox;
} Fila;

typedef struct {
    Fila *inicio;
    Fila *fim;
} GerenciadorFila;

void inicializarFila(GerenciadorFila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void entrarFila(GerenciadorFila *fila, int novoId) {
    Fila *novaPessoa = (Fila *)malloc(sizeof(Fila));
    novaPessoa->id = novoId;
    novaPessoa->prox = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novaPessoa;
        fila->fim = novaPessoa;
    } else {
        fila->fim->prox = novaPessoa;
        fila->fim = novaPessoa;
    }
}

void sairFila(GerenciadorFila *fila, int id) {
    Fila *pessoaAtual = fila->inicio;
    Fila *pessoaAnterior = NULL;

    while (pessoaAtual != NULL && pessoaAtual->id != id) {
        pessoaAnterior = pessoaAtual;
        pessoaAtual = pessoaAtual->prox;
    }

    if (pessoaAtual == NULL) return;

    if (pessoaAnterior == NULL) {
        fila->inicio = pessoaAtual->prox;
    } else {
        pessoaAnterior->prox = pessoaAtual->prox;
    }

    if (pessoaAtual == fila->fim) {
        fila->fim = pessoaAnterior;
    }

    free(pessoaAtual);
}

void mostrarFila(GerenciadorFila *fila) {
    Fila *pessoaAtual = fila->inicio;

    while (pessoaAtual != NULL) {
        printf("%d", pessoaAtual->id);
        if (pessoaAtual->prox != NULL) {
            printf(" ");
        }
        pessoaAtual = pessoaAtual->prox;
    }

    printf("\n");
}

void liberarFila(GerenciadorFila *fila) {
    Fila *pessoaAtual = fila->inicio;

    while (pessoaAtual != NULL) {
        Fila *proximo = pessoaAtual->prox;
        free(pessoaAtual);
        pessoaAtual = proximo;
    }

    fila->inicio = NULL;
    fila->fim = NULL;
}

int main() {
    int quant_p, quant_remov, id;
    GerenciadorFila filaIng;

    inicializarFila(&filaIng);

    scanf("%d", &quant_p);

    while (quant_p > 0) {
        scanf("%d", &id);
        entrarFila(&filaIng, id);
        quant_p--;
    }

    scanf("%d", &quant_remov);

    while (quant_remov > 0) {
        scanf("%d", &id);
        sairFila(&filaIng, id);
        quant_remov--;
    }

    mostrarFila(&filaIng);

    liberarFila(&filaIng);
}
