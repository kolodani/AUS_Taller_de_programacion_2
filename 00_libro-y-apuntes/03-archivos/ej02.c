// archivoAppend.c

/* El programa abrira al archivo NOMBRES.DAT  y agregara datos al final */

#include <stdio.h>

int main()
{
    FILE *pArchivo; // Puntero a archivo
    pArchivo = fopen("NOMBRES.DAT", "a"); // Abrir archivo en modo escritura "a" (append)
    if (pArchivo != NULL) // Si el archivo se abrio correctamente
    {
        fputs("Juan Roman\n", pArchivo); // Escribir datos en el archivo usando fputs
        fputs("Marta Rodriguez\n", pArchivo);
        fputs("Felipe Lopez\n", pArchivo);
        if (fclose(pArchivo)) // Si el archivo se cerro correctamente
        {
            printf("Error al cerra el archivo"); // Si el archivo no se cerro correctamente, informo el error
        }
        else
        {
            printf("El archivo ha sido cerrado\n"); // Se informa que el archivo se cerro correctamente
        }
    }
    else
    {
        printf("Error al abrir archivo\n"); // Si el archivo no se abrio correctamente, informo el error
    }
    return 0;
}
