#include <stdio.h>
#include <stdlib.h>

int leerCantidad()
{
  int cantidad;
  printf("Cuantos numeros va a ingresas?:");
  scanf("%d", &cantidad);
  return cantidad;
}

void leer(int cantidad, int *numeros)
{
  int i;
  for (i = 0; i < cantidad; i++)
  {
    printf("Ingrese el numero %d: ", i + 1);
    scanf("%d", numeros + i);
    printf("\n");
  }
}

void imprimir(int cantidad, int *numeros)
{
  int i;
  printf("Los numeros ingresados son:\n");

  for (i = 0; i < cantidad; i++)
  {
    printf("%d ", *(numeros + i));
  }
  printf("\n");
}

int main(void)
{
  int cantidad = leerCantidad();
  int *numeros = (int *)malloc(cantidad * sizeof(int));
  if (numeros == NULL)
  {
    return -1;
  }
  leer(cantidad, numeros);
  imprimir(cantidad, numeros);

  free(numeros);
  return 0;
}