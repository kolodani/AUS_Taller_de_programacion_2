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
    scanf("%d", &filas);
    printf("Ingresa ahora la cantidad de columnas:\n");
    printf("> ");
    scanf("%d", &columnas);
    
    int matriz[filas][columnas];
    
    printf("Ahora ingrese los valores de la matriz:\n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("La matriz A es:\n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("La matriz transpuesta es:\n");
    for (j = 0; j < columnas; j++)
    {
        for (i = 0; i < filas; i++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
