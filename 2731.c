#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CIDADES 16
#define MAX_ESTRADAS 226

typedef struct {
    int cidade;
    int tempo;
} Aresta;

typedef struct {
    Aresta arestas[MAX_ESTRADAS];
    int num_arestas;
} Cidade;

Cidade cidades[MAX_CIDADES];
int distancias[MAX_CIDADES];
int anterior[MAX_CIDADES];
int visitado[MAX_CIDADES];

void dijkstra(int origem, int cidades_count) {
    for (int i = 1; i <= cidades_count; i++) {
        distancias[i] = INT_MAX;
        visitado[i] = 0;
        anterior[i] = -1;
    }
    distancias[origem] = 0;

    for (int i = 1; i <= cidades_count; i++) {
        int u = -1;
        for (int j = 1; j <= cidades_count; j++) {
            if (!visitado[j] && (u == -1 || distancias[j] < distancias[u])) {
                u = j;
            }
        }

        if (distancias[u] == INT_MAX) break;

        visitado[u] = 1;

        for (int i = 0; i < cidades[u].num_arestas; i++) {
            int v = cidades[u].arestas[i].cidade;
            int peso = cidades[u].arestas[i].tempo;
            if (distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
                anterior[v] = u;
            }
        }
    }
}

void imprimir_caminho(int destino) {
    if (anterior[destino] == -1) {
        printf("%d", destino);
        return;
    }
    imprimir_caminho(anterior[destino]);
    printf(" %d", destino);
}

int main() {
    int C, E;

    while (scanf("%d %d", &C, &E), C != 0 && E != 0) {
        for (int i = 1; i <= C; i++) {
            cidades[i].num_arestas = 0;
        }

        for (int i = 0; i < E; i++) {
            int C1, C2, T;
            scanf("%d %d %d", &C1, &C2, &T);
            cidades[C1].arestas[cidades[C1].num_arestas++] = (Aresta){C2, T};
            cidades[C2].arestas[cidades[C2].num_arestas++] = (Aresta){C1, T};
        }

        int D;
        scanf("%d", &D);

        dijkstra(D, C);

        int tempo_viagem = distancias[1]; 

        if (tempo_viagem < 120) {
            printf("Will not be late. Travel time - %d - best way - ", tempo_viagem);
            imprimir_caminho(1);
            printf("\n");
        } else {
            printf("It will be %d minutes late. Travel time - %d - best way - ", tempo_viagem - 120, tempo_viagem);
            imprimir_caminho(1);
            printf("\n");
        }
    }

    return 0;
}
