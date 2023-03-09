/* tda.c */

#include "tda.h"

int main(){
    legisladores *chicos_buenos, *chicos_malos;
    chicos_buenos = NULL;
    chicos_malos = NULL;
    int cantidad = 0;
    char voto = ' ';
    char delegado[LONG_MAX_NOMBRE];
    char fin_del_programa = 'S';
    printf("Bienvenidos al programa de votaciones de la SPIA\n");
    while (fin_del_programa != 'N')
    {
        cantidad++;
        voto = ' ';
        printf("Esta es la votacion numero %d\n", cantidad);
        while(voto != 'E'){
            printf("agregue 'F' si el voto es favorable, 'D' si desfavorable y 'E' para terminar la votacion\n");
            scanf(" %c", &voto);
            if(voto == 'F' || voto == 'D'){
                printf("Ingrese el nombre del delegado que voto\n");
                scanf(" %s", delegado);
                votacion(&chicos_buenos, &chicos_malos, delegado, voto);
            }
        }
        printf("Los delegados que votaron favorablemente son:\n");
        mostrar(&chicos_buenos);
        printf("\n");
        printf("Los delegados que votaron desfavorablemente son:\n");
        mostrar(&chicos_malos);
        printf("\n");
        printf("Desea continuar con el programa? Ingrese 'S' para continuar y 'N' para terminar\n");
        scanf(" %c", &fin_del_programa);
    }
    return 0;
}

void inserta (char nombre[], legisladores** lista){
    if(*lista == NULL){
        *lista = (legisladores*)malloc(sizeof(legisladores));
        strcpy((*lista)->nombre, nombre);
        (*lista)->siguiente = NULL;
    }
    else{
        legisladores *aux = *lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = (legisladores*)malloc(sizeof(legisladores));
        strcpy(aux->siguiente->nombre, nombre);
        aux->siguiente->siguiente = NULL;
    }
}

void suprimir (char nombre[], legisladores** lista){
    if(lista == NULL){
        printf("La lista esta vacia");
    }
    else{
        legisladores *aux = *lista;
        if(strcmp(aux->nombre, nombre) == 0){
            *lista = (*lista)->siguiente;
            free(aux);
        }
        else{
            while(aux->siguiente != NULL){
                if(strcmp(aux->siguiente->nombre, nombre) == 0){
                    legisladores *aux2 = aux->siguiente;
                    aux->siguiente = aux->siguiente->siguiente;
                    free(aux2);
                }
                else{
                    aux = aux->siguiente;
                }
            }
        }
    }
}

int miembro (char nombre[], legisladores** lista){
    if(lista == NULL){
        return 0;
    }
    else{
        legisladores *aux = *lista;
        while(aux != NULL){
            if(strcmp(aux->nombre, nombre) == 0){
                return 1;
            }
            else{
                aux = aux->siguiente;
            }
        }
        return 0;
    }
}

void mostrar (legisladores** lista){
    if(lista == NULL){
        printf("La lista esta vacia");
    }
    else{
        legisladores *aux = *lista;
        while(aux != NULL){
            printf("%s\n", aux->nombre);
            aux = aux->siguiente;
        }
    }
}

void votacion (legisladores** chicos_buenos, legisladores** chicos_malos, char nombre[], char voto){
    if((voto == 'F') && (miembro(nombre, chicos_buenos) == 0)){
        inserta(nombre, chicos_buenos);
    }
    if((voto == 'F') && (miembro(nombre, chicos_malos) == 1)){
        suprimir(nombre, chicos_malos);
    }
    if((voto == 'D') && (miembro(nombre, chicos_malos) == 0)){
        inserta(nombre, chicos_malos);
    }
    if((voto == 'D') && (miembro(nombre, chicos_buenos) == 1)){
        suprimir(nombre, chicos_buenos);
    }
}