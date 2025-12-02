#include <stdio.h>

int verificarLinha(int matriz[9][9], int linha) {
    int ocorrencias[10] = {0};
    for (int j = 0; j < 9; j++) {
        int num = matriz[linha][j];
        if (ocorrencias[num] == 1) { 
            return 0;
        }
        ocorrencias[num] = 1;
    }

    if (linha == 8) {
        return 1;
    }

    verificarLinha(matriz, ++linha);
}

int verificarColuna(int matriz[9][9], int coluna) {
    int ocorrencias[10] = {0}; 

    for (int i = 0; i < 9; i++) {
        int num = matriz[i][coluna];
        if (ocorrencias[num] == 1) {
            return 0;
        }
        ocorrencias[num] = 1;
    }

    if (coluna == 8) {
        return 1;
    }
    
    verificarColuna(matriz, ++coluna);
}

int verificarRegiao(int matriz[9][9], int linhaInicial, int colunaInicial) {
    int ocorrencias[10] = {0};
    for (int i = linhaInicial; i < linhaInicial + 3; i++) {
        for (int j = colunaInicial; j < colunaInicial + 3; j++) {
            int num = matriz[i][j];
            if (ocorrencias[num] == 1) {
                return 0;
            }
            ocorrencias[num] = 1;
        }
    }

    if (linhaInicial == 6 && colunaInicial == 6) {
        return 1;
    } else if (colunaInicial == 6) {
        verificarRegiao(matriz, linhaInicial + 3, 0);
    } else {
        verificarRegiao(matriz, linhaInicial, colunaInicial + 3);
    }
}

int verificarSudoku(int matriz[9][9]) {
    if (!verificarLinha(matriz, 0)) {
        return 0;
    }

    if (!verificarColuna(matriz, 0)) {
        return 0;
    }

    if (!verificarRegiao(matriz, 0, 0)) {
        return 0;
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int matriz[9][9];

        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("Instancia %d\n", instancia);
        if (verificarSudoku(matriz)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
