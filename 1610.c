#include <stdio.h>
#include <stdlib.h>

typedef struct NoAdj {
    int destino;
    struct NoAdj *prox;
} NoAdj;

int contadorTempo;
int *tempoEntrada;
int *tempoSaida;
NoAdj **listaAdj;

void dfsProfundidade(int verticeAtual) {
    tempoEntrada[verticeAtual] = contadorTempo++;

    NoAdj *ptr = listaAdj[verticeAtual];
    while (ptr != NULL) {
        int vizinho = ptr->destino;
        if (tempoEntrada[vizinho] == -1) {
            dfsProfundidade(vizinho);
        }
        ptr = ptr->prox;
    }

    tempoSaida[verticeAtual] = contadorTempo++;
}

int grafoTemCiclo(int qtdVertices) {
    contadorTempo = 0;

    tempoEntrada = (int *)malloc((qtdVertices + 1) * sizeof(int));
    tempoSaida   = (int *)malloc((qtdVertices + 1) * sizeof(int));

    for (int i = 0; i <= qtdVertices; ++i) {
        tempoEntrada[i] = -1;
        tempoSaida[i]   = -1;
    }

    for (int i = 1; i <= qtdVertices; ++i) {
        if (tempoEntrada[i] == -1) {
            dfsProfundidade(i);
        }
    }

    for (int u = 1; u <= qtdVertices; ++u) {
        NoAdj *ptr = listaAdj[u];
        while (ptr != NULL) {
            int v = ptr->destino;
            if (tempoSaida[u] < tempoSaida[v]) {
                free(tempoEntrada);
                free(tempoSaida);
                return 1;
            }
            ptr = ptr->prox;
        }
    }

    free(tempoEntrada);
    free(tempoSaida);
    return 0;
}

int main(void) {
    int qtdCasos;
    int qtdVertices, qtdArestas;
    int origem, destino;

    scanf("%d", &qtdCasos);

    for (int caso = 0; caso < qtdCasos; ++caso) {
        scanf("%d %d", &qtdVertices, &qtdArestas);

        listaAdj = (NoAdj **)malloc((qtdVertices + 1) * sizeof(NoAdj *));
        for (int i = 0; i <= qtdVertices; ++i) {
            listaAdj[i] = NULL;
        }

        for (int i = 0; i < qtdArestas; ++i) {
            scanf("%d %d", &origem, &destino);

            NoAdj *novo = (NoAdj *)malloc(sizeof(NoAdj));
            novo->destino = destino;
            novo->prox = listaAdj[origem];
            listaAdj[origem] = novo;
        }

        if (grafoTemCiclo(qtdVertices)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        for (int i = 0; i <= qtdVertices; ++i) {
            NoAdj *ptr = listaAdj[i];
            while (ptr != NULL) {
                NoAdj *tmp = ptr->prox;
                free(ptr);
                ptr = tmp;
            }
        }
        free(listaAdj);
    }

    return 0;
}
