#include <stdio.h>
#include <stdlib.h>

struct NoDaArvore {
    int altura;
    int contagem;
    struct NoDaArvore *esquerda;
    struct NoDaArvore *direita;
};
int primeiroDaLinha;

struct NoDaArvore* novoNo(int altura) {
    struct NoDaArvore* no = (struct NoDaArvore*)malloc(sizeof(struct NoDaArvore));
    no->altura = altura;
    no->contagem = 1;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

struct NoDaArvore* insereNaArvore(struct NoDaArvore* raiz, int altura) {
    if (raiz == NULL) {
        return novoNo(altura);
    }
    if (altura < raiz->altura) {
        raiz->esquerda = insereNaArvore(raiz->esquerda, altura);
    }
    else if (altura > raiz->altura) {
        raiz->direita = insereNaArvore(raiz->direita, altura);
    }
    else {
        raiz->contagem++;
    }
    return raiz;
}

void mostraArvoreEmOrdem(struct NoDaArvore* raiz) {
    if (raiz == NULL) {
        return;
    }

    mostraArvoreEmOrdem(raiz->esquerda);
  
    for (int i = 0; i < raiz->contagem; i++) {
        if (primeiroDaLinha == 1) {
            printf("%d", raiz->altura);
            primeiroDaLinha = 0;
        } else {
            printf(" %d", raiz->altura);
        }
    }
    mostraArvoreEmOrdem(raiz->direita);
}

void limpaArvore(struct NoDaArvore* raiz) {
    if (raiz == NULL) {
        return;
    }
    limpaArvore(raiz->esquerda);
    limpaArvore(raiz->direita);
    free(raiz);
}

int main() {
    int numeroDeTestes;
    scanf("%d", &numeroDeTestes);

    for (int i = 0; i < numeroDeTestes; i++) {  
        struct NoDaArvore* raizDaArvore = NULL;
        int quantidadeDePessoas;   
        scanf("%d", &quantidadeDePessoas);

        for (int j = 0; j < quantidadeDePessoas; j++) {
            int alturaAtual;
            scanf("%d", &alturaAtual);
            raizDaArvore = insereNaArvore(raizDaArvore, alturaAtual);
        }
        primeiroDaLinha = 1;   
        mostraArvoreEmOrdem(raizDaArvore);
        printf("\n");

        limpaArvore(raizDaArvore);
    }

    return 0;
}
