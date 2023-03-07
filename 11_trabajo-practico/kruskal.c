/* kruskal.c */

#include "kruskal.h"

int main()
{
    int M_Costos[VERTICES][VERTICES];
    rama *arbol;

    for (int i = 0; i < VERTICES - 1; i++)
    {
        for (int j = i + 1; j < VERTICES - 1; j++)
        {
            printf("Ingrese el costo de lado entre vertices %d y %d: ", i, j);
            scanf("%d", &M_Costos[i][j]);
        }
    }

    for (int i = 0; i < VERTICES - 1; i++)
    {
        for (int j = i + 1; j < VERTICES - 1; j++)
        {
            if (M_Costos[i][j] != 0)
            {
                inserta(i, j, M_Costos[i][j], &arbol);
            }
        }
    }
    kruskal(arbol);
}