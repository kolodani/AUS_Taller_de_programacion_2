/*
 *   PRIMER PARCIAL
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int id = 0;

typedef struct proceso
{
    int procesador;
    int id_proceso;
    int prioridad;
    char estado[10];
} proceso;

proceso *scheduling[10];

/* Asigna el siguiente estado según el orden enunciado antes */
void asignaEstado(proceso *);
/* Ingresa el proceso al Scheduler en el primer espacio libre que encuentre*/
void ingresaProceso();
/*Quita el proceso de la cola liberando y retornando el lugar liberado*/
int terminaProceso();
/*Recorrera todos los procesos de la cola, haciendo el cambio del estado de los mismos*/
void recorreCola();
/*Lista los procesos de la cola*/
void mostrarScheduler();

int main()
{

    return 0;
}

void asignaEstado(proceso *proceso)
{
    if (strcmp(proceso->estado, "Corriendo") == 0)
    {
        strcpy(proceso->estado, "Terminado");
    }
    if ((strcmp(proceso->estado, "Listo") == 0 || strcmp(proceso->estado, "Nuevo") == 0) && 
    (proceso->procesador == 1 || proceso->procesador == 2))
    {
        strcpy(proceso->estado, "Corriendo");
    }
    if (strcmp(proceso->estado, "Nuevo") == 0 )
    {
        strcpy(proceso->estado, "Listo");
    }
}

void ingresaProceso()
{
    int i;
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        if (scheduling[i] == NULL)
        {
            proceso *proceso = (proceso *)malloc(sizeof(proceso));
            proceso->procesador = 0;
            proceso->id_proceso = rand() % 10000;
            proceso->prioridad = id;
            strcpy(proceso->estado, "Nuevo");
            scheduling[i] = proceso;
            id++;
            break;
        }
    }
}

int terminaProceso()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (scheduling[i] != NULL)
        {
            if (strcmp(scheduling[i]->estado, "Terminado") == 0)
            {
                free(scheduling[i]);
                scheduling[i] = NULL;
                return scheduling[i]->procesador;
            }
        }
    }
    return -1;
}

void recorreCola()
{
    int i, j, procesadorUno = 0, procesadorDos = 0, prioridadUno = 0, prioridadDos = 0;
    for (i = 0; i < 10; i++)
    {
        if (scheduling[i]->procesador == 1)
        {
            procesadorUno++;
        }
        if (scheduling[i]->procesador == 2)
        {
            procesadorDos++;
        }
    }
    if (procesadorUno == 0)
    {
        for (i = 0; i < 10; i++)
        {
            if (scheduling[i]->prioridad < scheduling[prioridadUno]->prioridad)
            {
                prioridadUno = i;
            }
        }
        scheduling[prioridadUno]->procesador = 1;
    }
    if (procesadorDos == 0)
    {
        for (i = 0; i < 10; i++)
        {
            if (scheduling[i]->prioridad < scheduling[prioridadDos]->prioridad)
            {
                prioridadDos = i;
            }
        }
        scheduling[prioridadDos]->procesador = 2;
    }
}

void mostrarScheduler()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("[%d]-> {%d;%d;%d;%s}", i, scheduling[i]->procesador, scheduling[i]->id_proceso, scheduling[i]->prioridad, scheduling[i]->estado);
    }
}