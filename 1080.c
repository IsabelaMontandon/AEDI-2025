#include <stdio.h>

int main() {
    int numeros[100];
    int maior_numero, indice_maior_numero;
    for (int i = 0; i < 100; i++) {
        scanf("%d", &numeros[i]);
    }
    maior_numero = numeros[0];
    indice_maior_numero = 1;
    for (int i = 1; i < 100; i++) {
        if (numeros[i] > maior_numero) {
            maior_numero = numeros[i];
            indice_maior_numero = i + 1;
        }
    }
    printf("%d\n%d\n", maior_numero, indice_maior_numero);
    return 0;
}
