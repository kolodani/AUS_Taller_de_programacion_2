/*
    Practica 01
    Ejercicio 01 Matriz identidad
*/

#include <stdio.h>

int main()
{
    int tamano, i, j; // creo las variables necesarias para el programa

    printf("Bienvenido a la matriz identidad\n");
    printf("Elija el tamaño de la matriz:\n");
    printf("> ");
    scanf("%d", &tamano); // guardo la variable ingresada y la guardo, si no es un numero, se genera un error
    printf("La matriz identidad de %dX%d es:\n", tamano, tamano);

    for (i = 0; i < tamano; i++)
    {
        for (j = 0; j < tamano; j++)
        {
            if (i == j)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    // solo imprimo la matriz, en ningun momento la guardo a la misma
    return 0;
}
