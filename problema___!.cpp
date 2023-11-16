#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 7

void llenarMatrizAleatoria(int matriz[FILAS][COLUMNAS]) {
    int i, j;

    srand(time(NULL));

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void imprimirMatriz(int matriz[FILAS][COLUMNAS]) {
    int i, j;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void calcularSumas(int matriz[FILAS][COLUMNAS]) {
    int i, j;
    int sumaDiagonalPrincipal = 0, sumaPrimeraFila = 0, sumaUltimaColumna = 0;
    int sumaTriangularSuperior = 0, sumaTriangularInferior = 0;
    int sumaFilasPares[FILAS] = {0};
    int sumaColumnasImpares[COLUMNAS] = {0};
    int sumaTotalFilasPares = 0, sumaTotalColumnasImpares = 0;

    
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
           
            if (i == j) {
                sumaDiagonalPrincipal += matriz[i][j];
            }

         
            if (i == 0) {
                sumaPrimeraFila += matriz[i][j];
            }

       
            if (j == COLUMNAS - 1) {
                sumaUltimaColumna += matriz[i][j];
            }

       
            if (i <= j) {
                sumaTriangularSuperior += matriz[i][j];
            }

      
            if (i >= j) {
                sumaTriangularInferior += matriz[i][j];
            }

        
            if (i % 2 == 0) {
                sumaFilasPares[i] += matriz[i][j];
            }

           
            if (j % 2 != 0) {
                sumaColumnasImpares[j] += matriz[i][j];
            }
        }
    }

    
    for (i = 0; i < FILAS; i++) {
        if (i % 2 == 0) {
            printf("Suma fila %d: %d\n", i + 1, sumaFilasPares[i]);
            sumaTotalFilasPares += sumaFilasPares[i];
        }
    }
    printf("Suma total de filas impares: %d\n\n", sumaTotalFilasPares);
    printf("-----------------------------------------------\n");

    for (j = 0; j < COLUMNAS; j++) {
        if (j % 2 != 0) {
            printf("Suma columna %d: %d\n", j + 1, sumaColumnasImpares[j]);
            sumaTotalColumnasImpares += sumaColumnasImpares[j];
        }
    }
    printf("Suma total de columnas pares: %d\n", sumaTotalColumnasImpares);
    printf("-----------------------------------------------\n");
 
    printf("Suma primera fila 1: %d\n", sumaPrimeraFila);
    printf("Suma ultima columna 7: %d\n", sumaUltimaColumna);
    printf("Suma diagonal principal: %d\n", sumaDiagonalPrincipal);
    printf("-----------------------------------------------\n");
	printf("Suma diagonal principal: %d\n", sumaDiagonalPrincipal);
	printf("Suma triangular superior: %d\n", sumaTriangularSuperior);
    printf("-----------------------------------------------\n");
	printf("Suma diagonal principal: %d\n", sumaDiagonalPrincipal);
	printf("Suma triangular inferior: %d\n", sumaTriangularInferior);
}

int main() {
    int matriz[FILAS][COLUMNAS];

    llenarMatrizAleatoria(matriz);

    printf("Matriz aleatoria:\n");
    imprimirMatriz(matriz);

    calcularSumas(matriz);

    return 0;
}

