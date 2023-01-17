/*
    Practica 03
    Ejercicio 03
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Estructura que permite representar numeros enteros con precision arbitraria
typedef struct
{
    char sign;
    unsigned char num_bytes;
    unsigned char *bytes;
} APint;

// Prototipo de funciones
APint *suma_APint(APint *i1, APint *i2);
APint *producto_APint(APint *i1, APint *i2);

int main()
{
    srand(time(NULL));
    int i;
    APint *i1, *i2;
    i1 = (APint *)malloc(sizeof(APint));
    i2 = (APint *)malloc(sizeof(APint));
    i1->sign = 1;
    i2->sign = 1;
    i1->num_bytes = 4;
    i2->num_bytes = 1;
    i1->bytes = (unsigned char *)malloc(sizeof(unsigned char) * (8 * i1->num_bytes));
    i2->bytes = (unsigned char *)malloc(sizeof(unsigned char) * (8 * i2->num_bytes));
    for (i = 0; i < (8 * i1->num_bytes); i++)
    {
        i1->bytes[i] = rand() % 2;
    }
    for (i = 0; i < (8 * i2->num_bytes); i++)
    {
        i2->bytes[i] = rand() % 2;
    }
    printf("i1 = ");
    for (i = (8 * i1->num_bytes) - 1; i >= 0; i--)
    {
        printf("%d", i1->bytes[i]);
    }
    printf("\n");
    printf("i2 = ");
    for (i = (8 * i2->num_bytes) - 1; i >= 0; i--)
    {
        printf("%d", i2->bytes[i]);
    }
    return 0;
}

// Funcion que suma dos numeros enteros con precision arbitraria
APint *suma_APint(APint *i1, APint *i2)
{
    
}