/* colaLista.h */

typedef struct nodo {
   int dato;
   struct nodo *sgte;
}cola;

void encola(cola **, cola **, int);

int desoncola(cola **, cola **);

void caciaCola (cola **);

int tamaño (cola *);

int estaVacia (cola **);

int frente (pila*);