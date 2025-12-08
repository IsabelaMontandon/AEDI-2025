#include <stdio.h>

int main() {
    int num_testes, quantidade, total_animais = 0;
    int total_coelhos = 0, total_ratos = 0, total_sapos = 0;
    char tipo_animal;
    float perc_coelhos, perc_ratos, perc_sapos;
    
    scanf("%d", &num_testes);
    for (int i = 0; i < num_testes; i++) {
        scanf("%d %c", &quantidade, &tipo_animal);
        total_animais += quantidade;
        if (tipo_animal == 'C') {
            total_coelhos += quantidade;
        } else if (tipo_animal == 'R') {
            total_ratos += quantidade;
        } else if (tipo_animal == 'S') {
            total_sapos += quantidade;
        }
    }
    
    perc_coelhos = (total_coelhos * 100.0) / total_animais;
    perc_ratos = (total_ratos * 100.0) / total_animais;
    perc_sapos = (total_sapos * 100.0) / total_animais;
    
    printf("Total: %d cobaias\n", total_animais);
    printf("Total de coelhos: %d\n", total_coelhos);
    printf("Total de ratos: %d\n", total_ratos);
    printf("Total de sapos: %d\n", total_sapos);
    printf("Percentual de coelhos: %.2f %%\n", perc_coelhos);
    printf("Percentual de ratos: %.2f %%\n", perc_ratos);
    printf("Percentual de sapos: %.2f %%\n", perc_sapos);
    
    return 0;
}
