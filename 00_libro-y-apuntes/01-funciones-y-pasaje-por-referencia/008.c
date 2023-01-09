/* referencia2.c */

/* al enviar la direccion de memoria de la variable, hacemos que la misma cambie */

#include "referencia2.h"

void modificar (int * variable)
{
  printf("\nvariable = %d dentro de modificar", *variable);
  *variable = 9;
  printf("\nvariable = %d dentro de modificar", *variable);
}

int main()
{
  int i = 1;
  printf("\ni = %d antes de llamar a la funcion modificar", i);
  modificar(&i);
  printf("\ni = %d despues de llamar a la funcion modificar", i);
}