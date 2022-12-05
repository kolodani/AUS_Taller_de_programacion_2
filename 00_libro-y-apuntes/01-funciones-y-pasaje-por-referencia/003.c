/* scope1.c */

#include "scope1.h"

void imprimeValor()
{
  int contador;
  contador = 5;
  printf("El valor del contador es: %d\n", contador);
}

int main()
{
  int contador;
  contador = 0;
  contador++;
  printf("El valor del contador es: %d\n", contador);
  imprimeValor();
  printf("Ahora el valor de contador es: %d\n", contador);
  return 0;
}
