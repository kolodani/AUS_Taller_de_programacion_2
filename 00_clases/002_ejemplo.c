#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *pc = (char*) malloc(20 * sizeof(char));
    
    if (pc == NULL)
    {
        printf("No hay memoria disponible");
    }
    
    pc[0] = 'A'; // notacion de arreglo
    *(pc + 0) = 'A'; // notacion de puntero
    
    pc[1] = 'B';
    *(pc + 1) = 'B';
    
    free(pc);
    
    return 0;
}
