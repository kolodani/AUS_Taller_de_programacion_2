/* kruskal.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int tipo_nombre;
typedef int tipo_elemento;
typedef int vertice;

#define VERTICES 5

typedef struct _ARISTA{
    vertice u;
    vertice v;
    int costo;
}arista;

typedef struct _RAMA{
    struct _ARISTA a;
    struct _RAMA *sig;
}rama;

typedef struct _ENCABEZADO {
    int cuenta;
    int primer_elemento;
}encabezado;

typedef struct _NOMBRE{
    tipo_nombre nombre_conjunto;
    int siguiente_elemento;
}nombre;

typedef struct _CONJUNTO_CE{
    nombre nombres[VERTICES];
    encabezado encabezamientos_conjunto[VERTICES];
}conjunto_ce;

void inicial(tipo_nombre, tipo_elemento, conjunto_ce *);
void combina(tipo_nombre, tipo_nombre, conjunto_ce *);
tipo_nombre encuentra(int , conjunto_ce *);
void kruskal(rama*);

void inserta(int, int, int, rama **);
arista* sacar_min(rama **);
void lista(rama *);