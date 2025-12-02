#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de pilha
typedef struct {
    int topo;
    int capacidade;
    char *vetor;
} Pilha;

// Função para criar uma nova pilha
Pilha *criarPilha(int capacidade) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->vetor = (char *)malloc(pilha->capacidade * sizeof(char));
    return pilha;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para empurrar um elemento para a pilha
void empurrar(Pilha *pilha, char item) {
    pilha->vetor[++pilha->topo] = item;
}

// Função para remover um elemento do topo da pilha
char remover(Pilha *pilha) {
    if (!pilhaVazia(pilha))
        return pilha->vetor[pilha->topo--];
    return '\0';
}

// Função para contar os diamantes possíveis
int contarDiamantes(char *s) {
    Pilha *pilha = criarPilha(strlen(s));
    int diamantes = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '<') {
            empurrar(pilha, '<');
        } else if (s[i] == '>') {
            if (!pilhaVazia(pilha) && pilha->vetor[pilha->topo] == '<') {
                diamantes++;
                remover(pilha);
            }
        }
    }

    free(pilha->vetor);
    free(pilha);
    return diamantes;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // Limpar o buffer

    char **entradas = (char **)malloc(N * sizeof(char *));
    int *resultados = (int *)malloc(N * sizeof(int));

    // Ler todas as entradas
    for (int i = 0; i < N; i++) {
        char *s = (char *)malloc(1001 * sizeof(char));
        fgets(s, 1001, stdin);
        entradas[i] = s;
        resultados[i] = contarDiamantes(s);
    }

    // Imprimir as saídas
    for (int i = 0; i < N; i++) {
        printf("%d\n", resultados[i]);
        free(entradas[i]); // Liberar memória alocada para cada entrada
    }

    free(entradas); // Liberar memória alocada para a matriz de entradas
    free(resultados); // Liberar memória alocada para o array de resultados

    return 0;
}
