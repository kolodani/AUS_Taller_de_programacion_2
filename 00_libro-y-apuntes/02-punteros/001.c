/* bidimensional.c */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[10][10], x, y; // matriz bidimensional de 10x10 y variables locales x e y, matriz es un puntero a un puntero al primer elemento de la matriz

    for (x = 0; x < 10; x++) // bucle for que se ejecuta desde 0 hasta 9 (10 veces)
    {
        for (y = 0; y < 10; y++) // bucle for que se ejecuta desde 0 hasta 9 (10 veces) anidado dentro del bucle for anterior
        {
            matriz[x][y] = 1 + rand() % 9; // asigna un valor aleatorio entre 1 y 9 a la posicion [x][y] de la matriz
            printf("%d ", matriz[x][y]);   // imprime el valor de la posicion [x][y] de la matriz
        }
        printf("\n"); // imprime un salto de linea para que la matriz se vea en forma de tabla
    }
    return 0;
}