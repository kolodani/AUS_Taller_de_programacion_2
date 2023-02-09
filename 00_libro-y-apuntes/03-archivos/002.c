/*
    Ejercicio 2: Realice un programa en C que leyendo el archivo NOMBRES.DAT cree uno
    nuevo llamado APELLIDOS.DAT y se escriba apellido y nombre en vez de
    nombre y apellido como estaba en el original.
*/

#include <stdio.h>

int main()
{
    FILE *pArchivo, *pArchivoApellidos;                // Punteros a archivos
    pArchivo = fopen("./NOMBRES.DAT", "r");            // Abro el archivo en modo lectura "r" (read)
    pArchivoApellidos = fopen("./APELLIDOS.DAT", "w"); // Abro el archivo en modo escritura "w" (write)
    if (pArchivo != NULL)                              // Si el archivo se abrio correctamente
    {
        char c = getc(pArchivo); // Leo el primer caracter
        while (c != EOF)         // Mientras no sea el final del archivo (EOF = End Of File)
        {
            char nombre[20];   // arreglo para guardar el nombre
            char apellido[20]; // arreglo para guardar el apellido
            int i = 0;         // Contador
            while (c != ' ')   // Mientras no sea un espacio
            {
                nombre[i] = c;      // Guardo el caracter en el nombre
                c = getc(pArchivo); // Leo el siguiente caracter
                i++;                // Incremento el contador
            }
            nombre[i] = '\0';   // Agrego el caracter de fin de cadena
            c = getc(pArchivo); // Leo el siguiente caracter
            i = 0;              // Reinicio el contador
            while (c != '\n')   // Mientras no sea un salto de linea
            {
                apellido[i] = c;    // Guardo el caracter en el apellido
                c = getc(pArchivo); // Leo el siguiente caracter
                i++;                // Incremento el contador
            }
            apellido[i] = '\0';                                      // Agrego el caracter de fin de cadena
            c = getc(pArchivo);                                      // Leo el siguiente caracter
            fprintf(pArchivoApellidos, "%s %s\n", apellido, nombre); // Escribo en el archivo de apellidos
        }
    }
    else
    {
        printf("Error al abrir el archivo"); // Si el archivo no se abrió correctamente, informo el error
    }
    return 0;
}
