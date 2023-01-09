/* factorial mejorado */

/* la funcion factorial ahora es recursiva y hace que sea mas intuitiva a la vista lo que realiza */

#include <stdio.h>

int factorial(int numero)
{
  if (numero == 1)
    return 1;
  else
    return (numero * factorial(numero -1));
}

int main()
{
  int a = 5;
  printf("El factorial de %d es igual a: %d", a, factorial(a));
  return 0;
}
