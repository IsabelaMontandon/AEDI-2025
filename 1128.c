#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 2010
char visitado[MAX_VERTICES];
char grafo[MAX_VERTICES][MAX_VERTICES];
int numVertices;
void buscaProfundidade(int);
int main(int cnt, char **vet)
{
    int numArestas, verticeU, verticeV, direcao, i, j;
    while (scanf("%d %d", &numVertices, &numArestas), numArestas && numVertices)
    {
        memset(grafo, 0, sizeof(grafo));
        for (i = 0; i < numArestas; ++i)
        {
            scanf("%d %d %d", &verticeU, &verticeV, &direcao);
            if (direcao == 1)
                grafo[verticeU][verticeV] = TRUE;
            else
                grafo[verticeU][verticeV] = grafo[verticeV][verticeU] = TRUE;
        }
        _Bool estaDesconectado = FALSE;
        for (i = 1; i <= numVertices; ++i)
        {
            memset(visitado, 0, sizeof(visitado));
            buscaProfundidade(i);
            estaDesconectado = FALSE;
            for (j = 1; j <= numVertices && !estaDesconectado; ++j)
                if (!visitado[j])
                    estaDesconectado = TRUE;
            if (estaDesconectado)
                break;
        }
        printf("%d\n", estaDesconectado ? 0 : 1);
    }
    return 0;
}
void buscaProfundidade(int verticeAtual)
{
    int verticeAdjacente;
    visitado[verticeAtual] = TRUE;
    for (verticeAdjacente = 1; verticeAdjacente <= numVertices; ++verticeAdjacente)
        if (grafo[verticeAtual][verticeAdjacente])
            if (!visitado[verticeAdjacente])
                buscaProfundidade(verticeAdjacente);
}
