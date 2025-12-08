#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_MAXIMO 300

typedef struct Nodo {
    char valor;
    struct Nodo* proximo;
} Nodo;

typedef struct {
    Nodo* topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
}

int estaVazia(Pilha* p) {
    return p->topo == NULL;
}

void empilhar(Pilha* p, char elemento) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novoNodo->valor = elemento;
    novoNodo->proximo = p->topo;
    p->topo = novoNodo;
}

char desempilhar(Pilha* p) {
    if (estaVazia(p)) {
        printf("Subfluxo de pilha\n");
        exit(EXIT_FAILURE);
    }
    Nodo* temp = p->topo;
    char elemento = temp->valor;
    p->topo = temp->proximo;
    free(temp);
    return elemento;
}

char topo(Pilha* p) {
    if (estaVazia(p)) {
        printf("Subfluxo de pilha\n");
        exit(EXIT_FAILURE);
    }
    return p->topo->valor;
}

int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedencia(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return -1;
}

void infixParaPostfix(char *expressao, char *resultado) {
    Pilha pilha;
    inicializar(&pilha);

    int tamanho = strlen(expressao);
    int j = 0;

    for (int i = 0; i < tamanho; i++) {
        char atual = expressao[i];

        if (isalnum(atual)) {
            resultado[j++] = atual;
        } else if (atual == '(') {
            empilhar(&pilha, atual);
        } else if (atual == ')') {
            while (!estaVazia(&pilha) && topo(&pilha) != '(') {
                resultado[j++] = desempilhar(&pilha);
            }
            if (!estaVazia(&pilha) && topo(&pilha) != '(') {
                printf("Expressão inválida\n");
                exit(EXIT_FAILURE);
            } else {
                desempilhar(&pilha);
            }
        } else {
            while (!estaVazia(&pilha) && precedencia(atual) <= precedencia(topo(&pilha))) {
                resultado[j++] = desempilhar(&pilha);
            }
            empilhar(&pilha, atual);
        }
    }

    while (!estaVazia(&pilha)) {
        resultado[j++] = desempilhar(&pilha);
    }

    resultado[j] = '\0'; 
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); 

    char resultados[N][TAMANHO_MAXIMO]; 

    for (int i = 0; i < N; i++) {
        char expressao[TAMANHO_MAXIMO];
        fgets(expressao, TAMANHO_MAXIMO, stdin);
        infixParaPostfix(expressao, resultados[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("%s", resultados[i]);
    }

    return 0;
}
