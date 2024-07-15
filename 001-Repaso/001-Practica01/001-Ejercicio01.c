#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;

    printf("Ingrese el tamaño de la matriz identidad:\n");
    printf("> ");
    scanf("%d", &numero);

    int matriz[numero][numero];

    for (int i = 0; i < numero; i++) {
        for (int j = 0; j < numero; j++) {
            if(i == j){
                matriz[i][j] = 1;
            }
            else {
                matriz[i][j] = 0;
            }
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
