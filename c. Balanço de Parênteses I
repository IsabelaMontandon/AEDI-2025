#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    char valor;
    struct cel *seg;
} celula;

void Empilha(celula **topo, char valor) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->seg = *topo;
    *topo = nova;
}

char Desempilha(celula **topo) {
    celula *q = *topo;
    char valor = q->valor;
    *topo = q->seg;
    free(q);
    return valor;
}

int VerificaParenteses(char expressao[]) {
    celula *pilha = NULL;
    int i = 0;

    while (expressao[i] != '\0') {
        if (expressao[i] == '(') {
            Empilha(&pilha, '(');
        } else if (expressao[i] == ')') {
            if (pilha == NULL || Desempilha(&pilha) != '(') {
                return 0;
            }
        }
        i++;
    }

    if (pilha != NULL) {
        return 0;
    }

    return 1;
}

int main() {
    char expressao[1001];

    while (scanf("%[^\n]%*c", expressao) != EOF) {
        if (VerificaParenteses(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
        if (expressao[0] == '\0') {
            break;
        }
    }

    return 0;
}
