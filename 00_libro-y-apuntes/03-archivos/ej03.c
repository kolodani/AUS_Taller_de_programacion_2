// lecturaArchivo.c

/* Abre el archivo para leer el contenido */

#include <stdio.h>

int main()
{

    FILE *pArchivo;

    char nombre[25];
    char apellido[25];

    pArchivo = fopen("./NOMBRES.DAT", "rt");

    if (pArchivo != NULL)
    {
        fscanf(pArchivo, "%s %s", nombre, apellido);
        while (!feof(pArchivo))
        {
            printf("Nombre leido: %s Apellido leido: %s \n", nombre, apellido);
            fscanf(pArchivo, "%s %s", nombre, apellido);
        }
        if (fclose(pArchivo))
        {
            printf("Eroor al cerra el archivo\n");
        }
        else
        {
            printf("Error al abrir archivo\n");
        }
    }
    return 0;
}