#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0
#define MAX_TAMANHO 40050
#define MAX_TAMANHO_P 40000

typedef struct {
    int origem, destino, peso;
} Aresta;

Aresta grafo[MAX_TAMANHO];
int pais[MAX_TAMANHO_P];

int compararArestas(Aresta *, Aresta *);
int executarKruskal(int);
int encontrarComponente(int);

int main(int argc, char **argv)
{
    int numRoteadores, numArestas, i;

    while (scanf("%d %d", &numRoteadores, &numArestas), numRoteadores && numArestas)
    {
        memset(grafo, 0, sizeof(grafo));
        memset(pais, 0, sizeof(pais));

        for (i = 0; i < numArestas; ++i)
            scanf("%d %d %d", &grafo[i].origem, &grafo[i].destino, &grafo[i].peso);

        qsort(grafo, numArestas, sizeof(Aresta), compararArestas);

        for (i = 1; i <= numRoteadores; ++i)
            pais[i] = i;

        printf("%d\n", executarKruskal(numArestas));
    }

    return 0;
}

int compararArestas(Aresta *a, Aresta *b)
{
    return a->peso - b->peso;
}

int encontrarComponente(int i)
{
    if (i == pais[i])
        return i;
    return encontrarComponente(pais[i]);
}

int executarKruskal(int numArestas)
{
    int i, custoTotal, componenteOrigem, componenteDestino;

    custoTotal = 0;

    for (i = 0; i < numArestas; ++i)
    {
        componenteOrigem = encontrarComponente(grafo[i].origem);
        componenteDestino = encontrarComponente(grafo[i].destino);

        if (componenteOrigem != componenteDestino)
        {
            pais[componenteOrigem] = pais[componenteDestino];
            custoTotal += grafo[i].peso;
        }
    }

    return custoTotal;
}
