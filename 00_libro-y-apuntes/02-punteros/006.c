/* Estructura con memoria dinamica version 2 */

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
  direccion *pdir, *pdiri;

  pdir = pdiri = (direccion *)malloc(1000 * sizeof(direccion));
  strcpy(pdir->calle, "Avd. Alemania");
  pdir->numero = 2010;
  strcpy(pdir->nombre, "Fulano");

  printf("La direccion de %s es: %s %d\n", pdir->nombre, pdir->calle, pdir->numero);

  pdiri++; // pasa a la siguiente estructura

  strcpy(pdiri->calle, "Avd. Pelegrini");
  pdiri->numero = 250;
  strcpy(pdiri->nombre, "Ingenieria");

  printf("La direccion de %s es: %s %d\n", pdiri->nombre, pdiri->calle, pdiri->numero);
}