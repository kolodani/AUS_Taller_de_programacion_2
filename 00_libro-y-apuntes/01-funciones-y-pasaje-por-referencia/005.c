/* scope3.c */

/* en este caso se hace externa a la variable para que su uso sea global en el programa */

#include <stdio.h>

void unaFuncion()
{
  extern int variable;
  printf("En la funcion unaFuncion, variable es: %d\n", variable);
}

void otraFuncion()
{
  extern int variable;
  variable++;
  printf("EN la funcion otraFuncion, la variable es: %d\n", variable);
}

int main()
{
  extern int variable;
  variable = 9;
  printf("El valor de la variable es: %d\n", variable);
  unaFuncion();
  otraFuncion();
  printf("Ahora el valor de variable es: %d\n", variable);
  return 0;
}

int variable;