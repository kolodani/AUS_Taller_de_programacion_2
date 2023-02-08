/* accediendo a las uniones */

#include <stdio.h>
#include <string.h>

union Data // defino la union
{
    int i;        // variable entera
    float f;      // variable flotante
    char str[20]; // arreglo de caracteres
};

int main()
{
    union Data data; // declaro una variable de tipo union
    /* forma erronea de mostrar los datos de una union ya que la misma toda la union tiene una sola direccion de memoria y solo se muestra el ultimo valor guardado */
    // data.i = 10;
    // data.f = 220.5;
    // strcpy(data.str, "C Programming");
    // printf("data.i : %d\n", data.i);
    // printf("data.f : %f\n", data.f);
    // printf("data.str : %s\n", data.str);
    data.i = 10;                         // guardo el valor 10 en la variable i
    printf("data.i : %d\n", data.i);     // muestro el valor de la variable i
    data.f = 220.5;                      // guardo el valor 220.5 en la variable f
    printf("data.f : %f\n", data.f);     // muestro el valor de la variable f
    strcpy(data.str, "C Programming");   // guardo el valor "C Programming" en la variable str
    printf("data.str : %s\n", data.str); // muestro el valor de la variable str
    return 0;
}