#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um conjunto de roteadores
typedef struct {
    int *pai;
    int *rank;
    int n;
} UnionFind;

// Função para inicializar o Union-Find
UnionFind* criarUnionFind(int n) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->n = n;
    uf->pai = (int*)malloc(n * sizeof(int));
    uf->rank = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        uf->pai[i] = i;  // Cada nó é seu próprio pai inicialmente
        uf->rank[i] = 0;  // Rank inicial é 0
    }
    return uf;
}

// Função para encontrar o representante de um conjunto
int encontrar(UnionFind *uf, int x) {
    if (uf->pai[x] != x) {
        uf->pai[x] = encontrar(uf, uf->pai[x]);  // Caminhamento de compressão
    }
    return uf->pai[x];
}

// Função para unir dois conjuntos
void unir(UnionFind *uf, int x, int y) {
    int raizX = encontrar(uf, x);
    int raizY = encontrar(uf, y);

    if (raizX != raizY) {
        // União por rank
        if (uf->rank[raizX] > uf->rank[raizY]) {
            uf->pai[raizY] = raizX;
        } else if (uf->rank[raizX] < uf->rank[raizY]) {
            uf->pai[raizX] = raizY;
        } else {
            uf->pai[raizY] = raizX;
            uf->rank[raizX]++;
        }
    }
}

// Estrutura para armazenar as arestas
typedef struct {
    int v, w, p;
} Aresta;

// Função para comparar arestas (usada pela qsort)
int compararArestas(const void *a, const void *b) {
    return ((Aresta*)a)->p - ((Aresta*)b)->p;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    // Array de arestas
    Aresta arestas[C];
    
    // Lendo as arestas
    for (int i = 0; i < C; i++) {
        scanf("%d %d %d", &arestas[i].v, &arestas[i].w, &arestas[i].p);
        arestas[i].v--;  // Convertendo para índice 0
        arestas[i].w--;  // Convertendo para índice 0
    }

    // Ordenar as arestas pelo custo
    qsort(arestas, C, sizeof(Aresta), compararArestas);

    // Inicializar o Union-Find
    UnionFind *uf = criarUnionFind(R);

    int custoTotal = 0;
    int arestasUsadas = 0;

    // Kruskal
    for (int i = 0; i < C && arestasUsadas < R - 1; i++) {
        int v = arestas[i].v;
        int w = arestas[i].w;
        int p = arestas[i].p;

        // Se v e w não estão no mesmo conjunto, adicionar a aresta
        if (encontrar(uf, v) != encontrar(uf, w)) {
            unir(uf, v, w);
            custoTotal += p;
            arestasUsadas++;
        }
    }

    printf("%d\n", custoTotal);

    // Liberar memória
    free(uf->pai);
    free(uf->rank);
    free(uf);

    return 0;
}
