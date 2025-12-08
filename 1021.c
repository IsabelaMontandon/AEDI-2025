#include <stdio.h>

int main() {
    float dinheiro;
    int valor, notas, moedas;

    scanf("%f", &dinheiro);
    valor = (int)(dinheiro * 100);

    printf("NOTAS:\n");
    notas = valor / 10000;
    printf("%d nota(s) de R$ 100.00\n", notas);
    valor %= 10000;

    notas = valor / 5000;
    printf("%d nota(s) de R$ 50.00\n", notas);
    valor %= 5000;

    notas = valor / 2000;
    printf("%d nota(s) de R$ 20.00\n", notas);
    valor %= 2000;

    notas = valor / 1000;
    printf("%d nota(s) de R$ 10.00\n", notas);
    valor %= 1000;

    notas = valor / 500;
    printf("%d nota(s) de R$ 5.00\n", notas);
    valor %= 500;

    notas = valor / 200;
    printf("%d nota(s) de R$ 2.00\n", notas);
    valor %= 200;

    printf("MOEDAS:\n");
    moedas = valor / 100;
    printf("%d moeda(s) de R$ 1.00\n", moedas);
    valor %= 100;

    moedas = valor / 50;
    printf("%d moeda(s) de R$ 0.50\n", moedas);
    valor %= 50;

    moedas = valor / 25;
    printf("%d moeda(s) de R$ 0.25\n", moedas);
    valor %= 25;

    moedas = valor / 10;
    printf("%d moeda(s) de R$ 0.10\n", moedas);
    valor %= 10;

    moedas = valor / 5;
    printf("%d moeda(s) de R$ 0.05\n", moedas);
    valor %= 5;

    moedas = valor / 1;
    printf("%d moeda(s) de R$ 0.01\n", moedas);

    return 0;
}
