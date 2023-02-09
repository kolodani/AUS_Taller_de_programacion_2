#include <stdio.h>

int main()
{
    FILE *fp; // Puntero a archivo
    char cadena[] = "Hola mundo!\n"; // arreglo de caracteres (string), inicializado con un string
    fp = fopen("./HM.txt", "w+"); // Abrir archivo en modo escritura y lectura "w+" (si no existe, lo crea)
    if (fp == NULL) // Si no se pudo abrir el archivo
    {
        printf("Error!\n"); // Imprimir mensaje de error
    }
    else
    {
        fwrite(cadena, sizeof(char), sizeof(cadena), fp); // Escribir en el archivo
    }
    fclose(fp); // Cerrar archivo
    return 0;
}
