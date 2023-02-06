/*
    Ejercicio 1: Realizar un programa en C que realice la lectura del archivo del ejemplo
    utilizando la función getc().
*/

#include <stdio.h>

int main()
{
    FILE *pArchivo; // Puntero a archivo

    pArchivo = fopen("./NOMBRES.DAT", "r");

    if (pArchivo != NULL)
    {
        char c = getc(pArchivo);
        while (c != EOF)
        {
            printf("%c", c);
            c = getc(pArchivo);
        }
        if (fclose(pArchivo))
        {
            printf("Error al cerrar el archivo\n");
        }
    }
    else
    {
        printf("Error al abrir el archivo");
    }
    return 0;
}
