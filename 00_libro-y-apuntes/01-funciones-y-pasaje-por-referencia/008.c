/* referencia2.c */

/* al enviar la direccion de memoria de la variable, hacemos que la misma cambie */

#include "referencia2.h"

void modificar(int *variable) // la funcion recibe un parametro de tipo puntero a entero y no devuelve nada
{
    printf("\nvariable = %d dentro de modificar", *variable); // imprime el valor de la variable
    *variable = 9;                                            // modifica el valor de la variable
    printf("\nvariable = %d dentro de modificar", *variable); // imprime el valor de la variable
}

int main()
{
    int i = 1;                                                      // variable local i inicializada en 1
    printf("\ni = %d antes de llamar a la funcion modificar", i);   // imprime el valor de i
    modificar(&i);                                                  // llama a la funcion modificar y le pasa la direccion de memoria de i
    printf("\ni = %d despues de llamar a la funcion modificar", i); // imprime el valor de i
}