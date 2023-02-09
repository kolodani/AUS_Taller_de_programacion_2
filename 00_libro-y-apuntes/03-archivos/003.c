/*
    Ejercicio 3: Haga una copia exacta del archivo NOMBRES.DAT pero el nuevo que sea binario.
*/

#include <stdio.h>

int main()
{
    FILE *pArchivo, *pBinario;                // Punteros a archivos
    pArchivo = fopen("NOMBRES.DAT", "r");     // Abrir archivo en modo lectura "r" (read)
    pBinario = fopen("NOMBRES.BIN", "wb");    // Abrir archivo en modo escritura "w" (write) y binario "b" (binary)
    if (pArchivo != NULL || pBinario != NULL) // Si los archivos se abrieron correctamente
    {
        char c;                              // Variable para guardar el caracter leido
        while ((c = fgetc(pArchivo)) != EOF) // Mientras no sea el final del archivo (EOF = End Of File) usando fgetc para leer caracter por caracter
        {
            fputc(c, pBinario); // Escribir caracter en el archivo binario usando fputc
        }
        fclose(pArchivo); // Cerrar los archivos
        fclose(pBinario);
    }
    else
    {
        printf("Error al abrir el archivo"); // Si el archivo no se abrió correctamente, informo el error
    }
    return 0;
}
