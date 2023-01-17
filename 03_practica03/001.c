/*
    Practica 03
    Ejercicio 01
*/

#include <stdio.h>
#include <string.h>

// estructura
typedef struct
{
    int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

typedef struct
{
    char *nombre;
    Tiempo ultima_mod;
} Archivo;

// prototipos
int compara_tiempo(Tiempo *t1, Tiempo *t2);
void imprime_tiempo(Tiempo t);
void ordena_alfa(Archivo *lista, int n);
void ordena_temporal(Archivo *lista, int n);

// parte principal
int main()
{
    Tiempo t1, t2;
    Tiempo *pt1, *pt2;
    pt1 = &t1;
    pt2 = &t2;
    Archivo lista[3] = {
        {"bbb.txt", {2015, 10, 1, 12, 30, 12}},
        {"ccc.txt", {2018, 10, 1, 12, 30, 12}},
        {"aaa.txt", {2021, 10, 1, 12, 30, 12}}};
    Archivo *p_lista = lista;
    int comparacion;

    t1.anio = 2018;
    t1.mes = 8;
    t1.dia = 30;
    t1.hora = 15;
    t1.minuto = 13;
    t1.segundo = 14;

    t2.anio = 2019;
    t2.mes = 8;
    t2.dia = 30;
    t2.hora = 15;
    t2.minuto = 13;
    t2.segundo = 14;

    comparacion = compara_tiempo(pt1, pt2);
    if (comparacion == 1)
    {
        printf("El tiempo 1 es anterior que el tiempo 2\n");
    }
    else if (comparacion == -1)
    {
        printf("El tiempo 2 es anterior que el tiempo 1\n");
    }
    else
    {
        printf("Los tiempos son iguales\n");
    }

    printf("Tiempo 1: ");
    imprime_tiempo(t1);
    printf("Tiempo 2: ");
    imprime_tiempo(t2);

    ordena_alfa(p_lista, 3);
    printf("Lista ordenada alfabeticamente: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s ", lista[i].nombre);
        imprime_tiempo(lista[i].ultima_mod);
    }

    ordena_temporal(p_lista, 3);
    printf("Lista ordenada temporalmente: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s ", lista[i].nombre);
        imprime_tiempo(lista[i].ultima_mod);
    }

    return 0;
}

// funcion que compara dos tiempos
int compara_tiempo(Tiempo *t1, Tiempo *t2)
{
    if (t1->anio < t2->anio)
        return 1;
    if (t1->anio > t2->anio)
        return -1;
    if (t1->mes < t2->mes)
        return 1;
    if (t1->mes > t2->mes)
        return -1;
    if (t1->dia < t2->dia)
        return 1;
    if (t1->dia > t2->dia)
        return -1;
    if (t1->hora < t2->hora)
        return 1;
    if (t1->hora > t2->hora)
        return -1;
    if (t1->minuto < t2->minuto)
        return 1;
    if (t1->minuto > t2->minuto)
        return -1;
    if (t1->segundo < t2->segundo)
        return 1;
    if (t1->segundo > t2->segundo)
        return -1;
    return 0;
}

// funcion que imprime un tiempo
void imprime_tiempo(Tiempo t)
{
    printf("%d/%d/%d %d:%d:%d\n", t.dia, t.mes, t.anio, t.hora, t.minuto, t.segundo);
}

// funcion que ordena una lista de archivos alfabeticamente
void ordena_alfa(Archivo *lista, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                Archivo aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

// funcion que ordena una lista de archivos por fecha de modificacion
void ordena_temporal(Archivo *lista, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (compara_tiempo(&lista[i].ultima_mod, &lista[j].ultima_mod) == -1)
            {
                Archivo aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}