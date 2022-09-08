/*
    Practica 02
    Ejercicio 01 Determinante de una matriz
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipo de funcion que reserva memoria para una matriz
int ** reservarMemoria (int dimension);
// Prototipo de funcion para llenar de valores aleatorios una matriz
void llenarMatriz (int ** matriz, int dimension);
// Prototipo de funcion para calcular el determinante de una matriz
int determinanteMatriz (int ** matriz, int dimension);
// Prototipo de funcion para imprimir una matriz
void imprimirMatriz (int ** matriz, int dimension);
// Prototipo de funcion para liberar memoria de una matriz
void liberarMemoria (int ** matriz, int dimension);

int main()
{
    // Declaracion de variables
    int dimension, i, j, determinante;
    int ** matrizA;
    // Solicitar la dimension de la matriz por teclado
    printf("Bienvenido al determinante de una matriz\n");
    printf("Ingrese la dimension de la matriz:\n");
    printf("> ");
    scanf("%d", &dimension);
    // Solicitar memoria para el almacenamiento
    matrizA = reservarMemoria(dimension);
    // Llenar la matriz con valores aleatorios
    llenarMatriz(matrizA, dimension);
    // Calcular el determinante de la matriz
    determinante = determinanteMatriz(matrizA, dimension);
    // Mostrar el resultado
    printf("Matriz A:\n");
    imprimirMatriz(matrizA, dimension);
    printf("Determinante de la matriz A: %d\n", determinante);
    // Liberar memoria
    liberarMemoria(matrizA, dimension);
    
    return 0;
}

// Funcion que reserva memoria para una matriz
int **reservarMemoria(int dimension)
{
    int i;
    int **matriz;
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

// Funcion para llenar de valores aleatorios una matriz
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

// Funcion para calcular el determinante de una matriz
int determinanteMatriz(int **matriz, int dimension)
{
    int determinante = 0;
    if (dimension == 2)
    {
        determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }
    else if (dimension == 3)
    {
        determinante = matriz[0][0] * matriz[1][1] * matriz[2][2] + matriz[0][1] * matriz[1][2] * matriz[2][0] + 
        matriz[0][2] * matriz[1][0] * matriz[2][1] - matriz[0][2] * matriz[1][1] * matriz[2][0] - matriz[0][1] * 
        matriz[1][0] * matriz[2][2] - matriz[0][0] * matriz[1][2] * matriz[2][1];
    }
    else
    {
        printf("No se puede calcular el determinante de una matriz de dimension mayor a 3");
    }
}

// Funcion para imprimir una matriz
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

// Funcion para liberar memoria de una matriz
void liberarMemoria(int **matriz, int dimension)
{
    int i;
    for (i = 0; i < dimension; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
