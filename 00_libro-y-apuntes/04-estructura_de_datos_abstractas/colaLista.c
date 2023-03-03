/* colaLista.c */

#include <stdio.h>
#include <stdlib.h>
#include "colaLista.h"

int main()
{
   cola *inicio, *final;
   inicio = NULL;
   final = NULL;

   encola(&inicio, &final, 10);
   encola(&inicio, &final, 20);
   encola(&inicio, &final, 30);
   encola(&inicio, &final, 40);
   encola(&inicio, &final, 50);
   printf("El tamaño de la cola es: %d\n", tamaño(inicio));
   printf("El primer elemento de la cola es: %d\n", frente(inicio));
   desoncola(&inicio, &final);
   printf("El primer elemento de la cola es: %d\n", frente(inicio));
   desoncola(&inicio, &final);
   printf("El primer elemento de la cola es: %d\n", frente(inicio));
   printf("El tamaño de la cola es: %d\n", tamaño(inicio));
   vaciaCola(&inicio);
   printf("El tamaño de la cola es: %d\n", tamaño(inicio));
   printf("El primer elemento de la cola es: %d\n", frente(inicio));
   return 0;
}

int frente (cola *inicio)
{
   if (inicio == NULL)
   {
      printf("La cola esta vacia\n");
      return 0;
   }
   return inicio->dato;
}

int estaVacia (cola **inicio)
{
   if (*inicio == NULL)
   {
      return 0;
   }
   else
   {
      return 1;
   }
}

int tamaño (cola *inicio)
{
   if (estaVacia(&inicio) == 0)
   {
      printf("La cola esta vacia\n");
      return 0;
   }
   int cont = 0;
   cola *aux;
   aux = inicio;
   while (aux != NULL)
   {
      cont++;
      aux = aux->sgte;
   }
   return cont;
}

void vaciaCola (cola **inicio)
{
   if (estaVacia(inicio) == 0)
   {
      printf("La cola esta vacia");
   } else {
      cola *aux;
      while (*inicio != NULL)
      {
         aux = *inicio;
         *inicio = (*inicio)->sgte;
         free(aux);
      }
   }
}

void encola(cola **inicio, cola **final, int dato)
{
   cola *nuevo;
   nuevo = (cola *)malloc(sizeof(cola));
   nuevo->dato = dato;
   nuevo->sgte = NULL;
   if (*inicio == NULL)
   {
      *inicio = nuevo;
      *final = nuevo;
   }
   else
   {
      (*final)->sgte = nuevo;
      *final = nuevo;
   }
}

int desoncola(cola **inicio, cola **final)
{
   if (estaVacia(inicio) == 0)
   {
      printf("La cola esta vacia");
      return 0;
   }
   int dato;
   cola *aux;
   aux = *inicio;
   dato = aux->dato;
   *inicio = (*inicio)->sgte;
   free(aux);
   return dato;
}