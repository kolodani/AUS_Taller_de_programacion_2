/*
    Practica 01
    Ejercicio 03 suma de matrices
*/

#include <stdio.h>

int main()
{
    int n, i, j;
    printf("Bienvenido a la suma de matrices NxN\n");
    printf("primero ingrese el tamaño de la matriz:\n");
    printf("> ");
    scanf("%d", &n);
    
    int matrizA[n][n];
    int matrizB[n][n];
    
    printf("Ahora ingrese los valores de la matriz A:\n");
    for  (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("Ahora ingrese los valores de la matriz B:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("B[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matrizB[i][j]);
        }
    }

    printf("El contenido de las matrices es:\n");
    printf("La matriz A es:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("La matriz B es:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrizB[i][j]);
        }
        printf("\n");
    }

    printf("La suma de la matriz A y B es:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrizA[i][j] + matrizB[i][j]);
        }
        printf("\n");
    }
    return 0;
}
