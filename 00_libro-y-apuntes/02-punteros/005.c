/* Estructura con memoria dinamica */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  char calle[25];
  int numero;
  char nombre[30];
} direccion;

void main()
{
  direccion *pdir;

  pdir = (direccion *)malloc(sizeof(direccion));
  strcpy(pdir->calle, "Avd. Alemania");
  pdir->numero = 2010;
  strcpy(pdir->nombre, "Fulano");

  printf("La direccion de %s es: %s %d\n", pdir->nombre, pdir->calle, pdir->numero);
}