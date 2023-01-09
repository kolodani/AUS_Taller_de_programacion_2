/* scope4.c */

/* al ser una variable estatica la misma incrementa su valor y no vuelve a ser redeclarada */

#include <stdio.h>

void sumador();

void sumador()
{
  static int contador = 0;
  printf("El valor de contador es: %d\n", contador);
  contador++;
}

int main()
{
  sumador();
  sumador();
  sumador();
  sumador();
  return 0;
}