/*
    Practica 01
    Ejercicio 05 descubrimiento de punteros
*/

#include <stdio.h>

int main()
{
    int i = 8, *pi = &i;
    long long l = 8, *pl = &l;
    float f = 102.8f, *pf = &f;
    double d = 678.44, *pd = &d;
    int vec[100];
    vec[0] = 44;

    // Imprimir los valores de las variables y punteros en la misma se ve el tamaño de la variable, direccion de memoria y valor
    printf("variable int, tam.bytes: %d \tdir.&i: %p \tvalor: %d\n\n", sizeof(i), &i, i);
    printf("puntero int, tam.bytes: %d \tdir.&pi: %p \tvalor: %p\n\n", sizeof(pi), &pi, pi);
    printf("variable long long, tam.bytes: %d \tdir.&l: %p \tvalor: %ld\n\n", sizeof(l), &l, l);
    printf("puntero long long, tam.bytes: %d \tdir.&pl: %p \tvalor: %p\n\n", sizeof(pl), &pl, pl);
    printf("variable float, tam.bytes: %d \tdir.&f: %p \tvalor: %f\n\n", sizeof(f), &f, f);
    printf("puntero float, tam.bytes: %d \tdir.&pf: %p \tvalor: %p\n\n", sizeof(pf), &pf, pf);
    printf("variable double, tam.bytes: %d \tdir.&d: %p \tvalor: %f\n\n", sizeof(d), &d, d);
    printf("puntero double, tam.bytes: %d \tdir.&pd: %p \tvalor: %p\n\n", sizeof(pd), &pd, pd);
    printf("variable vector, tam.bytes: %d \tdir.&vec: %p \tvalor: %d\n\n", sizeof(vec), &vec, vec[0]);
    printf("puntero vector, tam.bytes: %d \tdir.&vec: %p \tvalor: %p\n\n", sizeof(vec), &vec, vec);

    return 0;
}
