#include <stdio.h>

// Estructura que permite representar numeros enteros con precision arbitraria
typedef struct {
    char sign;
    unsigned char num_bytes;
    unsigned char * bytes;
} APint;

// Prototipo de funciones
APint * suma_APint (APint * i1, APint * i2);
APint * producto_APint (APint * i1, APint * i2);

int main()
{
    
    return 0;
}

// Funcion que suma dos numeros enteros con precision arbitraria
