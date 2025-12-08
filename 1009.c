#include <stdio.h>
 
int main() {
    char nome [10];
    double salario, montante, total;
    scanf("%s", &nome);
    scanf("%lf %lf", &salario, &montante);
    total = salario + montante*0.15;
    printf("TOTAL = R$ %.2lf\n", total);
    return 0;
}
