/*
   letras.c
   Esribe el abecedario y lee dos letras la I y la R
*/

#include <stdio.h>

int main()
{
   FILE *pArchivo;
   int letra; // almacena las letras

   if ((pArchivo = fopen("letras.txt", "w+")) == NULL)
   {
      printf("Error al abrir el archivo\n");
      return 0;
   }

   /* Escribir las letras usando los ASCCI */
   for (letra = 65; letra <= 90; letra++)
   {
      fputc(letra, pArchivo);
   }

   /* Posiciona al puntero en el 8vo bytes */
   fseek(pArchivo, 8L, SEEK_SET);
   letra = getc(pArchivo);

   printf("Primera letra leida %c\n", letra);
   /* Posiciona al puntero en el bytes 17 */
   fseek(pArchivo, 17L, SEEK_SET);
   letra = getc(pArchivo);

   printf("Segunda letra leida %c\n", letra);

   fclose(pArchivo);

   return 0;
}