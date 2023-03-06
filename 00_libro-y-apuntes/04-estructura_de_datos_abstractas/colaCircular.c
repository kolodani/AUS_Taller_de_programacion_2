/* colaCircular.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colaCircular.h"
#define MAX_LONG 10

int main()
{
    cola **inicio, **fin, *listaCola;
    listaCola = (cola *)malloc(sizeof(cola) * MAX_LONG);
    inicio = &listaCola;
    fin = &listaCola;
    return 0;
}

int suma_uno(int i)
{
    return ((i % MAX_LONG) + 1);
}

void anula(cola *inicio, cola *fin)
{
    inicio = fin = NULL;
}

bool vacia(cola *inicio, cola *fin)
{
    if (inicio == fin)
        return true;
    else
        return false;
}

void encolar(cola *inicio, cola *fin, int dato)
{
    if (cantidad == MAX_LONG - 1)
    {
        printf("La cola está llena");
        return;
    }
    else
    {
        cantidad++;
        cola *nuevo;
        nuevo = (cola *)malloc(sizeof(cola));
        nuevo->dato = dato;
        nuevo->sgte = NULL;
        if (vacia(inicio, fin))
        {
            inicio = fin = nuevo;
        }
        else
        {
            fin->sgte = nuevo;
            fin = nuevo;
        }
    }
}

void desencolar(cola *inicio, cola *fin)
{
    if (vacia(inicio, fin) && cantidad == 0)
    {
        printf("La cola está vacía");
        return;
    }
    else
    {
        cola *aux;
        aux = inicio;
        inicio = inicio->sgte;
        free(aux);
    }
}