/* scope2.c */

#include "scope2.h"

void unaFuncion()
{
  printf("En la funcion unaFuncion, variable es: %d\n", variable);
}

void otraFuncion()
{
  variable++;
  printf("EN la funcion otraFuncion, la variable es: %d\n", variable);
}

int main()
{
  variable = 9;
  printf("El valor de variable es: %d\n", variable);
  unaFuncion();
  otraFuncion();
  printf("Ahora el valor de variable es: %d\n", variable);
  return 0;
}