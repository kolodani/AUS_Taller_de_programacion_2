/* colaLista.h */

typedef struct nodo {
   int dato;
   struct nodo *sgte;
}cola;

/*
 * que añade un elemento al final de la cola
 */
void encola(cola **, cola **, int);

/*
 * elimina y retorna el primer elemento de la cola.
 * el segundo pasa a ser el primero luego de la operacion
 */
int desoncola(cola **, cola **);

/*
 * vacia la cola, el tamaño pasa a ser cero
 */
void vaciaCola (cola **);

/*
 * retorna el tamaño de la cola, el numero de elementos
*/
int tamaño (cola *);

/*
 * retorna verdadero si es vacia
*/
int estaVacia (cola **);

/*
 * retorna pero no elimina el primer elemento
*/
int frente (cola *);