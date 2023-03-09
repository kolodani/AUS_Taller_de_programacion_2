/* tda.c */

#define LONG_MAX_NOMBRE 10

typedef struct nodo {
    char nombre[LONG_MAX_NOMBRE];
    char voto;
    *nodo siguiente;
}chicos_buenos, chicos_malos;

void inserta (char [], nodo);

void suprimir (char [], nodo);

bool miembro (char [], nodo);

void mostrar (nodo);