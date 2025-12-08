#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char valor;
    struct cel *seg;
} Celula;

void Empilha(Celula **topo, char valor) {
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    nova->valor = valor;
    nova->seg = *topo;
    *topo = nova;
}

char Desempilha(Celula **topo) {
    if (*topo == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    Celula *q = *topo;
    char valor = q->valor;
    *topo = q->seg;
    free(q);
    return valor;
}

int main() {
    int numVagao, i, j;
    char entrada[27], saida[27];
    Celula *pilha;

    while (scanf("%d", &numVagao) && numVagao != 0) {
        for (i = 0; i < numVagao; i++) {
            scanf("%s", &entrada[i]);
        }
        
        for (i = 0; i < numVagao; i++) {
            scanf("%s", &saida[i]);
        }

        char movimentos[2 * numVagao + 1];
        int movIndex = 0;
        int impossivel = 0;

        pilha = NULL;
        i = 0;
        j = 0;

        while (i < numVagao) {
            Empilha(&pilha, entrada[i]);
            movimentos[movIndex++] = 'I';
            while (pilha != NULL && pilha->valor == saida[j]) {
                Desempilha(&pilha);
                movimentos[movIndex++] = 'R';
                j++;
            }
            i++;
        }

        while (pilha != NULL && pilha->valor == saida[j]) {
            Desempilha(&pilha);
            movimentos[movIndex++] = 'R';
            j++;
        }

        movimentos[movIndex] = '\0';

        if (j == numVagao) {
            printf("%s\n", movimentos);
        } else {
            printf("%s Impossible\n", movimentos);
        }
    }

    return 0;
}
