#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    char **lista = (char **)malloc(n * sizeof(char *));
    
    for (int i = 0; i < n; i++) {
        lista[i] = (char *)malloc(21 * sizeof(char));
        scanf("%s", lista[i]);
    }

    qsort(lista, n, sizeof(char *), compare);

    char *aluno = lista[k - 1];

    printf("%s\n", aluno);

    for (int i = 0; i < n; i++) {
        free(lista[i]);
    }
    free(lista);

    return 0;
}
