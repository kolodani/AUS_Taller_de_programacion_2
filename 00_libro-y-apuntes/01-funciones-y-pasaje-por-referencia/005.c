/* scope3.c */

/* en este caso se hace externa a la variable para que su uso sea global en el programa */

#include <stdio.h>

void unaFuncion() // la funcion no recibe parametros y utiliza la variable global externa
{
  extern int variable;                                             // variable global externa
  printf("En la funcion unaFuncion, variable es: %d\n", variable); // imprime el valor de la variable
}

void otraFuncion() // la funcion no recibe parametros y utiliza la variable global externa
{
  extern int variable;                                                 // variable global externa
  variable++;                                                          // incrementa el valor de la variable
  printf("EN la funcion otraFuncion, la variable es: %d\n", variable); // imprime el valor de la variable
}

int main()
{
  extern int variable;                                     // variable global externa
  variable = 9;                                            // inicializa la variable
  printf("El valor de la variable es: %d\n", variable);    // imprime el valor de la variable
  unaFuncion();                                            // llama a la funcion unaFuncion
  otraFuncion();                                           // llama a la funcion otraFuncion
  printf("Ahora el valor de variable es: %d\n", variable); // imprime el valor de la variable
  return 0;
}

int variable; // variable global