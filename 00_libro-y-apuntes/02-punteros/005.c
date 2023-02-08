/* Estructura con memoria dinamica */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct // defino la estructura
{
    char calle[25];  // arreglo de caracteres
    int numero;      // variable de tipo entero
    char nombre[30]; // arreglo de caracteres
} direccion;         // nombre de la estructura

void main()
{
    direccion *pdir;                                                                   // puntero a la estructura creada
    pdir = (direccion *)malloc(sizeof(direccion));                                     // reservo memoria para la estructura
    strcpy(pdir->calle, "Avd. Argentina");                                             // la funcion strcpy copia el contenido de la cadena de caracteres
    pdir->numero = 2022;                                                               // asigno el valor 2010 a la variable numero
    strcpy(pdir->nombre, "Fulano");                                                    // copio el contenido de la cadena de caracteres a la variable nombre
    printf("La direccion de %s es: %s %d\n", pdir->nombre, pdir->calle, pdir->numero); // imprimo los datos
}