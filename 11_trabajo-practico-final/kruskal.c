#include "kruskal.h"

int main()
{
    int M_Costos[VERTICES][VERTICES]; // matriz con los pesos
    arista *cola = NULL;              // cola de prioridad
    int i, j;

    for (i = 0; i < VERTICES; i++) // diagonal superior
    {
        for (j = i + 1; j < VERTICES; j++)
        {
            printf("\nIngrese el costo de lado entre vertices %d y %d: ", i, j);
            scanf("%d", &M_Costos[i][j]);

            if (M_Costos[i][j])
                inserta(i, j, M_Costos[i][j], &cola); // inserta en cola de prioridad
        }
    }

    kruskal(&cola);
    return 0;
}

//*************************************************************************************************************
//* INSERTA
//*************************************************************************************************************
void inserta(vertice vi, vertice vj, int nuevo_costo, arista **cola)
{
    // agrega una arista a la cola de prioridad
    arista *aristaNueva = malloc(sizeof(arista));
    aristaNueva->vertice_u = vi;
    aristaNueva->vertice_v = vj;
    aristaNueva->costo = nuevo_costo;
    aristaNueva->sig = NULL;

    if (!*cola)
    {
        *cola = aristaNueva;
        return;
    }
    aristaNueva->sig = *cola;
    *cola = aristaNueva;
}

//*************************************************************************************************************
//* SACAR_MIN
//*************************************************************************************************************
arista *sacar_min(arista **cola)
{
    int min;
    arista *aux;
    arista *aristaMenor;
    if (!*cola) // si la cola esta vacia
    {
        printf("No hay aristas disponibles\n");
        return NULL;
    }
    /* inicializo */
    aristaMenor = *cola;
    min = aristaMenor->costo;
    aux = aristaMenor;

    /* encuentro la menor arista */
    while (aux)
    {
        if (aux->costo < min)
        {
            aristaMenor = aux;
            min = aristaMenor->costo;
        }
        aux = aux->sig;
    }

    if (*cola == aristaMenor)
    {
        // si la primer arista de la cola es la menor, apunto la cabeza de la cola al siguiente elemento
        *cola = aristaMenor->sig;
        return aristaMenor;
    }
    // encuentro la arista previa a la menor, vuelvo a atravesar la cola
    aux = *cola;
    while (aux->sig != aristaMenor)
        aux = aux->sig;

    aux->sig = aux->sig->sig; // apunto a la arista previa con la siguiente de la siguiente
    return aristaMenor;
}

//*************************************************************************************************************
//* INICIAL
//*************************************************************************************************************
void inicial(tipo_nombre x, conjunto_CE *ce)
{
    // nombre de un componente que pertenece al conjunto ce que inicialmente tiene al vertice tipo_elemento
    ce->nombres[x].nombre_conjunto = x;
    ce->nombres[x].siguiente_elemento = NIL;    // no posee siguiente elemento
    ce->encabezamientos[x].primer_elemento = x; // el primer elemento de un componente conexo es el mismo
    ce->encabezamientos[x].cuenta = 1;          // cada elemento comienza con
}

//*************************************************************************************************************
//* COMBINA
//*************************************************************************************************************
void combina(tipo_nombre x, tipo_nombre y, conjunto_CE *ce)
{
    // a y y son los conjuntos
    int i;
    if (ce->encabezamientos[x].cuenta > ce->encabezamientos[y].cuenta)
    {
        // si A es el conjunto mas grande, combinar B en A
        i = ce->encabezamientos[y].primer_elemento; // primer elemento del conjunto B
        while (ce->nombres[i].siguiente_elemento != NIL)
        {
            ce->nombres[i].nombre_conjunto = x; // nombre del conjunto que contiene a i pasa a ser a
            i = ce->nombres[i].siguiente_elemento;
        }
        // i ahora es igual al ultimo elemento del conjunto B (ahora unido con A)
        ce->nombres[i].nombre_conjunto = x;
        ce->nombres[i].siguiente_elemento = ce->encabezamientos[x].primer_elemento;
        ce->encabezamientos[x].primer_elemento = ce->encabezamientos[y].primer_elemento;
        ce->encabezamientos[x].cuenta += ce->encabezamientos[y].cuenta;

        ce->encabezamientos[y].cuenta = 0;
    }
    else
    {
        i = ce->encabezamientos[x].primer_elemento;
        while (ce->nombres[i].siguiente_elemento != NIL)
        {
            ce->nombres[i].nombre_conjunto = x; // nombre del conjunto que contiene a i pasa a ser a
            i = ce->nombres[i].siguiente_elemento;
        }

        // i ahora es igual al ultimo elemento del conjunto A (ahora unido con B)
        ce->nombres[i].nombre_conjunto = y;
        ce->nombres[i].siguiente_elemento = ce->encabezamientos[y].primer_elemento;
        ce->encabezamientos[y].primer_elemento = ce->encabezamientos[x].primer_elemento;
        ce->encabezamientos[y].cuenta += ce->encabezamientos[x].cuenta;

        ce->encabezamientos[x].cuenta = 0;
    }
}

//*************************************************************************************************************
//* LISTA
//*************************************************************************************************************
void lista(arista *cola)
{
    if (!cola)
    {
        printf("\n");
        return;
    }
    printf("(%d-%d,%d)\n", cola->vertice_u, cola->vertice_v, cola->costo);
    lista(cola->sig);
}

//*************************************************************************************************************
//* ENCUENTRA
//*************************************************************************************************************
tipo_nombre encuentra(vertice vi, conjunto_CE *ce)
{
    return ce->nombres[vi].nombre_conjunto;
}

//*************************************************************************************************************
//* KRUSKAL
//*************************************************************************************************************
void kruskal(arista **cola)
{
    int numero_componentes = VERTICES, i;
    arista *arbol = NULL, *aristaMenor;
    conjunto_CE combinaYencuentra;
    vertice vi, vj;
    tipo_nombre componenteX, componenteY;

    if (!*cola)
    {
        printf("No hay lados disponibles\n");
        return;
    }

    for (i = 0; i < VERTICES; i++)
        inicial(i, &combinaYencuentra); // incializo el conjunto combina-encuentra

    while (numero_componentes > 1)
    {
        aristaMenor = sacar_min(cola);
        vi = aristaMenor->vertice_u; // vertice de cada arista
        vj = aristaMenor->vertice_v;
        componenteX = encuentra(vi, &combinaYencuentra);
        componenteY = encuentra(vj, &combinaYencuentra);
        if (componenteX != componenteY)
        {                                        // si las componentes son disconexas, entonces
            combina(vi, vj, &combinaYencuentra); // combino las componentes
            aristaMenor->sig = arbol;           // agrego la arista al arbol abarcador de menor costo
            arbol = aristaMenor;
            numero_componentes--; // una componente seguro fue combinada con otra si la arista juntaba dos componentes disconexas, por eso tengo una menos
        }
        else
        {
            if (aristaMenor)
                free(aristaMenor); // descarto la arista si estuvo en un primer momento
        }
    }
    lista(arbol);
}
