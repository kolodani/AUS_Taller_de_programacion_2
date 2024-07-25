#include <stdio.h>

int main(int argc, char *argv[])
{
    int alumnos, materias, promedio;

    do {
        printf("Ingrese el numero de alumnos que hay en el curso:\n");
        printf("> ");
        scanf("%d", &alumnos);
    } while (alumnos <= 0);
    do {
        printf("Ingrese el numero de materias que hay en el curso:\n");
        printf("> ");
        scanf("%d", &materias);
    } while (materias <= 0);

    int curricula[materias][alumnos];

    for (int i = 0;i < materias; i++) {
        printf("Ingrese las notas de la materia %d:\n", i + 1);
        for (int j = 0;j < alumnos; j++) {
            printf("Ingrese la nota del alumno %d:\n", j + 1);
            printf("> ");
            scanf("%d", &curricula[i][j]);
        }
    }
    printf("Todas las notas ingresadas.\n");

    printf("El promedio de cada materia es:\n");
    for (int i = 0;i < materias; i++) {
        promedio = 0;
        for (int j = 0;j < alumnos; j++) {
            promedio += curricula[i][j];
        }
        promedio = promedio / alumnos;
        printf("La materia %d tiene un promedio de: %d\n", i + 1, promedio);
    }

    printf("El promedio de cada alumno es:\n");
    for (int i = 0;i < alumnos; i++) {
        promedio = 0;
        for (int j = 0;j < materias; j++) {
            promedio += curricula[j][i];
        }
        promedio = promedio / materias;
        printf("El alumno %d tiene un promedio de: %d\n", i + 1, promedio);
        if (promedio < 6){
            printf("y su condicion es LIBRE.\n");
        }
        else if (promedio >= 8) {
            printf("y su condicion es PROMOVIDO.\n");
        }
        else {
            printf("y su condicion es REGULAR.\n");
        }
    }

    return 0;
}
