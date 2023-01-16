/*
    Practica 01
    Ejercicio 04 matriz transpuesta
*/

#include <stdio.h>

int main()
{
    int filas, columnas, i, j;

    printf("Bienvenido a la matriz transpuesta\n");
    printf("primero ingrese el tamaño de la matriz:\n");
    printf("Ingresa primero la cantidad de filas:\n");
    printf("> ");
    scanf("%d", &filas); // ingreso el tamaño de la matriz
    printf("Ingresa ahora la cantidad de columnas:\n");
    printf("> ");
    scanf("%d", &columnas); // ingreso el tamaño de la matriz

    int matriz[filas][columnas]; // declaro las matrices

    printf("Ahora ingrese los valores de la matriz:\n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]); // ingreso los valores de la matriz
        }
    }

    printf("El tamaño de columna de la matriz es: %d\n", columnas); // imprimo el tamaño de las matrices
    printf("El tamaño de fila de la matriz es: %d\n", filas);       // imprimo el tamaño de las matrices

    printf("La matriz A es:\n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("%d ", matriz[i][j]); // imprimo la matriz
        }
        printf("\n");
    }

    printf("La matriz transpuesta es:\n");
    for (j = 0; j < columnas; j++)
    {
        for (i = 0; i < filas; i++)
        {
            printf("%d ", matriz[i][j]); // imprimo la matriz transpuesta (columnas por filas)
        }
        printf("\n");
    }
    return 0;
}
