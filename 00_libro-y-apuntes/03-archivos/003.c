/*
    Ejercicio 3: Haga una copia exacta del archivo NOMBRES.DAT pero el nuevo que sea binario.
*/

#include <stdio.h>

int main()
{
    FILE *pArchivo, *pBinario;

    pArchivo = fopen("NOMBRES.DAT", "r");
    pBinario = fopen("NOMBRES.BIN", "wb");

    if (pArchivo != NULL || pBinario != NULL)
    {
        char c;
        while ((c = fgetc(pArchivo)) != EOF)
        {
            fputc(c, pBinario);
        }
        fclose(pArchivo);
        fclose(pBinario);
    }
    else
    {
        printf("Error al abrir el archivo");
    }
    return 0;
}
