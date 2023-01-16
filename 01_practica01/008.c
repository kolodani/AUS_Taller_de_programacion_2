/*
    Practica 01
    Ejercicio 08 retornar un puntero
*/

#include <stdio.h>

char *semanal(int, char (*)[10]);

int main()
{
    char semana[7][10] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"}; // arreglo con los 7 dias de la semana
    int num, i;
    char *puntero;
    printf("Ingrese un numero del 1 al 7 y recibira un dia de la semana:\n");
    printf("> ");
    scanf("%d", &num); // Se pide el numero del dia de la semana

    puntero = semanal(num, semana);                // Se llama a la funcion semanal y se le pasa el numero del dia de la semana y el arreglo con los dias de la semana
    printf("El dia de la semana es: %s", puntero); // Se imprime el dia de la semana

    return 0;
}

char *semanal(int num, char (*semana)[10])
{
    char *psem;             // puntero al dia de la semana
    psem = semana[num - 1]; // se le asigna el dia de la semana
    return psem;            // se retorna el puntero al dia de la semana
}
