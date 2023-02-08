/* Uniones */

#include <stdio.h>
#include <string.h>

union Data // defino la union
{
  int i;        // variable entera
  float f;      // variable flotante
  char str[20]; // arreglo de caracteres
};

int main()
{
  union Data data;                                            // declaro una variable de tipo union
  printf("Memory size occupied by data: %d\n", sizeof(data)); // muestro el tamaño de la union
  return 0;
}