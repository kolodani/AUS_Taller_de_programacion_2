/*
   lectura.c
   Lee el archivo letras.txt de atras hacia adelante
*/

#include <stdio.h>

int main()
{
   int contador; /* recorrera en sentido inverso */
   int letra;
   FILE *pArchivo;

   if ((pArchivo = fopen("letras.txt", "r")) == NULL)
   {
      printf("Error al abrir el archivo\n");
      return 0;
   }

   fseek(pArchivo, 1L, SEEK_END);

   for (contador = 0; contador <= 25; contador++)
   {
      fseek(pArchivo, -2L, SEEK_CUR);
      letra = getc(pArchivo);
      printf("Letra leida: %c\n", letra);
   }

   fclose(pArchivo);

   return 0;
}