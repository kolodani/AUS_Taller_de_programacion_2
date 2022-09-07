/*
    Practica 02
    Ejercicio 02 Producto escalar
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipo de funcion que calcula el producto escalar
int ** producto_escalar_matriz (int filas, int columnas, int escalar, int ** matriz);
void imprimir_matriz (int filas, int columnas, int ** matriz);

int main()
{
    // Declaracion de variables
    int escalar, filas, columnas, i, j;
    int **matriz;    // Puntero a puntero inicializado en NULL
    int **matrizEscalar;   // Puntero a puntero inicializado en NULL
    
    // Solicitar el valor escalar y la dimension de la matriz por teclado
    printf("Bienvenido al programa que calcula el producto escalar de una matriz\n");
    printf("Ingrese el valor escalar:\n");
    printf("> ");
    scanf("%d", &escalar);
    printf("Ingrese la dimension de la matriz:\n");
    printf("Ingrese el numero de filas:\n");
    printf("> ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas:\n");
    printf("> ");
    scanf("%d", &columnas);
    
    // Solicitar memoria para el almacenamiento de la matriz
    matriz = (int **) malloc(filas * sizeof(int *));
    if (matriz == NULL) {
        printf("No se pudo reservar memoria\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < filas; i++) {
        matriz[i] = (int *) malloc(columnas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("No se pudo reservar memoria\n");
            return EXIT_FAILURE;
        }
    }
    // Llenar la matriz con valores aleatorios
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matriz[i][j] = i + j;
        }
    }
    
    // Llamar a la funcion que calcula el producto escalar
    matrizEscalar = producto_escalar_matriz(filas, columnas, escalar, matriz);
    
    // Imprimir la matriz original
    printf("Matriz original: ");
    imprimir_matriz(filas, columnas, matriz);
    // Imprimir la matriz Escalar
    printf("Matriz escalar: ");
    imprimir_matriz(filas, columnas, matrizEscalar);
    
    // Liberar la memoria reservada para la matriz
    for (i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    return 0;
}

// Funcion que calcula el producto escalar
int **producto_escalar_matriz(int filas, int columnas, int escalar, int **matriz)
{
    int i, j;
    int **matrizEscalar = NULL;   // Puntero a puntero inicializado en NULL
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; i++)
        {
            matrizEscalar[i][j] = matriz[i][j] * escalar;
        }
    }
    return matrizEscalar;
}

void imprimir_matriz(int filas, int columnas, int **matriz)
{
    int i, j;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; i++)
        {
            printf("%d ", matriz[i][j]);
        }
    }
}