/* Estructura con memoria dinamica version 2 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct // defino la estructura
{
    char calle[25];  // arreglo de caracteres
    int numero;      // variable entera
    char nombre[30]; // arreglo de caracteres
} direccion;         // nombre de la estructura

void main()
{
    direccion *pdir, *pdiri;                                                              // declaro dos punteros a estructura
    pdir = pdiri = (direccion *)malloc(1000 * sizeof(direccion));                         // asigno memoria para 1000 estructuras
    strcpy(pdir->calle, "Avd. Alemania");                                                 // copio la cadena a la estructura
    pdir->numero = 2010;                                                                  // guardo el numero en la estructura
    strcpy(pdir->nombre, "Fulano");                                                       // copio la cadena a la estructura
    printf("La direccion de %s es: %s %d\n", pdir->nombre, pdir->calle, pdir->numero);    // muestro la direccion
    pdiri++;                                                                              // pasa a la siguiente estructura
    strcpy(pdiri->calle, "Avd. Pelegrini");                                               // copio la cadena a la estructura
    pdiri->numero = 250;                                                                  // guardo el numero en la estructura
    strcpy(pdiri->nombre, "Ingenieria");                                                  // copio la cadena a la estructura
    printf("La direccion de %s es: %s %d\n", pdiri->nombre, pdiri->calle, pdiri->numero); // muestro la direccion
}