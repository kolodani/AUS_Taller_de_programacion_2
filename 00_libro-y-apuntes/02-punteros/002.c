#include <stdio.h>
#include <stdlib.h>

int leerCantidad() // funcion que devuelve un entero y no recibe parametros
{
    int cantidad;                              // variable local cantidad
    printf("Cuantos numeros va a ingresas?:"); // imprime el mensaje al usuario
    scanf("%d", &cantidad);                    // lee el valor ingresado por el usuario y lo asigna a la variable cantidad
    return cantidad;                           // devuelve el valor de la variable cantidad
}

void leer(int cantidad, int *numeros) // funcion que no devuelve nada y recibe como parametro un entero y un puntero a entero
{
    int i;                         // variable local i
    for (i = 0; i < cantidad; i++) // bucle for que se ejecuta desde 0 hasta el valor de la variable cantidad
    {
        printf("Ingrese el numero %d: ", i + 1); // imprime un mensaje al usuario
        scanf("%d", numeros + i);                // lee el valor ingresado por el usuario y lo asigna a la posicion i del arreglo de numeros
        printf("\n");                            // imprime un salto de linea
    }
}

void imprimir(int cantidad, int *numeros) // funcion que no devuelve nada y recibe como parametro un entero y un puntero a entero
{
    int i;                                   // variable local i
    printf("Los numeros ingresados son:\n"); // imprime un mensaje al usuario

    for (i = 0; i < cantidad; i++) // bucle for que se ejecuta desde 0 hasta el valor de la variable cantidad
    {
        printf("%d ", *(numeros + i)); // recorre el arreglo de numeros con aritmetica de punteros
    }
    printf("\n"); // imprime un salto de linea
}

int main(void)
{
    int cantidad = leerCantidad();                        // llama a la funcion leerCantidad y asigna el valor devuelto a la variable cantidad
    int *numeros = (int *)malloc(cantidad * sizeof(int)); // asigna la memoria justa para los numeros que se van a ingresar
    if (numeros == NULL)                                  // si el puntero numeros no apunta a nada
    {
        return -1; // si el puntero no apunta a nada devuelve -1 y finaliza el programa
    }
    leer(cantidad, numeros);     // llama a la funcion leer y le pasa como parametros la cantidad de numeros a ingresar y el puntero numeros
    imprimir(cantidad, numeros); // llama a la funcion imprimir y le pasa como parametros la cantidad de numeros a ingresar y el puntero numeros

    free(numeros); // libera la memoria asignada
    return 0;
}