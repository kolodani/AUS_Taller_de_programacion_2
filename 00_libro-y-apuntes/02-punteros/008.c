/* accediendo a las uniones */

#include <stdio.h>
#include <string.h>

union Data
{
  int i;
  float f;
  char str[20];
};

int main()
{

  union Data data;
  
  /* forma erronea de mostrar los datos de una union ya que la misma toda la union tiene una sola direccion de memoria y solo se muestra el ultimo valor guardado */
  // data.i = 10;
  // data.f = 220.5;
  // strcpy(data.str, "C Programming");

  // printf("data.i : %d\n", data.i);
  // printf("data.f : %f\n", data.f);
  // printf("data.str : %s\n", data.str);

  data.i = 10;
  printf("data.i : %d\n", data.i);

  data.f = 220.5;
  printf("data.f : %f\n", data.f);

  strcpy(data.str, "C Programming");
  printf("data.str : %s\n", data.str);

  return 0;
}