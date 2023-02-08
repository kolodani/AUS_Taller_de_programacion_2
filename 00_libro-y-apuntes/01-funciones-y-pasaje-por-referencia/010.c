/* factorial mejorado */

/* la funcion factorial ahora es recursiva y hace que sea mas intuitiva a la vista lo que realiza */

#include <stdio.h>

int factorial(int numero) // la funcion recibe un parametro de tipo entero y devuelve un entero
{
    if (numero == 1)                             // si el valor de la variable numero es igual a 1
        return 1;                                // devuelve 1
    else                                         // si no
        return (numero * factorial(numero - 1)); // devuelve el valor de la variable numero multiplicado por el valor de la funcion factorial con el valor de la variable numero decrementado en 1
}

int main()
{
    int a = 5;                                                    // variable local a inicializada en 5
    printf("El factorial de %d es igual a: %d", a, factorial(a)); // imprime el valor de a y el valor de factorial(a)
    return 0;
}
