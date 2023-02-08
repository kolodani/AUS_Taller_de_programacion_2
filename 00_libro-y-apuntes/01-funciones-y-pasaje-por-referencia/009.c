/* factorial1.c */

/* la funcion factorial funciona pero no se ve como la funcion matematica */

#include "factorial1.h" // incluye el archivo de cabecera que contiene el prototipo de la funcion factorial

int factorial(int numero) // la funcion recibe un parametro de tipo entero y devuelve un entero
{
    int i;                        // variable local i
    int devuelve = 1;             // variable local devuelve inicializada en 1
    for (i = 1; i <= numero; i++) // bucle for que se ejecuta desde 1 hasta el valor de la variable numero
    {
        devuelve = devuelve * i; // multiplica el valor de la variable devuelve por el valor de la variable i
    }
    return devuelve; // devuelve el valor de la variable devuelve
}

int main()
{
    int valor = 4;                                           // variable local valor inicializada en 4
    int resultado;                                           // variable local resultado
    resultado = factorial(valor);                            // llama a la funcion factorial y le pasa una copia del valor de la variable valor
    printf("El factorial de %d es %d \n", valor, resultado); // imprime el valor de valor y el valor de resultado
    return 0;
}