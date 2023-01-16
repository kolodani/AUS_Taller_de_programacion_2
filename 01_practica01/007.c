/*
    Practica 01
    Ejercicio 07 recorriendo un array
*/

#include <stdio.h>

int main()
{
    int n, i = 0;
    printf("Introduce un numero, el mismo sera el tamaño del array:\n");
    printf("> ");
    scanf("%d", &n); // Se pide el tamaño del array

    int arreglo[n];    // Se crea el array
    int *pa = arreglo; // Se crea un puntero al array
    do
    {
        printf("Introduce el numero de la posicion %d:\n", i + 1);
        printf("> ");
        scanf("%d", pa); // Se pide el valor de la posicion i
        pa++;            // Se incrementa el puntero
        i++;             // Se incrementa el contador
    } while (i < n);

    printf("El array invertido es:\n");
    i = 0;
    do
    {
        printf("%d\n", *(pa - 1)); // Se imprime el valor de la posicion i
        pa--;                      // Se decrementa el puntero
        i++;                       // Se incrementa el contador
    } while (i < n);

    return 0;
}
