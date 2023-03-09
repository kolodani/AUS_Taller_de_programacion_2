/* tda.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG_MAX_NOMBRE 10

typedef struct nodo {
    char nombre[LONG_MAX_NOMBRE];
    struct nodo *siguiente;
}legisladores;

void inserta (char [], legisladores**);

void suprimir (char [], legisladores**);

int miembro (char [], legisladores**);

void mostrar (legisladores**);

void votacion (legisladores**, legisladores**, char [], char);