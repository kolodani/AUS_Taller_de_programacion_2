#include "kruskal.h"

tipo_nombre encuentra(int x, conjunto_ce *ce)
{
    tipo_nombre y = x;
    while (ce->nombres[y].nombre_conjunto != y)
    {
        y = ce->nombres[y].nombre_conjunto;
    }
    return y;
}

void lista(rama *arbol)
{
    if (!arbol)
    {
        printf("No hay aristas en el arbol");
    }
    else
    {
        while (arbol)
        {
            printf("Arista: %d - %d, Costo: %d", arbol->a.u, arbol->a.v, arbol->a.costo);
            arbol = arbol->sig;
        }
    }
}

void inicial(tipo_nombre x, tipo_elemento y, conjunto_ce *ce)
{
    ce->nombres[y].nombre_conjunto = x;
    ce->nombres[y].siguiente_elemento = -1;
    ce->encabezamientos_conjunto[x].cuenta = 1;
    ce->encabezamientos_conjunto[x].primer_elemento = y;
}

void inserta(int u, int v, int costo, rama **arbol)
{
    rama *nuevo = (rama *)malloc(sizeof(rama));
    nuevo->a.u = u;
    nuevo->a.v = v;
    nuevo->a.costo = costo;
    nuevo->sig = *arbol;
    *arbol = nuevo;

    if (!*arbol)
    {
        *arbol = nuevo;
    }
    nuevo->sig = *arbol;
    *arbol = nuevo;
}