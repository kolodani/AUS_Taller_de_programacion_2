// archivo1.c

// el programa escribe los valores del 1 a 100 en un archivo en disco

#include <stdio.h>

int main()
{
    FILE *pArchivo;                        // puntero a archivo
    int contador;                          // contador
    pArchivo = fopen("./NUMEROS.1", "wt"); // se crea el archivo en modo escritura "w" (write) y texto "t" (text)
    if (pArchivo != NULL)                  // si el archivo se creo correctamente
    {
        for (contador = 1; contador <= 100; contador++) // bucle para escribir los numeros del 1 al 100
        {
            fprintf(pArchivo, "%d ", contador); // se escribe el numero en el archivo
        }
        if (!fclose(pArchivo)) // si el archivo se cerro correctamente
        {
            printf("El archivo ha sido cerrado.\n"); // se informa que el archivo se cerro correctamente
        }
        else
        {
            printf("Error al cerrar el archivo.\n"); // si el archivo no se cerro correctamente, se informa el error
        }
    }
    else
    {
        printf("Error al crear el archivo.\n"); // si el archivo no se creo correctamente, se informa el error
    }
    return 0;
}
