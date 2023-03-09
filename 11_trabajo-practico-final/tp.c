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
        printf("(%d - %d , %d) |", arbol->a.u, arbol->a.v, arbol->a.costo);
        lista(arbol->sig);
    }
}

void inicial(tipo_nombre x, tipo_elemento y, conjunto_ce *ce)
{
    ce->nombres[y].nombre_conjunto = x;
    ce->nombres[y].siguiente_elemento = 0;
    ce->encabezamientos_conjunto[x].cuenta = 1;
    ce->encabezamientos_conjunto[x].primer_elemento = y;
}

void inserta(int u, int v, int costo, rama **arbol)
{
    rama *nuevo = (rama *)malloc(sizeof(rama));
    nuevo->a.u = u;
    nuevo->a.v = v;
    nuevo->a.costo = costo;
    nuevo->sig = NULL;

    if (!*arbol)
    {
        *arbol = nuevo;
        return;
    }
    nuevo->sig = *arbol;
    *arbol = nuevo;
}

arista *sacar_min(rama **arbol)
{
    rama *aux = *arbol;
    rama *min = *arbol;
    rama *prev = NULL;
    rama *prev_min = NULL;

    if (!*arbol)
    {
        printf("No hay aristas en el arbol");
        return NULL;
    }
    while (aux)
    {
        if (aux->a.costo < min->a.costo)
        {
            min = aux;
            prev_min = prev;
        }
        prev = aux;
        aux = aux->sig;
    }
    if (prev_min)
    {
        prev_min->sig = min->sig;
    }
    else
    {
        *arbol = min->sig;
    }
    return &min->a;
}

void combina(tipo_nombre x, tipo_nombre y, conjunto_ce *ce)
{
    int aux, i;
    if (ce->encabezamientos_conjunto[x].cuenta > ce->encabezamientos_conjunto[y].cuenta)
    {
        i = ce->encabezamientos_conjunto[y].primer_elemento;
        while (ce->nombres[i].siguiente_elemento != 0)
        {
            ce->nombres[i].nombre_conjunto = x;
            i = ce->nombres[i].siguiente_elemento;
        }
        ce->nombres[i].nombre_conjunto = x;
        ce->nombres[i].siguiente_elemento = ce->encabezamientos_conjunto[x].primer_elemento;
        ce->encabezamientos_conjunto[x].primer_elemento = ce->encabezamientos_conjunto[y].primer_elemento;
        ce->encabezamientos_conjunto[x].cuenta += ce->encabezamientos_conjunto[y].cuenta;
        ce->encabezamientos_conjunto[y].cuenta = 0;
    }
    else
    {
        i = ce->encabezamientos_conjunto[x].primer_elemento;
        while (ce->nombres[i].siguiente_elemento != 0)
        {
            ce->nombres[i].nombre_conjunto = y;
            i = ce->nombres[i].siguiente_elemento;
        }
        ce->nombres[i].nombre_conjunto = y;
        ce->nombres[i].siguiente_elemento = ce->encabezamientos_conjunto[y].primer_elemento;
        ce->encabezamientos_conjunto[y].primer_elemento = ce->encabezamientos_conjunto[x].primer_elemento;
        ce->encabezamientos_conjunto[y].cuenta += ce->encabezamientos_conjunto[x].cuenta;
        ce->encabezamientos_conjunto[x].cuenta = 0;
    }
}

void kruskal(rama *arbol)
{
    int componentes = VERTICES, i;
    arista *arbol_minimo = NULL, *arista_minima;
    conjunto_ce ce;
    vertice x, y;
    tipo_nombre x_nombre, y_nombre;

    if (!arbol)
    {
        printf("No hay aristas en el arbol");
        return;
    }
    for (i = 0; i < VERTICES; i++)
    {
        inicial(i, i, &ce);
    }
    while (componentes > 1)
    {
        arista_minima = sacar_min(&arbol);
        x = arista_minima->u;
        y = arista_minima->v;
        x_nombre = encuentra(x, &ce);
        y_nombre = encuentra(y, &ce);
        if (x_nombre != y_nombre)
        {
            combina(x_nombre, y_nombre, &ce);
            arista_minima->sig = arbol_minimo;
            arbol_minimo = arista_minima;
            componentes--;
        }
        else
        {
            if (arista_minima)
            {
                free(arista_minima);
            }
        }
    }
    lista(arbol_minimo);
}