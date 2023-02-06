/* arbolbinario.c */

#include <stdio.h>
#include <stdlib.h>
#include "arbolbinario.h"

void inserta(arbol **A, int x)
{
    if (*A == NULL)
    {
        *A = (arbol *)malloc(sizeof(arbol));
        (*A)->dato = x;
        (*A)->h_izq = NULL;
        (*A)->h_der = NULL;
    }
    else
    {
        if (x < (*A)->dato)
        {
            inserta(&((*A)->h_izq), x);
        }
        else if (x > (*A)->dato)
        {
            inserta(&((*A)->h_der), x);
        }
    }
}

int es_miembro(arbol *A, int x)
{
    if (A == NULL)
    {
        return -1;
    }
    else if (A->dato == x)
    {
        return 1;
    }
    else if (x < A->dato)
    {
        return es_miembro(A->h_izq, x);
    }
    else
    {
        return es_miembro(A->h_der, x);
    }
}

int main()
{
    arbol *raiz;
    raiz = NULL;

    /* armar codigo de main para probar el arbol */

    inserta(&raiz, 10);
    inserta(&raiz, 5);
    inserta(&raiz, 18);
    inserta(&raiz, 16);
    inserta(&raiz, 3);

    if (es_miembro(raiz, 5) == 1)
    {
        printf("El elemento buscado existe en el arbol\n");
    }
    else
    {
        printf("No existe\n");
    }
    if (es_miembro(raiz, 124) == 1)
    {
        printf("El elemento buscado existe en el arbol\n");
    }
    else
    {
        printf("No existe\n");
    }

    return 0;
}