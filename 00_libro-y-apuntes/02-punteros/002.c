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
    scanf("%d", numeros + i); // recorre el arreglo de numeros con aritmetica de punteros
    printf("\n");
  }
}

void imprimir(int cantidad, int *numeros)
{
  int i;
  printf("Los numeros ingresados son:\n");

  for (i = 0; i < cantidad; i++)
  {
    printf("%d ", *(numeros + i)); // recorre el arreglo de numeros con aritmetica de punteros
  }
  printf("\n");
}

int main(void)
{
  int cantidad = leerCantidad();
  int *numeros = (int *)malloc(cantidad * sizeof(int)); // asigna la memoria justa para los numeros que se van a ingresar
  if (numeros == NULL)
  {
    return -1; // si el puntero no apunta a nada devuelve -1 y finaliza el programa
  }
  leer(cantidad, numeros);
  imprimir(cantidad, numeros);

  free(numeros); // libera la memoria asignada
  return 0;
}