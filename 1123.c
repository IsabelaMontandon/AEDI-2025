#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define INF INT_MAX
int numVertices, numArestas, cidadeDestino, cidadeInicial;
int g[1010][1010];
int custoMinimo[1010];
void inicializarInfinito() {
    for (int i = 0; i <= numVertices; i++) {
        custoMinimo[i] = INF;
        for (int j = 0; j <= numVertices; j++) g[i][j] = INF;
    }
}
int dijkstra(int origem, int destino) {
    bool visitado[1010] = {false};
    custoMinimo[origem] = 0;
    for (int cont = 0; cont < numVertices - 1; cont++) {
        int menorCusto = INF, indiceMinimo;
        for (int vertice = 0; vertice < numVertices; vertice++)
            if (!visitado[vertice] && custoMinimo[vertice] <= menorCusto)
                menorCusto = custoMinimo[vertice], indiceMinimo = vertice;
        int u = indiceMinimo;
        visitado[u] = true;
        for (int vertice = 0; vertice < numVertices; vertice++)
            if (!visitado[vertice] && g[u][vertice] != INF && custoMinimo[u] != INF
                && custoMinimo[u] + g[u][vertice] < custoMinimo[vertice])
                custoMinimo[vertice] = custoMinimo[u] + g[u][vertice];
    }
    return custoMinimo[destino];
}
int main() {
    while (scanf("%d %d %d %d", &numVertices, &numArestas, &cidadeDestino, &cidadeInicial), (numVertices || numArestas || cidadeDestino || cidadeInicial)) {
        inicializarInfinito();
        for (int i = 1; i <= numArestas; i++) {
            int verticeOrigem, verticeDestino, peso;
            scanf("%d %d %d", &verticeOrigem, &verticeDestino, &peso);
            if (verticeOrigem >= cidadeDestino && verticeDestino >= cidadeDestino) {
                g[verticeOrigem][verticeDestino] = peso;
                g[verticeDestino][verticeOrigem] = peso;
            }
            if (verticeOrigem >= cidadeDestino && verticeDestino < cidadeDestino) g[verticeOrigem][verticeDestino] = peso;
            if (verticeOrigem < cidadeDestino && verticeDestino >= cidadeDestino) g[verticeDestino][verticeOrigem] = peso;
            if (verticeOrigem < cidadeDestino && verticeDestino < cidadeDestino && abs(verticeOrigem - verticeDestino) == 1) {
                g[verticeOrigem][verticeDestino] = peso;
                g[verticeDestino][verticeOrigem] = peso;
            }
        }
        printf("%d\n", dijkstra(cidadeInicial, cidadeDestino - 1));
    }
    return 0;
}
