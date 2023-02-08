/* puedo llamar una funcion dentro de otra funcion, lo que es muy conveniente poder encadenar funciones*/

#include "funciones2.h"

int segunda(int x, int j)
{
    int b;                                                                 // variable local
    b = x + j;                                                             // alamaceno el resultado de la suma de los dos numeros que recibo
    printf("se inicia la segunda funcion - retorno %d y finalizado\n", b); // muestro el resultado de la suma
    return b;                                                              // retorno el resultado de la suma
}

void primera()
{
    printf("Esta es la primera funcion\n"); // muestro un mensaje

    printf("Muestro el resulrado de la segunda funcion: %d\n", segunda(3, 4)); // llamo a la segunda funcion y muestro el resultado

    printf("Fin de la primera funcion\n"); // muestro un mensaje
}

int main()
{
    printf("inicia el main\n"); // muestro un mensaje de inicio del programa
    int a;                      // variable local donde voy a guardar el resultado de la segunda funcion
    primera();                  // llamo a la primera funcion

    a = segunda(5, 8); // llamo a la segunda funcion y guardo el resultado en la variable a

    printf("El valor de a es %d\n", a); // muestro el valor de la variable a

    printf("Fin del main\n"); // finalizo el programa

    return 0;
}