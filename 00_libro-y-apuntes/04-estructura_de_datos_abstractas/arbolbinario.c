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

int suprime_min(arbol **A)
{
    int v_ref;
    if ((*A)->h_izq == NULL)
    {
        v_ref = (*A)->dato;
        arbol *tmp = *A;
        *A = (*A)->h_der;
        free(tmp);
        return v_ref;
    }
    else
    {
        return suprime_min(&((*A)->h_izq));
    }
}

void suprime(arbol **A, int x)
{
    if (*A != NULL)
    {
        if (x < (*A)->dato)
        {
            suprime(&((*A)->h_izq), x);
        }
        else if (x > (*A)->dato)
        {
            suprime(&((*A)->h_der), x);
        }
        else
        {
            if ((*A)->h_izq == NULL && (*A)->h_der == NULL)
            {
                free(*A);
                *A = NULL;
            }
            else if ((*A)->h_izq == NULL)
            {
                arbol *tmp = *A;
                *A = (*A)->h_der;
                free(tmp);
            }
            else if ((*A)->h_der == NULL)
            {
                arbol *tmp = *A;
                *A = (*A)->h_izq;
                free(tmp);
            }
            else
            {
                (*A)->dato = suprime_min(&((*A)->h_der));
            }
        }
    }
}

void inorden(arbol *A)
{
    if (A != NULL)
    {
        inorden(A->h_izq);
        printf("%d ", A->dato);
        inorden(A->h_der);
    }
}

void preorden(arbol *A)
{
    if (A != NULL)
    {
        printf("%d ", A->dato);
        preorden(A->h_izq);
        preorden(A->h_der);
    }
}

void postorden(arbol *A)
{
    if (A != NULL)
    {
        postorden(A->h_izq);
        postorden(A->h_der);
        printf("%d ", A->dato);
    }
}

int main()
{
    arbol *raiz;
    raiz = NULL;

    /* armar codigo de main para probar el arbol */

    inserta(&raiz, 12);
    inserta(&raiz, 7);
    inserta(&raiz, 20);
    inserta(&raiz, 24);
    inserta(&raiz, 3);
    inserta(&raiz, 8);
    inserta(&raiz, 15);
    inserta(&raiz, 30);

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

    // impresiones
    printf("Inorden: ");
    inorden(raiz);
    printf("\n");
    printf("Preorden: ");
    preorden(raiz);
    printf("\n");
    printf("Postorden: ");
    postorden(raiz);
    printf("\n");

    return 0;
}