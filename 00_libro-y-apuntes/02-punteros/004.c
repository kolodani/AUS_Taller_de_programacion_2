#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f, c, i, w;                                              // f = numero de filas y c = numero de columnas, las variables i y w son para los bucles
    int **m = NULL;                                              // Puntero a puntero de tipo entero inicializado a NULL
    printf("Elija el numero de filas que tiene su matriz: ");    // Pide el numero de filas de la matriz
    scanf("%d", &f);                                             // Guarda el numero de filas en la variable f
    printf("Elija el numero de columnas que tiene su matriz: "); // Pide el numero de columnas de la matriz
    scanf("%d", &c);                                             // Guarda el numero de columnas en la variable c
    // Se crea la matriz de forma dinamica
    m = (int **)malloc(sizeof(int *) * f); // Se reserva memoria para las filas de la matriz
    for (i = 0; i < f; i++)                // Se reserva memoria para las columnas de la matriz
    {
        m[i] = (int *)malloc(sizeof(int) * c); // Se reserva memoria para las columnas de la matriz
    }
    // Pide el valor de cada elemento de la matriz
    printf("Se completa la matriz con elementos RANDOM"); // cartel que informa que se completa la matriz
    for (i = 0; i < f; i++)                               // Se recorre la matriz
    {
        for (w = 0; w < c; w++) // Se recorre la matriz
        {
            m[i][w] = 1 + rand() % 9; // Se le asigna un valor random a cada elemento de la matriz
        }
    }
    printf("\nLa matriz es:\n"); // cartel que informa que se muestra la matriz
    for (i = 0; i < f; i++)      // Se recorre la matriz
    {
        for (w = 0; w < c; w++) // Se recorre la matriz
        {
            printf("%d\t", m[i][w]); // Se muestra el valor de cada elemento de la matriz
        }
        printf("\n"); // Se hace un salto de linea para que no se vea una sola linea la matriz
    }
    // Libero la memoria utilizada por la matriz
    for (i = 0; i < f; i++) // Se recorre la matriz
    {
        free(m[i]); // Se libera la memoria de cada columna de la matriz
    }
    free(m); // Se libera la memoria de cada fila de la matriz
    return 0;
}