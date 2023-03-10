#include "planes.h"

int main()
{
    int edad, meses_socio, total;
    char plan[PLAN];
    char linea[GRANDE];
    FILE *personas = fopen("personas.txt", "r");
    FILE *tabla_planes = fopen("plan.txt", "r");
    FILE *personas_actualizado = fopen("personas-plan.txt", "w");

    while (fscanf(personas, "%s", linea) != EOF)
    {
        parseo(linea);
        sscanf(linea, "%*s %*s %d %d %s", &edad, &meses_socio, plan);
        parseoInvertido(linea);
        total = totales(tabla_planes, plan, edad, meses_socio);
        fprintf(personas_actualizado, "%s-%d\n", linea, total);
    }

    fclose(personas);
    fclose(tabla_planes);
    fclose(personas_actualizado);

    return 0;
}

void parseo(char *linea)
{
    int i = 0;
    while (linea[i] != '\0')
    {
        if (linea[i] == '-')
        {
            linea[i] = ' ';
        }
        i++;
    }
}
void parseoInvertido(char *linea)
{
    int i = 0;
    while (linea[i] != '\0')
    {
        if (linea[i] == ' ')
        {
            linea[i] = '-';
        }
        i++;
    }
}

int totales(FILE *fp, char *plan, int edad, int meses)
{
    float total = 0, discount = 0;
    char linea_plan[CHICO];
    char plan_file[PLAN];
    rewind(fp);

    do
    {
        fscanf(fp, "%s", linea_plan);
        parseo(linea_plan);
        sscanf(linea_plan, "%s %f %f", plan_file, &total, &discount);
    } while (!feof(fp) && strcmp(plan_file, plan));

    if (meses >= 24)
        total = total - total * (discount * 1.0 / 100.0);

    if (edad < 12 || edad > 65)
        total = total - total * (5.0 / 100.0);

    return total;
}