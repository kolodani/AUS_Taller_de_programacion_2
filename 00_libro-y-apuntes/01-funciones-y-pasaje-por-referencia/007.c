/* referencia1.c */

/* a la funcion se envia una copia del valor de la variable y no la variable en si */

#include "referencia1.h"

void modificar(int variable) // la funcion recibe un parametro de tipo entero y no devuelve nada
{
    printf("\nvariable = %d dentro de modificar", variable); // imprime el valor de la variable
    variable = 9;                                            // modifica el valor de la variable
    printf("\nvariable = %d dentro de modificar", variable); // imprime el valor de la variable
}

int main()
{
    int i = 1;                                                      // variable local i inicializada en 1
    printf("\ni = %d antes de llamar a la funcion modificar", i);   // imprime el valor de i
    modificar(i);                                                   // llama a la funcion modificar y le pasa el valor de i
    printf("\ni = %d despues de llamar a la funcion modificar", i); // imprime el valor de i
    return 0;
}
