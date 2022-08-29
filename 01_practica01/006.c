/*
    Practica 01
    Ejercicio 06 escriba un programa que defina las siguientes variables
*/

#include <stdio.h>

int main()
{
    int i = 5, j[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, k;
    char x = 'a', pal[] = "texto en c";
    int *pi;
    char *pc;

    // respuesta 1
    printf("1.\n");
    printf("La direccion de i es %p y su valor es: %d\n", &i, i);

    // respuesta 2
    pi = &i;
    printf("\n2.\n");
    printf("La direccion de i es %p y su valor es: %d\n", pi, *pi);

    // respuesta 3
    printf("\n3.\n");
    for (k = 0; k < 10; k++)
    {
        printf("La direccion de j[%d] es %p y su valor es: %d\n", k, &j[k], j[k]);
    }

    // respuesta 4
    printf("\n4.\n");
    k = 0;
    pi = j;
    do
    {
        printf("La direccion de j[%d] es %p y su valor es: %d\n", k, pi, *pi);
        pi++;
        k++;
    } while (k < 10);

    // respuesta 5
    printf("\n5.\n");
    printf("La direccion de x es %p y su valor es: %c\n\n", &x, x);

    pc = &x;
    printf("La direccion de x es %p y su valor es: %c\n\n", pc, *pc);

    k = 0;
    do
    {
        printf("La direccion de pal[%d] es %p y su valor es: %c\n", k, &pal[k], pal[k]);
        k++;
    } while (pal[k] != '\0');
    printf("\n");

    k = 0;
    pc = pal;
    do
    {
        printf("La direccion de pal[%d] es %p y su valor es: %c\n", k, pc, *pc);
        pc++;
        k++;
    } while (*pc != '\0');

    // respuesta 6
    printf("\n6.\n");
    printf("La direccion del puntero pi es: %p\n", &pi);
    printf("La direccion del puntero pc es: %p\n", &pc);

    return 0;
}
