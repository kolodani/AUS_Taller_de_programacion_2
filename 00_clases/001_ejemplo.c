#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    
    // imprime la direccion de memoria
    printf("%ld\n", sizeof(arr));
    printf("%p\n", arr);
    printf("%p\n", &arr);
    printf("%p\n", &arr[0]);
    
    int *pi = arr;
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("*(pi + %d): %d\n", i, *(pi++));
    }
    
    printf("%p %p\n", arr, pi);
    /*
    int *pi;
    // pi = NULL;
    pi = arr + 1; // aritmetica de punteros
    printf("arr + 1: %p\n", pi);
    printf("valor de arr + 1: %d\n", *pi);
    
    pi = arr - 1; // aritmetica de punteros
    printf("arr - 1: %p\n", pi);
    printf("valor de arr - 1: %d\n", *pi);
    
    // arr = arr + 1; // error
    
    size_t cant = sizeof(int);
    printf("cantidad de bytes de un int: %ld\n", cant);
    */
    return 0;
}
