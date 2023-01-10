/* bidimensional.c */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int matriz[10][10], x, y; // la variable en este caso es un puntero al primer elemento, en este caso de la matriz

  for (x = 0; x < 10; x++)
  {
    for (y = 0; y < 10; y++)
    {
      matriz[x][y] = 1 + rand() % 9;
      printf("%d ", matriz[x][y]);
    }
    printf("\n");
  }
  return 0;
}