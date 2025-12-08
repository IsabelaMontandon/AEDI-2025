#include <stdio.h>
#include <stdlib.h>

typedef struct Exercito {
    int soldados;
    int lado; // 0 para lado do bem, 1 para lado do mal
    struct Exercito *prox;
} Exercito;

Exercito *criar(int s, int l) {
    Exercito *novo = (Exercito *)malloc(sizeof(Exercito));
    if (novo != NULL) {
        novo->soldados = s;
        novo->lado = l;
        novo->prox = NULL;
    }
    return novo;
}

void inserir(Exercito **h, Exercito *novo) {
    if (*h == NULL) {
        *h = novo;
    } else {
        Exercito *temp = *h;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void liberar(Exercito *h) {
    Exercito *temp;
    while (h != NULL) {
        temp = h;
        h = h->prox;
        free(temp);
    }
}

int calcular_vencedor(Exercito *h) {
    int bem = 0, mal = 0;
    while (h != NULL) {
        if (h->lado == 0) {
            bem += h->soldados;
        } else {
            mal += h->soldados;
        }
        h = h->prox;
    }

    if (bem > mal) {
        return 1; // Lado do bem vence
    } else if (bem < mal) {
        return 0; // Lado do mal vence
    } else {
        return -1; // Empate
    }
}

int main() {
    int h, e, a, o, w, x;
    scanf("%d %d %d %d %d %d", &h, &e, &a, &o, &w, &x);

    Exercito *head = NULL;

    inserir(&head, criar(h, 0)); // Humanos
    inserir(&head, criar(e, 0)); // Elfos
    inserir(&head, criar(a, 0)); // Anões
    inserir(&head, criar(o, 1)); // Orcs
    inserir(&head, criar(w, 1)); // Wargs
    inserir(&head, criar(x, 0)); // Águias

    int resultado = calcular_vencedor(head);

    if (resultado == 1) {
        printf("Middle-earth is safe.\n");
    } else if (resultado == 0) {
        printf("Sauron has returned.\n");
    } else {
        printf("Bilbo will defeat the last orc or warg with Sting.\n");
    }

    liberar(head);

    return 0;
}
