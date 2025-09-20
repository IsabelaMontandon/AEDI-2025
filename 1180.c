#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int valor, menor_valor, posicao;

    scanf("%d", &menor_valor);
    posicao = 0;

    for (int i = 1; i < N; i++) {
        scanf("%d", &valor);
        if (valor < menor_valor) {
            menor_valor = valor;
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
