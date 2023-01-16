/*
    Practica 02
    Ejercicio 04 Matriz transpuesta
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipo de funcion que reserva memoria para una matriz
int **reservarMemoria(int filas, int columnas);
// Prototipo de funcion para llenar de valores aleatorios una matriz
void llenarMatriz(int **matriz, int filas, int columnas);
// Prototipo de funcion para la transpuesta de una matriz
void transpuestaMatriz(int **matriz, int **matrizTranspuesta, int filas, int columnas);
// Prototipo de funcion para imprimir una matriz
void imprimirMatriz(int **matriz, int filas, int columnas);

int main()
{
    // Declaracion de variables
    int filas, columnas, i, j;
    int **matrizA, **matrizT;
    // Solicitar las filas y las columnas de las matrices por teclado
    printf("Bienvenido a la matriz transpuesta\n");
    printf("Ingrese la cantidad de filas de la matriz:\n");
    printf("> ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas de la matriz:\n");
    printf("> ");
    scanf("%d", &columnas);
    // Solicitar memoria para el almacenamiento
    matrizA = reservarMemoria(filas, columnas);
    matrizT = reservarMemoria(columnas, filas);
    // Llenar las matrices con valores aleatorios
    llenarMatriz(matrizA, filas, columnas);
    // Calcular la transpuesta de la matriz
    transpuestaMatriz(matrizA, matrizT, filas, columnas);
    // Imprimir las matrices
    printf("Matriz A:\n");
    imprimirMatriz(matrizA, filas, columnas);
    printf("Matriz Transpuesta:\n");
    imprimirMatriz(matrizT, columnas, filas);

    return 0;
}

int **reservarMemoria(int filas, int columnas)
{
    int i, j;
    int **matriz;
    matriz = (int **)malloc(filas * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Error al solicitar memoria para la matriz");
        return NULL;
    }
    for (i = 0; i < filas; i++)
    {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
        if (matriz[i] == NULL)
        {
            printf("Error al solicitar memoria para la matriz");
            return NULL;
        }
    }
    return matriz;
}

void llenarMatriz(int **matriz, int filas, int columnas)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
}

void transpuestaMatriz(int **matriz, int **matrizTranspuesta, int filas, int columnas)
{
    int i, j;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matrizTranspuesta[j][i] = matriz[i][j];
        }
    }
}

void imprimirMatriz(int **matriz, int filas, int columnas)
{
    int i, j;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}