/*
    Practica 01
    Ejercicio 03 suma de matrices
*/

#include <stdio.h>

void cargarMatriz(int n, int matriz[n][n]);
void imprimirMatriz(int n, int matriz[n][n]);
void sumaMatrices(int n, int matrizA[n][n], int matrizB[n][n]);

int main()
{
    int n, i, j;
    printf("Bienvenido a la suma de matrices NxN\n");
    printf("primero ingrese el tamaño de la matriz:\n");
    printf("> ");
    scanf("%d", &n); // ingreso el tamaño de la matriz

    int matrizA[n][n]; // declaro las matrices
    int matrizB[n][n];

    printf("Ahora ingrese los valores de la matriz A:\n");
    cargarMatriz(n, matrizA); // cargo los valores de la matriz A

    printf("Ahora ingrese los valores de la matriz B:\n");
    cargarMatriz(n, matrizB); // cargo los valores de la matriz B

    printf("El tamaño de las matrices es: %d x %d\n", n, n); // imprimo el tamaño de las matrices
    printf("El contenido de las matrices es:\n");
    printf("La matriz A es:\n");
    imprimirMatriz(n, matrizA); // imprimo la matriz A

    printf("La matriz B es:\n");
    imprimirMatriz(n, matrizB); // imprimo la matriz B

    printf("La suma de la matriz A y B es:\n");
    sumaMatrices(n, matrizA, matrizB); // imprimo la suma de las matrices

    return 0;
}

void cargarMatriz(int n, int matriz[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Ingrese el valor de la posicion (%d, %d): ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int n, int matriz[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumaMatrices(int n, int matrizA[n][n], int matrizB[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrizA[i][j] + matrizB[i][j]);
        }
        printf("\n");
    }
}