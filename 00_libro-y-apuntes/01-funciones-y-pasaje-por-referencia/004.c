/* scope2.c */

/* aqui la variable es global por lo que cada cambio que se le haga a la misma, perdura */

#include "scope2.h" // incluyo el archivo de cabecera que contiene el prototipo de las funciones y la variable global

void unaFuncion()
{
    printf("En la funcion unaFuncion, variable es: %d\n", variable); // muestro el valor de la variable
}

void otraFuncion()
{
    variable++;                                                          // incremento el valor de la variable
    printf("EN la funcion otraFuncion, la variable es: %d\n", variable); // muestro el valor de la variable
}

int main()
{
    variable = 9;                                            // creo la variable y le asigno un valor
    printf("El valor de variable es: %d\n", variable);       // muestro el valor de la variable
    unaFuncion();                                            // llamo a la funcion unaFuncion
    otraFuncion();                                           // llamo a la funcion otraFuncion
    printf("Ahora el valor de variable es: %d\n", variable); // muestro el valor de la variable
    return 0;
}