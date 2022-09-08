/*
    Practica 02
    Ejercicio 02 Producto escalar
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipo de funcion para calcular el producto escalar de una matriz
int ** productoEscalar (int filas, int columnas, int escalar, int ** matriz);
// Prototipo de funcion para imprimir una matriz
void imprimirMatriz (int filas, int columnas, int ** matriz);
// Prototipo de funcion para liberar memoria de una matriz
void liberarMatriz (int filas, int ** matriz);

int main()
{
    // Declaracion de variables
    int escalar, filas, columnas, i, j;
    int **matriz, **matrizEscalar;
    
    // Solicitar el valor escalar y la dimensión de la matriz por teclado.
    printf("Ingrese el valor escalar:\n");
    printf("> ");
    scanf("%d", &escalar);
    printf("Ingrese la cantidad de filas:\n");
    printf("> ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas:\n");
    printf("> ");
    scanf("%d", &columnas);
    
    // Solicitar memoria para el almacenamiento.
    matriz = (int **)malloc(filas * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Error al solicitar memoria para la matriz");
        return EXIT_FAILURE;
    }
    for (i = 0; i < filas; i++)
    {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
        if (matriz[i] == NULL)
        {
            printf("Error al solicitar memoria para la matriz");
            return EXIT_FAILURE;
        }
    }
    
    matrizEscalar = (int **)malloc(filas * sizeof(int *));
    if (matrizEscalar == NULL)
    {
        printf("Error al solicitar memoria para la matriz");
        return EXIT_FAILURE;
    }
    for (i = 0; i < filas; i++)
    {
        matrizEscalar[i] = (int *)malloc(columnas * sizeof(int));
        if (matrizEscalar[i] == NULL)
        {
            printf("Error al solicitar memoria para la matriz");
            return EXIT_FAILURE;
        }
    }
    // Llenar la matriz con valores aleatorios.
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
    
    /*
    // realizo el producto escalar
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matrizEscalar[i][j] = matriz[i][j] * escalar;
        }
    }
    */
    
    matrizEscalar = productoEscalar(filas, columnas, escalar, matriz);
    /*
    // Imprimir la matriz
    printf("Matriz original:\n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    // Imprimir la matriz escalar
    printf("Matriz escalar:\n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("%d ", matrizEscalar[i][j]);
        }
        printf("\n");
    }
    */
    // Imprimir las matrices
    printf("Matriz original:\n");
    imprimirMatriz(filas, columnas, matriz);
    printf("Matriz escalar:\n");
    imprimirMatriz(filas, columnas, matrizEscalar);
    
    /*
    // Liberar memoria
    for (i = 0; i < filas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    
    for (i = 0; i < filas; i++)
    {
        free(matrizEscalar[i]);
    }
    free(matrizEscalar);
    */
    // Liberar memoria
    liberarMatriz(filas, matriz);
    liberarMatriz(filas, matrizEscalar);
    return 0;
}

int ** productoEscalar (int filas, int columnas, int escalar, int ** matriz)
{
    int i, j;
    int **matrizesca;
    matrizesca = (int **)malloc(filas * sizeof(int *));
    if (matrizesca == NULL)
    {
        printf("Error al solicitar memoria para la matriz");
        return matrizesca = NULL;
    }
    for (i = 0; i < filas; i++)
    {
        matrizesca[i] = (int *)malloc(columnas * sizeof(int));
        if (matrizesca[i] == NULL)
        {
            printf("Error al solicitar memoria para la matriz");
            return matrizesca = NULL;
        }
    }
    
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matrizesca[i][j] = matriz[i][j] * escalar;
        }
    }
    
    return matrizesca;
}

void imprimirMatriz (int filas, int columnas, int ** matriz)
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

void liberarMatriz (int filas, int ** matriz)
{
    int i;
    for (i = 0; i < filas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}