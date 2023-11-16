#include <stdio.h>

#define ORDEN 3

void imprimirMatriz(int matriz[ORDEN][ORDEN]) {
    int i, j;

    for (i = 0; i < ORDEN; i++) {
        for (j = 0; j < ORDEN; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}


void imprimirSumas(int sumasFilas[ORDEN], int sumasColumnas[ORDEN],
                   int sumaDiagonalPrincipal, int sumaDiagonalSecundaria) {
    printf("Sumas:\n");
    for (int i = 0; i < ORDEN; i++) {
        printf("Suma fila %d: %d\n", i + 1, sumasFilas[i]);
    }

    for (int j = 0; j < ORDEN; j++) {
        printf("Suma columna %d: %d\n", j + 1, sumasColumnas[j]);
    }

    printf("Suma diagonal principal: %d\n", sumaDiagonalPrincipal);
    printf("Suma diagonal secundaria: %d\n", sumaDiagonalSecundaria);
}


int esMatrizMagica(int matriz[ORDEN][ORDEN]) {
    
    int sumasFilas[ORDEN] = {0};
    int sumasColumnas[ORDEN] = {0};
    int sumaDiagonalPrincipal = 0;
    int sumaDiagonalSecundaria = 0;

    for (int i = 0; i < ORDEN; i++) {
        for (int j = 0; j < ORDEN; j++) {
            sumasFilas[i] += matriz[i][j];
            sumasColumnas[j] += matriz[i][j];

            if (i == j) {
                sumaDiagonalPrincipal += matriz[i][j];
            }

            if (i + j == ORDEN - 1) {
                sumaDiagonalSecundaria += matriz[i][j];
            }
        }
    }

    
    printf("Matriz ingresada:\n");
    imprimirMatriz(matriz);
    imprimirSumas(sumasFilas, sumasColumnas, sumaDiagonalPrincipal, sumaDiagonalSecundaria);

    
    for (int i = 1; i < ORDEN; i++) {
        if (sumasFilas[i] != sumasFilas[0] || sumasColumnas[i] != sumasColumnas[0]) {
            return 0;  
        }
    }

    if (sumaDiagonalPrincipal != sumasFilas[0] || sumaDiagonalSecundaria != sumasFilas[0]) {
        return 0; 
    }

    return 1; 
}

int main() {
    int matriz[ORDEN][ORDEN];
    int i, j;

  
    printf("Ingrese los elementos de la matriz de 3x3:\n");
    for (i = 0; i < ORDEN; i++) {
        for (j = 0; j < ORDEN; j++) {
            printf("Ingrese valor para (%d, %d): ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

  
    if (esMatrizMagica(matriz)) {
        printf("La matriz es magica.\n");
    } else {
        printf("La matriz no es magica.\n");
    }

    return 0;
}
