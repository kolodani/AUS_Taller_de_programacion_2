/* scope4.c */

/* al ser una variable estatica la misma incrementa su valor y no vuelve a ser redeclarada */

#include <stdio.h>

void sumador(); // prototipo de la funcion

void sumador()
{
    static int contador = 0;                           // variable estatica lo que hace que su valor no se pierda
    printf("El valor de contador es: %d\n", contador); // imprime el valor de la variable
    contador++;                                        // incrementa el valor de la variable en 1
}

int main()
{
    sumador(); // llama a la funcion sumador 4 veces
    sumador();
    sumador();
    sumador();
    return 0;
}