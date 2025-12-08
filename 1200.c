#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Nodo {
    char chave;
    struct Nodo *filhoEsq;
    struct Nodo *filhoDir;
} Nodo;

bool primeiroToken;

Nodo *criarNodo(char chave) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    novo->chave = chave;
    novo->filhoEsq = NULL;
    novo->filhoDir = NULL;
    return novo;
}

Nodo *inserirChave(Nodo *raiz, char chave) {
    if (raiz == NULL) {
        return criarNodo(chave);
    }
    if (chave < raiz->chave) {
        raiz->filhoEsq = inserirChave(raiz->filhoEsq, chave);
    } else {
        raiz->filhoDir = inserirChave(raiz->filhoDir, chave);
    }
    return raiz;
}

Nodo *buscarChave(Nodo *raiz, char chave) {
    if (raiz == NULL) return NULL;
    if (chave == raiz->chave) return raiz;
    if (chave < raiz->chave) return buscarChave(raiz->filhoEsq, chave);
    return buscarChave(raiz->filhoDir, chave);
}

void percorrerInOrdem(Nodo *raiz) {
    if (raiz != NULL) {
        percorrerInOrdem(raiz->filhoEsq);
        if (primeiroToken) primeiroToken = false;
        else printf(" ");
        printf("%c", raiz->chave);
        percorrerInOrdem(raiz->filhoDir);
    }
}

void percorrerPreOrdem(Nodo *raiz) {
    if (raiz != NULL) {
        if (primeiroToken) primeiroToken = false;
        else printf(" ");
        printf("%c", raiz->chave);
        percorrerPreOrdem(raiz->filhoEsq);
        percorrerPreOrdem(raiz->filhoDir);
    }
}

void percorrerPosOrdem(Nodo *raiz) {
    if (raiz != NULL) {
        percorrerPosOrdem(raiz->filhoEsq);
        percorrerPosOrdem(raiz->filhoDir);
        if (primeiroToken) primeiroToken = false;
        else printf(" ");
        printf("%c", raiz->chave);
    }
}

void liberarArvore(Nodo *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->filhoEsq);
        liberarArvore(raiz->filhoDir);
        free(raiz);
    }
}

int main(void) {
    char comando[16];
    char caractere;
    Nodo *arvoreRaiz = NULL;

    while (scanf("%s", comando) == 1) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &caractere);
            arvoreRaiz = inserirChave(arvoreRaiz, caractere);
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &caractere);
            Nodo *resultado = buscarChave(arvoreRaiz, caractere);
            if (resultado == NULL) {
                printf("%c nao existe\n", caractere);
            } else {
                printf("%c existe\n", caractere);
            }
        } else if (strcmp(comando, "INFIXA") == 0) {
            primeiroToken = true;
            percorrerInOrdem(arvoreRaiz);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            primeiroToken = true;
            percorrerPreOrdem(arvoreRaiz);
            printf("\n");
        } else { /* POSFIXA */
            primeiroToken = true;
            percorrerPosOrdem(arvoreRaiz);
            printf("\n");
        }
    }

    liberarArvore(arvoreRaiz);
    return 0;
}
