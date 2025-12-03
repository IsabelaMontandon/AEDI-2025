#include <stdio.h>

int main() {

    int cod1, cod2, n1, n2;
    float v1, v2, pagar;
    scanf("%d %d %f\n%d %d %f", &cod1, &n1, &v1,
                                &cod2, &n2, &v2);
    pagar = n1 * v1 + n2 * v2;
    printf("VALOR A PAGAR: R$ %.2f\n", pagar);

    return 0;
}
