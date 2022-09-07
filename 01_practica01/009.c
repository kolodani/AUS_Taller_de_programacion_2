/*
    Practica 01
    Ejercicio 09 cadena de caracteres
*/

// Librerias
#include <stdio.h>
#include <stdlib.h>

typedef enum { MAYUSCULAS, MINUSCULAS } may_min;

// Prototipos
int strLargo(const char *origen); // cantidad de caracteres
int strVacio(const char *origen); // retorna 1 si tiene al menos un caracter, 0 en otro caso
void strCopia(char *destino, const char *origen); // copiador
char* reverse(char *string); // retorna una cadena que es string invertida
void strIzq(char *destino, const char *origen); // saca blancos Izq
void strDer(char *destino, const char *origen); // saca blancos Der
void strAmbos(char *destino, const char *origen); // saca blancos Izq y Der
void strMayMin(char *destino, const char *origen, may_min m); // convierte a mayusculas o minusculas

// Funcion principal
int main()
{
    char *text1 = " Sera Cierto ?? ";
    int largo = strLargo(text1) + 1;
    char *result = (char*)malloc(largo);
    char* reves;
    if (result == NULL)
    {
        return -1; // sino pudo reservar memoria para result
    }
    printf("La cadena: ");
    puts(text1);
    printf("Se encuentra %s\n", (strVacio(text1) ? "No vacia" : "Vacia"));
    printf("Largo: %d\n", strLargo(text1));
    strCopia(result, text1);
    printf("Copia: [%s]\n", result);
    strIzq(result, text1);
    printf("Sin blancos a la Izq: [%s]\n", result);
    strDer(result, text1);
    printf("Der: [%s]\n", result);
    strAmbos(result, text1);
    printf("Ambos: [%s], sin blancon al principio ni al final.\n", result);
    strMayMin(result, text1, MAYUSCULAS);
    printf("Mayusculas: [%s]\n", result);
    strMayMin(result, text1, MINUSCULAS);
    printf("Minusculas: [%s]\n", result);
    reves = reverse(text1);
    printf("La cadena: %s invertida queda: %s\n", text1, reves);
    
    return 0;
}

// Funciones
// strLargo retorna la cantidad de caracteres de una cadena
int strLargo(const char *origen)
{
    int i = 0;
    while (origen[i] != '\0') // recorro el arreglo hasta encontrar el caracter nulo
    {
        i++; // incremento el contador
    }
    return i; // retorno el contador que es el total de caracteres de la cadena
}

// strVacio retorna 1 si tiene al menos un caracter, 0 en caso de que este vacia la cadena
int strVacio(const char *origen)
{
    if (origen[0] == '\0') // si el primer caracter es nulo
    {
        return 0; // retorno 0 de lo contrario retorno 1
    }
    else
    {
        return 1;
    }
}

// strCopia copia una cadena en otra
void strCopia(char *destino, const char *origen)
{
    int i = 0;
    while (origen[i] != '\0') // recorro el arreglo hasta encontrar el caracter nulo
    {
        destino[i] = origen[i]; // copio el caracter
        i++; // incremento el contador
    }
    destino[i] = '\0'; // agrego el caracter nulo al final de la cadena
}

// reverse retorna una cadena que es string invertida
char* reverse(char *string)
{
    int i = 0;
    int j = strLargo(string) - 1;  // largo de la cadena - 1 para que no cuente el caracter nulo
    char *reversed = (char*)malloc(strLargo(string) + 1); // reservo memoria para la cadena invertida + 1 para el caracter nulo
    while (i < strLargo(string)) // recorro la cadena hasta el caracter nulo
    {
        reversed[i] = string[j]; // copio el caracter de la cadena original en la cadena invertida
        i++; // incremento el contador
        j--; // decremento el contador
    }
    reversed[i] = '\0'; // agrego el caracter nulo al final de la cadena
    return reversed; // retorno la cadena invertida
}

// strIzq saca los espacios en blancos a la izquierda
void strIzq(char *destino, const char *origen)
{
    int i = 0;
    int j = 0;
    while (origen[i] == ' ') // recorro la cadena hasta que no encuentre un espacio en blanco
    {
        i++; // incremento el contador
    }
    while (origen[i] != '\0') // recorro la cadena hasta el caracter nulo
    {
        destino[j] = origen[i]; // copio el caracter
        i++; // incremento el contador
        j++; // incremento el contador
    }
    destino[j] = '\0';  // agrego el caracter nulo al final de la cadena
}

// strDer saca los espacios en blancos a la derecha
void strDer(char *destino, const char *origen)
{
    int i = 0;
    int j = 0;
    while (origen[i] != '\0') // recorro la cadena hasta el caracter nulo
    {
        i++; // incremento el contador
    }
    i--; // decremento el contador para que no cuente el caracter nulo
    while (origen[i] == ' ') // recorro la cadena hasta que no encuentre un espacio en blanco
    {
        i--; // decremento el contador
    }
    while (j <= i) // recorro la cadena hasta el caracter nulo
    {
        destino[j] = origen[j]; // copio el caracter
        j++; // incremento el contador
    }
    destino[j] = '\0'; // agrego el caracter nulo al final de la cadena
}

// strAmbos saca los espacios en blancos a la izquierda y derecha
void strAmbos(char *destino, const char *origen)
{
    int i = 0;
    int j = 0;
    while (origen[i] == ' ') // recorro la cadena hasta que no encuentre un espacio en blanco
    {
        i++; // incremento el contador
    }
    while (origen[i] != '\0') // recorro la cadena hasta el caracter nulo
    {
        destino[j] = origen[i]; // copio el caracter
        i++; // incremento el contador
        j++; // incremento el contador
    }
    i--; // decremento el contador para que no cuente el caracter nulo
    while (destino[i] != ' ') // recorro la cadena hasta que no encuentre un espacio en blanco
    {
        i--; // decremento el contador
    }
    destino[i] = '\0'; // agrego el caracter nulo al final de la cadena
}

// strMayMin convierte a mayusculas o minusculas
void strMayMin(char *destino, const char *origen, may_min m)
{
    int i = 0;
    while (origen[i] != '\0') // recorro la cadena hasta el caracter nulo
    {
        if (m == MAYUSCULAS) // si m es MAYUSCULAS
        {
            if (origen[i] >= 'a' && origen[i] <= 'z') // si el caracter es una letra minuscula
            {
                destino[i] = origen[i] - 32; // convierto a mayuscula
            }
            else
            {
                destino[i] = origen[i]; // copio el caracter
            }
        }
        else // si m es MINUSCULAS
        {
            if (origen[i] >= 'A' && origen[i] <= 'Z') // si el caracter es una letra mayuscula
            {
                destino[i] = origen[i] + 32; // convierto a minuscula
            }
            else
            {
                destino[i] = origen[i]; // copio el caracter
            }
        }
        i++; // incremento el contador
    }
    destino[i] = '\0'; // agrego el caracter nulo al final de la cadena
}
