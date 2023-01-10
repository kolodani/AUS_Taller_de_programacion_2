/* Enumeraciones */

#include <stdio.h>

typedef enum TiposFormas
{
  circulo,
  cuadrado,
  rectangulo
} TiposFormas;

int main()
{
  TiposFormas forma = rectangulo; // al cambiar el valor el switch mostrara los otros casos

  switch (forma)
  {
  case circulo:
    printf("Se eligio el circulo -> valor: %d\n", forma);
    break;
  case cuadrado:
    printf("Se eligio el cuadrado -> valor: %d\n", forma);
    break;
  case rectangulo:
    printf("Se eligio el rectangulo -> valor: %d\n", forma);
    break;
  default:
    break;
  }

  return 0;
}