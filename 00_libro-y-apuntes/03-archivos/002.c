/*
    Ejercicio 2: Realice un programa en C que leyendo el archivo NOMBRES.DAT cree uno
    nuevo llamado APELLIDOS.DAT y se escriba apellido y nombre en vez de
    nombre y apellido como estaba en el original.
*/

#include <stdio.h>

int main()
{
    FILE *pArchivo, *pArchivoApellidos;

    pArchivo = fopen("./NOMBRES.DAT", "r");
    pArchivoApellidos = fopen("./APELLIDOS.DAT", "w");

    if (pArchivo != NULL)
    {
        char c = getc(pArchivo); // Leo el primer caracter
        while (c != EOF)         // Mientras no sea el final del archivo
        {
            char nombre[20];   // Guardo el nombre
            char apellido[20]; // Guardo el apellido
            int i = 0;         // Contador
            while (c != ' ')
            {
                nombre[i] = c;      // Guardo el caracter en el nombre
                c = getc(pArchivo); // Leo el siguiente caracter
                i++;
            }
            nombre[i] = '\0';   // Agrego el caracter de fin de cadena
            c = getc(pArchivo); // Leo el siguiente caracter
            i = 0;              // Reinicio el contador
            while (c != '\n')
            {
                apellido[i] = c;    // Guardo el caracter en el apellido
                c = getc(pArchivo); // Leo el siguiente caracter
                i++;
            }
            apellido[i] = '\0';                                      // Agrego el caracter de fin de cadena
            c = getc(pArchivo);                                      // Leo el siguiente caracter
            fprintf(pArchivoApellidos, "%s %s\n", apellido, nombre); // Escribo en el archivo de apellidos
        }
    }
    else
    {
        printf("Error al abrir el archivo");
    }
    return 0;
}
