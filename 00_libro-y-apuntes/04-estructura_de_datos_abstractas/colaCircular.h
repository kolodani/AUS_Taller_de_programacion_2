/* colaCircular.h */

typedef struct nodo
{
    int dato;
    struct nodo *sgte;
} cola;

int cantidad = 0;

/*
 * 
 */
int suma_uno(int);

/*
 * anula la cola, la deja completamente vacía
 */
void anula(cola *, cola *);

/*
 * devuelve un booleano indicando si la cola está vacía o no
 */
bool vacia(cola *, cola *);

/*
 * agrega un elemento al final de la cola
 */
void encolar(cola *, cola *, int);

/*
 * elimina el primer elemento de la cola
 */
void desencolar(cola *, cola *);