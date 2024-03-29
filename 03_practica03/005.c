/*
    Practica 03
    Ejercicio 05
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// estructura de la matriz
typedef struct
{
    int filas;
    int columnas;
    int **matriz;
} matrix;

// prototipos de las funciones
void inicializarMatriz(matrix *m, int filas, int columnas);
void rellenarMatriz(matrix *m);
void mostrarMatriz(matrix *m);
void liberarMatriz(matrix *m);
matrix *sumaMatrices(matrix *m1, matrix *m2);

// funcion principal
int main()
{
    // declaracion de variables
    matrix m1, m2;
    matrix *pm3;
    matrix *pm1 = &m1;
    matrix *pm2 = &m2;
    int filas, columnas;

    // entrada de datos
    printf("Introduzca el numero de filas: ");
    scanf("%d", &filas);
    printf("Introduzca el numero de columnas: ");
    scanf("%d", &columnas);

    // inicializacion de las matrices
    inicializarMatriz(pm1, filas, columnas);
    inicializarMatriz(pm2, filas, columnas);
    // rellenar las matrices

    rellenarMatriz(pm1);
    rellenarMatriz(pm2);

    // mostrar las matrices
    printf("Matriz 1:\n");
    mostrarMatriz(pm1);
    printf("Matriz 2:\n");
    mostrarMatriz(pm2);

    // sumar las matrices
    pm3 = sumaMatrices(pm1, pm2);

    // mostrar la matriz resultante
    printf("Matriz 3:\n");
    mostrarMatriz(pm3);

    // liberar la memoria
    liberarMatriz(pm1);
    liberarMatriz(pm2);
    liberarMatriz(pm3);

    return 0;
}

void inicializarMatriz(matrix *m, int filas, int columnas)
{
    int i;
    m->filas = filas;
    m->columnas = columnas;
    m->matriz = (int **)malloc(filas * sizeof(int *));
    for (i = 0; i < filas; i++)
    {
        m->matriz[i] = (int *)malloc(columnas * sizeof(int));
    }
}

void rellenarMatriz(matrix *m)
{
    srand(time(NULL));
    int i, j;
    for (i = 0; i < m->filas; i++)
    {
        for (j = 0; j < m->columnas; j++)
        {
            m->matriz[i][j] = rand() % 10;
        }
    }
}

void mostrarMatriz(matrix *m)
{
    int i, j;
    for (i = 0; i < m->filas; i++)
    {
        for (j = 0; j < m->columnas; j++)
        {
            printf("%d ", m->matriz[i][j]);
        }
        printf("\n");
    }
}

void liberarMatriz(matrix *m)
{
    int i;
    for (i = 0; i < m->filas; i++)
    {
        free(m->matriz[i]);
    }
    free(m->matriz);
}

matrix *sumaMatrices(matrix *m1, matrix *m2)
{
    matrix *m3;
    int i, j;
    m3 = (matrix *)malloc(sizeof(matrix));
    inicializarMatriz(m3, m1->filas, m1->columnas);
    for (i = 0; i < m1->filas; i++)
    {
        for (j = 0; j < m1->columnas; j++)
        {
            m3->matriz[i][j] = m1->matriz[i][j] + m2->matriz[i][j];
        }
    }
    return m3;
}
