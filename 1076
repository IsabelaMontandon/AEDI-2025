#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int matrizAdjacencia[50][50];
  int quantidadeTestes, parametroX, quantidadeVertices, quantidadeArestas;
  int origem, destino;

  scanf("%d\n", &quantidadeTestes);

  for (int indiceTeste = 0; indiceTeste < quantidadeTestes; ++indiceTeste) {
    scanf("%d\n", &parametroX);

    scanf("%d %d\n", &quantidadeVertices, &quantidadeArestas);

    memset(matrizAdjacencia, 0, sizeof(matrizAdjacencia));

    for (int indiceAresta = 0; indiceAresta < quantidadeArestas; ++indiceAresta) {
      scanf("%d %d\n", &origem, &destino);
      matrizAdjacencia[origem][destino] = 1;
      matrizAdjacencia[destino][origem] = 1;
    }

    int quantidadeConexoes = 0;
    for (int linha = 0; linha < quantidadeVertices; ++linha) {
      for (int coluna = linha; coluna < quantidadeVertices; ++coluna) {
        if (matrizAdjacencia[linha][coluna] == 1) {
          ++quantidadeConexoes;
        }
      }
    }

    printf("%d\n", 2 * quantidadeConexoes);
  }

  return 0;
}
