#include <stdio.h>
#include <stdlib.h>

int main()
{
  int f, c, i, w; // f = numero de filas y c = numero de columnas

  int **m = NULL;

  printf("Elija el numero de filas que tiene su matriz: ");
  scanf("%d", &f);

  printf("Elija el numero de columnas que tiene su matriz: ");
  scanf("%d", &c);

  // Se crea la matriz de forma dinamica
  m = (int **)malloc(sizeof(int *) * f);

  for (i = 0; i < f; i++)
  {
    m[i] = (int *)malloc(sizeof(int) * c);
  }

  // Pide el valor de cada elemento de la matriz
  printf("Se completa la matriz con RANDOM");

  for (i = 0; i < f; i++)
  {
    for (w = 0; w < c; w++)
    {
      m[i][w] = 1 + rand() % 9;
    }
  }

  printf("\nLa matriz es:\n");

  for (i = 0; i < f; i++)
  {
    for (w = 0; w < c; w++)
    {
      printf("%d\t", m[i][w]);
    }
    printf("\n");
  }

  // Libero la memoria utilizada por la matriz

  for (i = 0; i < f; i++)
  {
    free(m[i]);
  }

  free(m);

  return 0;
}