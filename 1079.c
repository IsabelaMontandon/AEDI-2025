#include <stdio.h>

int main() {
    int num_testes;
    scanf("%d", &num_testes);
    for (int i = 0; i < num_testes; i++) {
        float nota1, nota2, nota3;
        scanf("%f %f %f", &nota1, &nota2, &nota3);
        float media_ponderada = (nota1 * 2 + nota2 * 3 + nota3 * 5) / 10;
        printf("%.1f\n", media_ponderada);
    }
    return 0;
}
