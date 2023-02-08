/* scope1.c */

/* en este caso hay dos variables distintas con el mismo nombre que se utilizan y manipulan de formas diferentes*/

#include "scope1.h"

void imprimeValor()
{
    int contador;                                       // variable local no es la misma que la del main mas alla de llamarse igual
    contador = 5;                                       // inicializo la variable en 5
    printf("El valor del contador es: %d\n", contador); // muestro el valor de la variable local
}

int main()
{
    int contador;                                            // variable local
    contador = 0;                                            // inicializo la variable
    contador++;                                              // incremento el valor de la variable en 1
    printf("El valor del contador es: %d\n", contador);      // muestro el valor de la variable
    imprimeValor();                                          // llamo a la funcion imprimeValor
    printf("Ahora el valor de contador es: %d\n", contador); // muestro el valor de la variable local del main
    return 0;
}
