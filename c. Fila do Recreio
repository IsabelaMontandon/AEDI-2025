#include <stdio.h>
#include <stdlib.h>

void intercalaVetor(int inicio, int meio, int fim, int vet[]) {
    int contadorInicio, contadorMeio, contador = 0, *vet_temp;

    vet_temp = (int*)malloc((fim - inicio) * sizeof(int));
    contadorInicio = inicio;
    contadorMeio = meio;

    while (contadorInicio < meio && contadorMeio < fim) {
        if (vet[contadorInicio] >= vet[contadorMeio]) vet_temp[contador++] = vet[contadorInicio++];
        else vet_temp[contador++] = vet[contadorMeio++];
    }

    while (contadorInicio < meio) vet_temp[contador++] = vet[contadorInicio++];
    while (contadorMeio < fim) vet_temp[contador++] = vet[contadorMeio++];

    for (contadorInicio = inicio; contadorInicio < fim; contadorInicio++) {
        vet[contadorInicio] = vet_temp[contadorInicio - inicio];
    }

    free(vet_temp);
}

void mergeSort(int inicio, int fim, int vet[]) {
    int meio;

    if (inicio < fim - 1) {
        meio = (inicio + fim)/2;

        mergeSort(inicio, meio, vet);
        mergeSort(meio, fim, vet);
        intercalaVetor(inicio, meio, fim, vet);
    }
}

int main() {
    int testes, alunos, naoMudaram, i;
    int *fila, *filaAux;

    scanf("%d", &testes);
    fila = (int*)malloc(sizeof(int));
    filaAux = (int*)malloc(sizeof(int));

    while (testes != 0) {
        naoMudaram = 0;
        scanf("%d", &alunos);
        fila = (int*)realloc(fila, sizeof(int) * alunos);
        filaAux = (int*)realloc(filaAux, sizeof(int) * alunos);

        for (i = 0; i < alunos; i++) {
            scanf("%d", &fila[i]);
            filaAux[i] = fila[i];
        }

        mergeSort(0, alunos, fila);

        for (i = 0; i < alunos; i++) {
            if (fila[i] == filaAux[i]) naoMudaram++;
        }

        printf("%d\n", naoMudaram);

        testes--;
    }
}
