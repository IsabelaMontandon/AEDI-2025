#include <stdio.h>
#include <string.h>

#define MAX_DIM 2005

char matrizCelulas[MAX_DIM][MAX_DIM];
int filaLinha[MAX_DIM * MAX_DIM];
int filaColuna[MAX_DIM * MAX_DIM];

void propagarRegiao(int linhaInicial, int colunaInicial) {
    int indiceInicio = 0;
    int indiceFim = 0;

    filaLinha[indiceFim] = linhaInicial;
    filaColuna[indiceFim] = colunaInicial;
    indiceFim++;

    while (indiceInicio < indiceFim) {
        int linhaAtual = filaLinha[indiceInicio];
        int colunaAtual = filaColuna[indiceInicio];
        indiceInicio++;

        if (matrizCelulas[linhaAtual][colunaAtual] != '.') {
            continue;
        }

        matrizCelulas[linhaAtual][colunaAtual] = 'o';

        if (matrizCelulas[linhaAtual - 1][colunaAtual] == '.') {
            filaLinha[indiceFim] = linhaAtual - 1;
            filaColuna[indiceFim] = colunaAtual;
            indiceFim++;
        }
        if (matrizCelulas[linhaAtual][colunaAtual + 1] == '.') {
            filaLinha[indiceFim] = linhaAtual;
            filaColuna[indiceFim] = colunaAtual + 1;
            indiceFim++;
        }
        if (matrizCelulas[linhaAtual + 1][colunaAtual] == '.') {
            filaLinha[indiceFim] = linhaAtual + 1;
            filaColuna[indiceFim] = colunaAtual;
            indiceFim++;
        }
        if (matrizCelulas[linhaAtual][colunaAtual - 1] == '.') {
            filaLinha[indiceFim] = linhaAtual;
            filaColuna[indiceFim] = colunaAtual - 1;
            indiceFim++;
        }
    }
}

int main(void) {
    int quantidadeLinhas, quantidadeColunas, quantidadeRegioes;

    memset(matrizCelulas, 'o', sizeof(matrizCelulas));

    scanf("%d %d", &quantidadeLinhas, &quantidadeColunas);
    for (int linha = 1; linha <= quantidadeLinhas; ++linha) {
        for (int coluna = 1; coluna <= quantidadeColunas; ++coluna) {
            scanf(" %c", &matrizCelulas[linha][coluna]);
        }
    }

    quantidadeRegioes = 0;
    for (int linha = 1; linha <= quantidadeLinhas; ++linha) {
        for (int coluna = 1; coluna <= quantidadeColunas; ++coluna) {
            if (matrizCelulas[linha][coluna] == '.') {
                quantidadeRegioes++;
                propagarRegiao(linha, coluna);
            }
        }
    }

    printf("%d\n", quantidadeRegioes);

    return 0;
}
