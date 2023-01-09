/* referencia1.c */

/* a la funcion se envia una copia del valor de la variable y no la variable en si */

#include "referencia1.h"

void modificar(int variable)
{
  printf("\nvariable = %d dentro de modificar", variable);
  variable = 9;
  printf ("\nvariable = %d dentro de modificar", variable);
}

int main()
{
  int i = 1;
  printf("\ni = %d antes de llamar a la funcion modificar", i);
  modificar(i);
  printf("\ni = %d despues de llamar a la funcion modificar", i);
  return 0;
}
