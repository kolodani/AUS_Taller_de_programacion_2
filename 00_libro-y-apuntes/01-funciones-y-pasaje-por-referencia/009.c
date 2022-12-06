/* factorial1.c */

#include "factorial1.h"

int factorial (int numero)
{
  int i;
  int devuelve = 1;
  for (i = 1; i <= numero; i++)
  {
    devuelve = devuelve * i;
  }
  return devuelve;
}

int main()
{
  int valor = 4;
  int resultado;
  resultado = factorial(valor);
  printf("El factorial de %d es %d \n", valor, resultado);
  return 0;
}