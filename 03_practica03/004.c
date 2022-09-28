#include <stdio.h>
#include <math.h>

typedef struct {
    double abscisa;
    double ordenada;
} tipoPunto;

typedef struct {
    tipoPunto situacion;
    char nombre[50];
} tipoCiudad;

void Reordenar (tipoCiudad ciudades[], int num_ciudades, const char nombre_ciudad_referencia[]);

int main()
{
    return 0;
}

void Reordenar(tipoCiudad ciudades[], int num_ciudades, const char nombre_ciudad_referencia[]){
    int i, j, k;
    double restaAbscisaA, restaOrdenadaA, totalA;
    double restaAbscisaB, restaOrdenadaB, totalB;
    struct tipoCiudad aux;
    for (i = 0; i < num_ciudades; i++)
    {
        if (ciudades[i].nombre == nombre_ciudad_referencia)
        {
            aux = ciudades[0];
            ciudades[0] = ciudades[i];
            ciudades[i] = aux;
        }
    }
    for(i = 0; i<num_ciudades; i++)
    {
        for (j = i + 1; j < num_ciudades; j++)
        {
            for (k = j + 1; k < num_ciudades; k++)
            {
                restaAbscisaA = ciudades[i].situacion.abscisa - ciudades[j].situacion.abscisa;
                restaOrdenadaA = ciudades[i].situacion.ordenada - ciudades[j].situacion.ordenada;
                totalA = sqrt(pow(restaAbscisaA, 2) + pow(restaOrdenadaA, 2));
                
                restaAbscisaB = ciudades[i].situacion.abscisa - ciudades[k].situacion.abscisa;
                restaOrdenadaB = ciudades[i].situacion.ordenada - ciudades[k].situacion.ordenada;
                totalB = sqrt(pow(restaAbscisaB, 2) + pow(restaOrdenadaB, 2));
                
                if (totalA > totalB)
                {
                    aux = ciudades[j];
                    ciudades[j] = ciudades[k];
                    ciudades[k] = aux;
                }
            }
        }
    }
}