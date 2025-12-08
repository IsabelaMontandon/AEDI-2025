#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool visitado[32];
int V, E;
int M[32][32];

bool DFS(int v, int lvl) {
  visitado[v] = true;

  bool imprimiu = false;
  for (int i = 0; i < V; ++i) {
    if (M[v][i]) {
      imprimiu = true;
      for (int j = 0; j < lvl; ++j) {
        printf("  ");
      }
      printf("%d-%d", v, i);

      if (!visitado[i]) {
        printf(" pathR(G,%d)\n", i);
        DFS(i, lvl + 1);
      } else {
        printf("\n");
      }
    }
  }

  return imprimiu;
}

int main(void) {
  int T, x, y, k;

  scanf("%d", &T);
  k = 0;

  while (T--) {
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; ++i) {
      visitado[i] = false;
    }
    memset(M, 0, sizeof(M));

    for (int i = 0; i < E; ++i) {
      scanf("%d %d", &x, &y);
      M[x][y] = 1;
    }

    printf("Caso %d:\n", ++k);

    for (int i = 0; i < V; ++i) {
      if (!visitado[i]) {
        if (DFS(i, 1)) {
          printf("\n");
        }
      }
    }
  }

  return 0;
}
