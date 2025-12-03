#include <stdio.h>
 
int main() {
    int number, horas;
    float salary, valorhoras;
    scanf("%d %d %f", &number, &horas, &valorhoras);
    salary = horas * valorhoras;
    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2f\n", salary);
    return 0;
}
