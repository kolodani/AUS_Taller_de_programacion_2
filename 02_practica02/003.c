/*
    Practica 02
    Ejercicio 03 Suma de matrices NxN
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipo de funcion que reserva memoria para una matriz
int ** reservarMemoria (int dimension);
// Prototipo de funcion para llenar de valores aleatorios una matriz
void llenarMatriz (int ** matriz, int dimension);
// Prototipo de funcion para la suma de dos matrices
void sumaMatrices (int ** matriz1, int ** matriz2, int ** matrizR, int dimension);
// Prototipo de funcion para imprimir una matriz
void imprimirMatriz (int ** matriz, int dimension);
// Prototipo de funcion para liberar memoria de una matriz
void liberarMemoria (int ** matriz, int dimension);

int main()
{
    // Declaracion de variables
    int dimension, i;
    int ** matrizA, ** matrizB, ** matrizSuma;
    // Solicitar la dimensión de las matrices por teclado
    printf("Bienvenido a suma de matrices\n");
    printf("Ingrese la dimension que tiene cada matriz:\n");
    printf("> ");
    scanf("%d", &dimension);;
    // Solicitar memoria para el almacenamiento
    matrizA = reservarMemoria(dimension);
    matrizB = reservarMemoria(dimension);
    matrizSuma = reservarMemoria(dimension);
    // Llenar las matrices con valores aleatorios
    llenarMatriz(matrizA, dimension);
    llenarMatriz(matrizB, dimension);
    // Sumar las matrices.
    sumaMatrices(matrizA, matrizB, matrizSuma, dimension);
    // Mostrar el resultado
    printf("Matriz A:\n");
    imprimirMatriz(matrizA, dimension);
    printf("Matriz B:\n");
    imprimirMatriz(matrizB, dimension);
    printf("Matriz Suma:\n");
    imprimirMatriz(matrizSuma, dimension);
    // Liberar memoria
    liberarMemoria(matrizA, dimension);
    liberarMemoria(matrizB, dimension);
    liberarMemoria(matrizSuma, dimension);
    
    return 0;
}

// Funcion que reserva memoria para una matriz
int ** reservarMemoria (int dimension)
{
    int i;
    int ** matriz;
    matriz = (int **)malloc(dimension * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Error al solicitar memoria para la matriz");
        return NULL;
    }
    for (i = 0; i < dimension; i++)
    {
        matriz[i] = (int *)malloc(dimension * sizeof(int));
        if (matriz[i] == NULL)
        {
            printf("Error al solicitar memoria para la matriz");
            return NULL;
        }
    }
    return matriz;
}

void llenarMatriz(int **matriz, int dimension)
{
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
}

void sumaMatrices(int **matriz1, int **matriz2, int **matrizR, int dimension)
{
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            matrizR[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void imprimirMatriz(int **matriz, int dimension)
{
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void liberarMemoria(int **matriz, int dimension)
{
    int i;
    for (i = 0; i < dimension; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}