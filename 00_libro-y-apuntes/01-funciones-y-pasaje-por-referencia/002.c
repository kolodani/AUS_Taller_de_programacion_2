#include "funciones2.h"

int segunda (int x, int j)
{
  int b;
  b = x +j;
  printf("se inicia la segunda funcion - retorno %d y finalizado\n", b);
  return b;
}

void primera ()
{
  printf("Esta es la primera funcion\n");

  printf("Muestro el resulrado de la segunda funcion: %d\n", segunda(3, 4));

  printf("Fin de la primera funcion\n");
}

int main ()
{
  printf("inicia el main\n");
  int a;
  primera();

  a = segunda(5 , 8);

  printf("El valor de a es %d\n", a);

  printf("Fin del main\n");

  return 0;
}