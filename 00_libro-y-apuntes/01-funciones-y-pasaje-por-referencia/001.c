/* funciones1.c */

#include "funciones1.h" // incluyo aqui al prototipo de la funcion cubo

int cubo(int base)
{
    int potencia;                  // variable donde se almacena el resultado
    potencia = base * base * base; // calculo del cubo
    return potencia;               // devuelvo el resultado
}

int main()
{
    int numero; // variable donde se almacena el numero a calcular su cubo

    for (numero = 1; numero <= 5; numero++) // bucle para calcular los cubos de los numeros del 1 al 5
    {
        printf("El cubo de %d es igual a %d\n", numero, cubo(numero)); // imprimo el resultado llamando a la funcion cubo
    }
    return 0;
}
