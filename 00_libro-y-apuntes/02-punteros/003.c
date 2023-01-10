#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ingreso()
{
  char frase[256]; // creo un arreglo grande para poder guardar la frase
  printf("Ingrese una frase: ");

  scanf("%[^,`\n`]", frase); // leo la frase ingresada por teclado, lee todo hasta ingresar la tecla ENTER

  char *frase1 = (char *)malloc(strlen(frase)); // creo un puntero y le asigno el tamaño escrito del arreglo antes creado

  strcpy(frase1, frase); // copio el contenido de la frase

  return frase1;
}

int main()
{
  char *frase = ingreso(); // asigno a mi puntero el resultado de la funcion

  printf("Frase Ingresada: %s\n", frase);

  printf("Frase modificada: %s  - largo  %d\n", frase, (int)strlen(frase)); // muestro la frase guardada en un arreglo del tamaño justo

  free(frase);

  return 0;
}
