/* pilaArray.c */

#include <stdio.h>
#include "pilaArray.h"

int main()
{
   desapila();
   printf("Cima: %d\n", valorCima());
   apila(10);
   apila(12);
   apila(33);
   apila(45);
   printf("Cima: %d\n", valorCima());
   desapila();
   desapila();
   printf("Cima: %d\n", valorCima());
   for (int i = 0; i < cima + 1; i++)
   {
      printf("%d\n", elementos[i]);
   }

   return 0;
}

int valorCima()
{
   return elementos[cima];
}

int estaVacia()
{
   if (cima == -1)
      return -1;
   return 0;
}

int tamaño()
{
   return cima + 1;
}

void vaciaPila()
{
   cima = -1;
}

void apila(int elemento)
{
   if (tamaño() == CAPACIDAD)
   {
      printf("La pila esta llena");
      return;
   }
   cima++;
   elementos[cima] = elemento;
}

int desapila()
{
   if (estaVacia() == -1)
   {
      printf("La pila esta vacia\n");
      return -1;
   }
   int elemento = elementos[cima];
   cima--;
   return elemento;
}