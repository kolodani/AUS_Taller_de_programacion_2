/*
    Practica 01
    Ejercicio 06 escriba un programa que defina las siguientes variables
*/

#include <stdio.h>

int main()
{
    // variables
    int i = 5, j[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, k;
    char x = 'a', pal[] = "texto en c";
    int *pi;
    char *pc;

    // respuesta 1
    printf("1.\n");
    printf("La direccion de i es %p y su valor es: %d\n", &i, i); // &i es la direccion de i

    // respuesta 2
    pi = &i; // pi es un puntero a i
    printf("\n2.\n");
    printf("La direccion de i es %p y su valor es: %d\n", pi, *pi); // *pi es el valor de i

    // respuesta 3
    printf("\n3.\n");
    for (k = 0; k < 10; k++)
    {
        printf("La direccion de j[%d] es %p y su valor es: %d\n", k, &j[k], j[k]); // &j[k] es la direccion de j[k]
    }

    // respuesta 4
    printf("\n4.\n");
    k = 0;
    pi = j;
    do
    {
        printf("La direccion de j[%d] es %p y su valor es: %d\n", k, pi, *pi); // *pi es el valor de j[k]
        pi++;
        k++;
    } while (k < 10);

    // respuesta 5
    printf("\n5.\n");
    printf("La direccion de x es %p y su valor es: %c\n\n", &x, x); // &x es la direccion de x

    pc = &x;
    printf("La direccion de x es %p y su valor es: %c\n\n", pc, *pc); // *pc es el valor de x

    k = 0;
    do
    {
        printf("La direccion de pal[%d] es %p y su valor es: %c\n", k, &pal[k], pal[k]); // &pal[k] es la direccion de pal[k]
        k++;
    } while (pal[k] != '\0');
    printf("\n");

    k = 0;
    pc = pal;
    do
    {
        printf("La direccion de pal[%d] es %p y su valor es: %c\n", k, pc, *pc); // *pc es el valor de pal[k]
        pc++;
        k++;
    } while (*pc != '\0');

    // respuesta 6
    printf("\n6.\n");
    printf("La direccion del puntero pi es: %p\n", &pi); // &pi es la direccion de pi
    printf("La direccion del puntero pc es: %p\n", &pc); // &pc es la direccion de pc

    return 0;
}
