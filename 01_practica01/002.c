/*
    Practica 01
    Ejercicio 02 Estadistica de notas
*/

#include <stdio.h>

int main()
{
    int materias, alumnos, i, j;
    
    printf("Bienvenido a las estadisticas de notas\n");
    printf("Primero elija el la cantidad de materias que hay:\n");
    printf("> ");
    scanf("%d", &materias);
    printf("Ahora elija la cantidad de alumnos:\n");
    printf("> ");
    scanf("%d", &alumnos);
    
    float notas[alumnos][materias];
    float promedioalumno[materias], promediomateria[alumnos];
    float suma = 0.0;
    
    for (i = 0; i < alumnos; i++)
    {
        for (j = 0; j < materias; j++)
        {
            printf("Ingrese la nota del alumno %d de la materia %d: ", i + 1, j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
    printf("\n");
    
    printf("El promedio de cada alumno es:\n");
    for (i = 0; i < alumnos; i++)
    {
        for (j = 0; j < materias; j++)
        {
            suma += notas[i][j];
        }
        promedioalumno[i] = suma / materias;
        suma = 0.0;
        printf("El promedio del alumno %d es: %.2f\n", i + 1, promedioalumno[i]);
        if (promedioalumno[i] < 6.0)
        {
            printf("El alumno %d esta LIBRE\n", i + 1);
        }
        else if (promedioalumno[i] >= 8.0)
        {
            printf("El alumno %d esta PROMOVIDO\n", i + 1);
        }
        else
        {
            printf("El alumno %d esta REGULAR\n", i + 1);
        }
        printf("\n");
    }
    
    printf("El promedio de cada materia es:\n");
    for (j = 0; j < materias; j++)
    {
        for (i = 0; i < alumnos; i++)
        {
            suma += notas[i][j];
        }
        promediomateria[j] = suma / alumnos;
        suma = 0.0;
        printf("El promedio de la materia %d es: %.2f\n\n", j + 1, promediomateria[j]);
    }

    return 0;
}
