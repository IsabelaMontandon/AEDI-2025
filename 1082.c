#include <stdio.h>
#include <stdlib.h>

int compararInteiros(const void *a, const void *b) {
  return (*(const int *)a - *(const int *)b);
}

void buscaEmProfundidade(int *marcacaoComponentes, int **matrizAdjacencia, int totalVertices, int idComponente, int verticeAtual) {
  int proximoVertice;
  marcacaoComponentes[verticeAtual] = idComponente;

  for (proximoVertice = 0; proximoVertice < totalVertices; ++proximoVertice) {
    if (matrizAdjacencia[verticeAtual][proximoVertice] > 0 &&
        marcacaoComponentes[proximoVertice] == 0) {
      buscaEmProfundidade(marcacaoComponentes, matrizAdjacencia, totalVertices, idComponente, proximoVertice);
    }
  }
}

int main(void) {
  int quantidadeCasos;
  int totalVertices, totalArestas;
  int tamanhoComponente, quantidadeComponentes;
  int *marcacaoComponentes, *listaVertices;
  int **matrizAdjacencia;
  char origemChar, destinoChar;

  scanf("%d\n", &quantidadeCasos);

  for (int indiceCaso = 1; indiceCaso <= quantidadeCasos; ++indiceCaso) {
    scanf("%d %d\n", &totalVertices, &totalArestas);

    matrizAdjacencia = (int **)malloc(totalVertices * sizeof(int *));
    for (int linha = 0; linha < totalVertices; ++linha) {
      matrizAdjacencia[linha] = (int *)malloc(totalVertices * sizeof(int));
      for (int coluna = 0; coluna < totalVertices; ++coluna) {
        matrizAdjacencia[linha][coluna] = 0;
      }
    }

    for (int indiceAresta = 0; indiceAresta < totalArestas; ++indiceAresta) {
      scanf("%c %c\n", &origemChar, &destinoChar);
      matrizAdjacencia[origemChar - 'a'][destinoChar - 'a'] = 1;
      matrizAdjacencia[destinoChar - 'a'][origemChar - 'a'] = 1;
    }

    printf("Case #%d:\n", indiceCaso);

    marcacaoComponentes = (int *)malloc(totalVertices * sizeof(int));
    for (int indiceVertice = 0; indiceVertice < totalVertices; ++indiceVertice) {
      marcacaoComponentes[indiceVertice] = 0;
    }

    quantidadeComponentes = 0;

    for (int verticeBase = 0; verticeBase < totalVertices; ++verticeBase) {
      if (marcacaoComponentes[verticeBase] == 0) {
        quantidadeComponentes += 1;
        buscaEmProfundidade(marcacaoComponentes, matrizAdjacencia, totalVertices, quantidadeComponentes, verticeBase);

        tamanhoComponente = 0;
        listaVertices = (int *)malloc(totalVertices * sizeof(int));
        for (int indiceVertice = 0; indiceVertice < totalVertices; ++indiceVertice) {
          if (marcacaoComponentes[indiceVertice] == quantidadeComponentes) {
            listaVertices[tamanhoComponente++] = indiceVertice;
          }
        }

        qsort(listaVertices, tamanhoComponente, sizeof(int), compararInteiros);

        for (int indiceLista = 0; indiceLista < tamanhoComponente; ++indiceLista) {
          printf("%c,", listaVertices[indiceLista] + 'a');
        }
        printf("\n");

        free(listaVertices);
      }
    }

    printf("%d connected components\n\n", quantidadeComponentes);

    free(marcacaoComponentes);
    for (int linha = 0; linha < totalVertices; ++linha) {
      free(matrizAdjacencia[linha]);
    }
    free(matrizAdjacencia);
  }

  return 0;
}
