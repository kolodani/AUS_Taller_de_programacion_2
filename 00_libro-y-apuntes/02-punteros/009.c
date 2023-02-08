/* Enumeraciones */

#include <stdio.h>

typedef enum TiposFormas // defino la enumeracion que es un tipo de dato que contiene un conjunto de valores constantes
{
    circulo, // creo tres constantes
    cuadrado,
    rectangulo
} TiposFormas; // le doy un alias a la enumeracion

int main()
{
    TiposFormas forma = rectangulo; // al cambiar el valor el switch mostrara los otros casos
    switch (forma)                  // switch para mostrar el valor de la enumeracion
    {
    case circulo:                                                // caso del circulo
        printf("Se eligio el circulo -> valor: %d\n", forma);    // muestro el valor de la enumeracion
        break;                                                   // rompo el switch
    case cuadrado:                                               // caso del cuadrado
        printf("Se eligio el cuadrado -> valor: %d\n", forma);   // muestro el valor de la enumeracion
        break;                                                   // rompo el switch
    case rectangulo:                                             // caso del rectangulo
        printf("Se eligio el rectangulo -> valor: %d\n", forma); // muestro el valor de la enumeracion
        break;                                                   // rompo el switch
    default:                                                     // caso por defecto vacio
        break;                                                   // rompo el switch
    }
    return 0;
}