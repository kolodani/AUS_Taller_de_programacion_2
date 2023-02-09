// lecturaArchivo.c

/* Abre el archivo para leer el contenido */

#include <stdio.h>

int main()
{
    FILE *pArchivo;                          // puntero a archivo
    char nombre[25];                         // arreglo de caracteres
    char apellido[25];                       // arreglo de caracteres
    pArchivo = fopen("./NOMBRES.DAT", "rt"); // abre el archivo para lectura en modo texto "rt" (read text)
    if (pArchivo != NULL)                    // si el archivo se abrio correctamente
    {
        fscanf(pArchivo, "%s %s", nombre, apellido); // lee el archivo usando fscanf
        while (!feof(pArchivo))                      // mientras no se llegue al final del archivo (feof = end of file)
        {
            printf("Nombre leido: %s \tApellido leido: %s \n", nombre, apellido); // imprime los datos leidos
            fscanf(pArchivo, "%s %s", nombre, apellido);                        // lee el archivo usando fscanf
        }
        if (fclose(pArchivo)) // si el archivo se cerro correctamente
        {
            printf("Error al cerra el archivo\n"); // si el archivo no se cerro correctamente, informo el error
        }
    }
    else
    {
        printf("Error al abrir el archivo\n"); // si el archivo no se abrio correctamente, informo el error
    }
    return 0;
}