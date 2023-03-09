/* arbolbinario.h */

#define long_max 25;

typedef struct nodo {
    int dato;
    struct nodo *h_izq;
    struct nodo *h_der;
}arbol;

void inserta(arbol **, int);

int es_miembro(arbol *, int);

int suprime_minimo(arbol **);

void suprime(arbol **, int);

void listar(arbol *);

void inorder(arbol *);

void preorder(arbol *);

void postorder(arbol *);