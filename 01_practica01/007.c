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
    scanf("%d", &n);

    int arreglo[n];
    int *pa = arreglo;
    do
    {
        printf("Introduce el numero de la posicion %d:\n", i + 1);
        printf("> ");
        scanf("%d", pa);
        pa++;
        i++;
    } while (i < n);

    printf("El array invertido es:\n");
    i = 0;
    do
    {
        printf("%d\n", *(pa - 1));
        pa--;
        i++;
    } while (i < n);

    return 0;
}
