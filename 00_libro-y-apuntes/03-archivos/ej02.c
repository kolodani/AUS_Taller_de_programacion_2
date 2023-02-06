// archivoAppend.c

/* El programa abrira al archivo NOMBRES.DAT  y agregara datos al final */

#include <stdio.h>

int main()
{
    FILE *pArchivo;

    pArchivo = fopen("NOMBRES.DAT", "a");

    if (pArchivo != NULL)
    {
        fputs("Juan Roman\n", pArchivo);
        fputs("Marta Rodriguez\n", pArchivo);
        fputs("Felipe Lopez\n", pArchivo);

            if (fclose(pArchivo))
        {
            printf("Error al cerra el archivo");
        }
    }
    else
    {
        printf("Error al abrir archivo\n");
    }
    return 0;
}
