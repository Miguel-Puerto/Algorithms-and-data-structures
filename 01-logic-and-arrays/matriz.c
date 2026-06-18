#include <stdio.h>

// Função para calcular o determinante de uma matriz 3x3
int calcularDeterminante(int matriz[3][3]) {
    return matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
         - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
         + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
}

int main() {
    int matriz[3][3];
    int determinante;

    // Solicitar ao usuário para preencher a matriz
    printf("Digite os valores para a matriz 3x3:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir a matriz
    printf("\nMatriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Calcular e exibir o determinante
    determinante = calcularDeterminante(matriz);
    printf("\nDeterminante da matriz: %d\n", determinante);

    return 0;
}
