#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() 
{
    unsigned short casos, pessoas;
    char palavraAtual[21], palavraAnterior[21];
    bool ingles;

    scanf("%hu", &casos);

    while (casos--)
    {
        scanf("%hu", &pessoas);

        scanf(" %s", palavraAtual);

        pessoas--;
        ingles = false;
        strcpy(palavraAnterior, palavraAtual);

        while (pessoas--)
        {
            if (strcmp(palavraAtual, palavraAnterior) != 0 && ingles == false)
                ingles = true;
            else
                strcpy(palavraAnterior, palavraAtual);

            scanf(" %s", palavraAtual);
        }

        if (ingles)
            printf("ingles\n");
        else
            printf("%s\n", palavraAtual);

        ingles = false;
    }

    return 0; 
}
