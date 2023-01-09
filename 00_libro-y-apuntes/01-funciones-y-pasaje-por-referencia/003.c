/* scope1.c */

/* en este caso hay dos variables distintas con el mismo nombre que se utilizan y manipulan de formas diferentes*/

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
