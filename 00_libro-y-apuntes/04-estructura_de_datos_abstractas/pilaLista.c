/* pilaLista.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilaLista.h"

/* Completar las funciones prototipadas en el .h */

int main()
{
   pila *cima;
   cima = NULL;
   apila(&cima, 10);
   apila(&cima, 20);
   apila(&cima, 30);
   printf("Cima: %d\n", valorCima(cima));
   printf("Tamaño: %d\n", tamaño(cima));
   desapila(&cima);
   desapila(&cima);
   apila(&cima, 400);
   printf("Cima: %d\n", valorCima(cima));
   printf("Tamaño: %d\n", tamaño(cima));
   vaciaPila(&cima);
   printf("Cima: %d\n", valorCima(cima));
   printf("Tamaño: %d\n", tamaño(cima));

   return 0;
}

int valorCima(pila *cima)
{
   if (estaVacia(&cima) == true)
   {
      printf("Pila vacia\n");
      return 0;
   }
   return cima->dato;
}

bool estaVacia (pila **cima)
{
   if (*cima == NULL)
      return true;
   else
      return false;
}

int tamaño (pila *cima)
{
   if (estaVacia(&cima) == true)
   {
      printf("Pila vacia\n");
      return 0;
   }
   int i = 0;
   while (estaVacia(&cima) == false)
   {
      cima = cima->sgte;
      i++;
   }
   return i;
}

void vaciaPila (pila **cima)
{
   pila *aux;
   while (estaVacia(cima) == false)
   {
      aux = *cima;
      *cima = (*cima)->sgte;
      free(aux);
   }
}

void apila (pila **cima, int dato)
{
   pila *nuevo;
   nuevo = (pila *)malloc(sizeof(pila));
   nuevo->dato = dato;
   nuevo->sgte = *cima;
   *cima = nuevo;
}

int desapila (pila **cima)
{
   int dato;
   pila *aux;
   aux = *cima;
   dato = aux->dato;
   *cima = (*cima)->sgte;
   free(aux);
   return dato;
}