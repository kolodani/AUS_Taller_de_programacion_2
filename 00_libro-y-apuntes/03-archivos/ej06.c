/*
    lectura.c
    Lee el archivo letras.txt de atras hacia adelante
*/

#include <stdio.h>

int main()
{
    int contador;                                      // variable de control
    int letra;                                         // variable para almacenar la letra leida
    FILE *pArchivo;                                    // puntero a archivo
    if ((pArchivo = fopen("letras.txt", "r")) == NULL) // abre el archivo en modo lectura y verifica que no haya error
    {
        printf("Error al abrir el archivo\n"); // si hay error, muestra un mensaje
        return 0;
    }
    fseek(pArchivo, 1L, SEEK_END);                 // posiciona el puntero al final del archivo
    for (contador = 0; contador <= 25; contador++) // lee las 26 letras del archivo
    {
        fseek(pArchivo, -2L, SEEK_CUR);     // retrocede el puntero 2 posiciones
        letra = getc(pArchivo);             // lee la letra
        printf("Letra leida: %c\n", letra); // muestra la letra leida
    }
    fclose(pArchivo); // cierra el archivo
    return 0;
}