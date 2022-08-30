/*
    Practica 01
    Ejercicio 08 retornar un puntero
*/

#include <stdio.h>

char* semanal(int, char(*)[10]);

int main()
{
    char semana[7][10] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    int num, i;
    char *puntero;
    printf("Ingrese un numero del 1 al 7 y recibira un dia de la semana:\n");
    printf("> ");
    scanf("%d", &num);
    
    puntero = semanal(num, semana);
    printf("El dia de la semana es: %s", puntero);
    
    return 0;
}

char* semanal(int num, char(*semana)[10])
{
    char *psem;
    psem = semana[num - 1];
    return psem;
}
