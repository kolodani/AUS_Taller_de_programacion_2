#include <stdio.h>

int main()
{
    FILE *fp;

    char cadena[] = "Hola mundo!\n";

    fp = fopen("./HM.txt", "w+");

    if (fp == NULL)
    {
        printf("Error!\n");
    }
    else
    {
        fwrite(cadena, sizeof(char), sizeof(cadena), fp);
    }

    fclose(fp);

    return 0;
}
