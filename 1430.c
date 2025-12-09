#include <string.h>
#include <stdio.h>

double obterDuracaoNota(char nota)
{
    switch (nota)
    {
    case 'W':
        return 1.0;
    case 'H':
        return 0.5;
    case 'Q':
        return 0.25;
    case 'E':
        return 0.125;
    case 'S':
        return 0.0625;
    case 'T':
        return 0.03125;
    case 'X':
        return 0.015625;
    }
}

int main()
{
    int numeroDeComposicoes;
    double duracaoTotal;
    char composicaoMusical[1000];

    while (scanf("%[^\n]\n", composicaoMusical) != EOF)
    {
        if (strcmp(composicaoMusical, "*") == 0)
            break;

        numeroDeComposicoes = 0;
        duracaoTotal = 0.0;
        for (int i = 0; i < strlen(composicaoMusical); ++i)
        {
            if (composicaoMusical[i] == '/')
            {
                if (duracaoTotal == 1.0)
                    ++numeroDeComposicoes;
                duracaoTotal = 0.0;
            }
            else
            {
                duracaoTotal += obterDuracaoNota(composicaoMusical[i]);
            }
        }

        printf("%d\n", numeroDeComposicoes);
    }

    return 0;
}
