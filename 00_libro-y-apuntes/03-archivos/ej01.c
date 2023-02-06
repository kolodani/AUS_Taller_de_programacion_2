// archivo1.c

// el programa escribe los valores del 1 a 100 en un archivo en disco

#include <stdio.h>

int main()
{
    FILE *pArchivo;

    int contador;

    pArchivo = fopen("./NUMEROS.1", "wt");
    /* valida que el archivo este creado correctamente */
    if (pArchivo != NULL)
    {
        for (contador = 1; contador <= 100; contador++)
        {
            /* se escriben los numeros */
            fprintf(pArchivo, "%d ", contador);
        }
        /* se cierra el archivo */
        if (!fclose(pArchivo))
        {
            printf("El archivo ha sido cerrado.\n");
        }
        else
        {
            printf("Error al cerrar el archivo.\n");
        }
    }
    else
    {
        printf("Error al crear el archivo.\n");
    }
    return 0;
}
