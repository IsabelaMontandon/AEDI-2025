#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int i, numA, numB;

    scanf("%d", &numA);
    int vetorA[numA];
    scanf("%d", &numB);
    int vetorB[numB];
    
    for(i = 0; i < numA; i++)
        scanf("%d", &vetorA[i]);

    for(i = 0; i < numB; i++)
        scanf("%d", &vetorB[i]);
    
    int resultado[numA];
    int t = 0;
    
    while(t < numB) 
    {
        if(t < numA)
        {
            resultado[t] = vetorB[t] * vetorA[t];
            t++;
        }
        else
        {
            int valorMinimo = resultado[0];
            int indiceMinimo = 0;
            
            for(i = 0; i < numA; i++)
                if(valorMinimo > resultado[i])
                {
                    valorMinimo = resultado[i];
                    indiceMinimo = i;
                }
                
            resultado[indiceMinimo] += vetorB[t] * vetorA[indiceMinimo];
            t++;
        }
    }
    
    int valorMaximo = resultado[0];
    for(i = 0; i < numA; i++)
        if(valorMaximo < resultado[i])
            valorMaximo = resultado[i];
            
    printf("%d\n", valorMaximo);
}
