#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *esq;
    struct No *dir;
} No;

char prefixo[64], infixo[64];
int prefixoIndice;

No* ConstroiArvore(int inL, int inR) {
    if (inL > inR) {
        return NULL;
    }

    char letra = prefixo[prefixoIndice++];

    No *no = (No *)malloc(sizeof(No));
    no->valor = letra;
    no->esq = NULL;
    no->dir = NULL;

    int infixoIndice;
    for (infixoIndice = inL; infixoIndice <= inR; ++infixoIndice) {
        if (infixo[infixoIndice] == letra) {
            break;
        }
    }

    no->esq = ConstroiArvore(inL, infixoIndice - 1);
    no->dir = ConstroiArvore(infixoIndice + 1, inR);

    return no;
}

void PosOrdem(No *no) {
    if (no != NULL) {
        PosOrdem(no->esq);
        PosOrdem(no->dir);
        putchar(no->valor);
    }
}

void LiberaArvore(No *no) {
    if (no != NULL) {
        LiberaArvore(no->esq);
        LiberaArvore(no->dir);
        free(no);
    }
}

int main(void) {
    No *raiz;

    while (scanf("%s %s", prefixo, infixo) == 2) {
        int n = (int)strlen(prefixo);
        prefixoIndice = 0;

        raiz = ConstroiArvore(0, n - 1);
        PosOrdem(raiz);
        putchar('\n');

        LiberaArvore(raiz);
    }

    return 0;
}
