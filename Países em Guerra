#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define VERTICES 501
#define INFINITO 999999
typedef struct {
    int quantidadeVertices;
    int quantidadeArestas;
    int rota[VERTICES][VERTICES];
} Grafo;
Grafo grafo;
void dijkstra(int verticeOrigem, int verticeDestino)
{
    int a, a0;
    int predecessores[VERTICES], fila[VERTICES];
    int custos[VERTICES];
    
    memset(predecessores, -1, sizeof(predecessores));
    memset(custos, INFINITO, sizeof(custos));
    
    fila[verticeOrigem] = verticeOrigem;
    custos[verticeOrigem] = 0;
    
    while (true)
    {
        int menorCusto = INFINITO;
        for (a = 0; a < grafo.quantidadeVertices; a++)
        {
            if (predecessores[a] == -1 && menorCusto > custos[a])
            {
                menorCusto = custos[a0 = a];
            }
        }
        if (menorCusto == INFINITO) break;
        predecessores[a0] = fila[a0];
        
        for (a = 0; a < grafo.quantidadeVertices; a++)
        {
            if (custos[a] > custos[a0] + grafo.rota[a0][a])
            {
                custos[a] = custos[a0] + grafo.rota[a0][a];
                fila[a] = a0;
            }
        }
    }
    
    if (custos[verticeDestino] < INFINITO) 
        printf("%d\n", custos[verticeDestino]);
    else 
        printf("Nao e possivel entregar a carta\n");
}
int main()
{
    memset(&grafo, 0, sizeof(grafo));
    int n, e, k, origem, destino;
    int x, y, z;
    int i, j;
    
    while (true) {
        scanf("%d %d", &n, &e);
        if (n == 0 && e == 0) break;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                grafo.rota[i][j] = INFINITO;
            }
        }
        for (i = 0; i < e; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            if (grafo.rota[y][x] != INFINITO)
            {
                grafo.rota[x][y] = 0;
                grafo.rota[y][x] = 0;
            }
            else
            {
                grafo.rota[x][y] = z;
            }
        }
        grafo.quantidadeVertices = n + 1;
        grafo.quantidadeArestas = e;
        scanf("%d", &k);
        for (i = 0; i < k; i++)
        {
            scanf("%d %d", &origem, &destino);
            dijkstra(origem, destino);
        }
        printf("\n");
    }
    return 0;
}
