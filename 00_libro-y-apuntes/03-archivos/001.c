/*
    Ejercicio 1: Realizar un programa en C que realice la lectura del archivo del ejemplo
    utilizando la función getc().
*/

#include <stdio.h>

int main()
{
    FILE *pArchivo;                         // Puntero a archivo
    pArchivo = fopen("./NOMBRES.DAT", "r"); // Abrir archivo en modo lectura "r" (read)
    if (pArchivo != NULL)                   // Si el archivo se abrió correctamente
    {
        char c = getc(pArchivo); // funcion getc() para leer el archivo caracter por caracter y almacenarlo en la variable c
        while (c != EOF)         // Mientras no se llegue al final del archivo (EOF = End Of File)
        {
            printf("%c", c);    // Imprimir el caracter leído
            c = getc(pArchivo); // Leer el siguiente caracter y almacenarlo en la variable c
        }
        if (fclose(pArchivo)) // Cerrar el archivo
        {
            printf("Error al cerrar el archivo\n");
        }
    }
    else
    {
        printf("Error al abrir el archivo"); // Si el archivo no se abrió correctamente, informo el error
    }
    return 0;
}
