/* funciones1.c */

#include "funciones1.h"

int cubo(int base)
{
  int potencia;
  potencia = base * base * base;
  return potencia;
}

int main()
{
  int numero;

  for (numero = 1; numero <= 5; numero++)
  {
    printf("El cubo de %d es igual a %d\n", numero, cubo(numero));
  }
  return 0;
}
