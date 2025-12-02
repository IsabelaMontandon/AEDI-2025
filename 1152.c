#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int *parent;
    int *rank;
    int size;
} UnionFind;

UnionFind* createUnionFind(int size) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->parent = (int*)malloc(size * sizeof(int));
    uf->rank = (int*)malloc(size * sizeof(int));
    uf->size = size;
    for (int i = 0; i < size; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

int find(UnionFind *uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]); 
    }
    return uf->parent[x];
}

void unionSets(UnionFind *uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);
    if (rootX != rootY) {
        // União por rank
        if (uf->rank[rootX] > uf->rank[rootY]) {
            uf->parent[rootY] = rootX;
        } else if (uf->rank[rootX] < uf->rank[rootY]) {
            uf->parent[rootX] = rootY;
        } else {
            uf->parent[rootY] = rootX;
            uf->rank[rootX]++;
        }
    }
}

int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int main() {
    while (1) {
        int m, n;
        scanf("%d %d", &m, &n);
        
        if (m == 0 && n == 0) break;

        Edge *edges = (Edge*)malloc(n * sizeof(Edge));
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges[i].u = x;
            edges[i].v = y;
            edges[i].weight = z;
            totalCost += z;
        }

        qsort(edges, n, sizeof(Edge), compareEdges);

        UnionFind *uf = createUnionFind(m);

        int mstCost = 0;
        int mstEdges = 0;

        for (int i = 0; i < n; i++) {
            if (find(uf, edges[i].u) != find(uf, edges[i].v)) {
                unionSets(uf, edges[i].u, edges[i].v);
                mstCost += edges[i].weight;
                mstEdges++;
                if (mstEdges == m - 1) break; // A MST está completa
            }
        }

        printf("%d\n", totalCost - mstCost);

        free(edges);
        free(uf->parent);
        free(uf->rank);
        free(uf);
    }

    return 0;
}
