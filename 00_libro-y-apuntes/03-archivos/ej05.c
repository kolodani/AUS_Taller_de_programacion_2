/*
    letras.c
    Esribe el abecedario y lee dos letras la I y la R
*/

#include <stdio.h>

int main()
{
    FILE *pArchivo;                                     // puntero a archivo
    int letra;                                          // variable para almacenar el valor ASCII de la letra
    if ((pArchivo = fopen("letras.txt", "w+")) == NULL) // Abrir archivo en modo escritura y lectura "w+" (si no existe, lo crea)
    {
        printf("Error al abrir el archivo\n"); // Imprimir mensaje de error
        return 0;
    }
    /* Escribir las letras usando los ASCCI */
    for (letra = 65; letra <= 90; letra++)
    {
        fputc(letra, pArchivo); // Escribir en el archivo
    }
    /* Posiciona al puntero en el 8vo bytes */
    fseek(pArchivo, 8L, SEEK_SET);             // SEEK_SET: posiciona al puntero en el byte 8
    letra = getc(pArchivo);                    // Leer un caracter del archivo
    printf("Primera letra leida %c\n", letra); // Imprimir la letra
    /* Posiciona al puntero en el bytes 17 */
    fseek(pArchivo, 17L, SEEK_SET);            // SEEK_SET: posiciona al puntero en el byte 17
    letra = getc(pArchivo);                    // Leer un caracter del archivo
    printf("Segunda letra leida %c\n", letra); // Imprimir la letra
    fclose(pArchivo);                          // Cerrar archivo
    return 0;
}