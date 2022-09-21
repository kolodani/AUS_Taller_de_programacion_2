#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Estructura de polinomios
typedef struct {
    int n;
    double *coeficiente;
} Polinomio;

// Prototipo de funciones
Polinomio * crearPolinomio(int);
void setCoef(int, double, Polinomio *);
double getCoef(int, Polinomio *);
double especializar(double, Polinomio *);
Polinomio * sum(Polinomio *, Polinomio *);
Polinomio * mult(Polinomio *, Polinomio *);
Polinomio * deriv(Polinomio *);
void destruyePolinomio(Polinomio *);
double ceropol(Polinomio *, double, double, double);

// Funcion principal
int main()
{
    
    return 0;
}

// Funciones
// Funcion para crear y retornar un polinomio
Polinomio * crearPolinomio(int orden){
    Polinomio *polinomio = (Polinomio *) malloc(sizeof(Polinomio));
    polinomio->n = orden;
    polinomio->coeficiente = (double *) malloc(sizeof(double) * (orden + 1));
    return polinomio;
}

// Funcion para asignar un coeficiente a un polinomio
void setCoef(int n, double c, Polinomio *P){
    P->coeficiente[n] = c;
}

// Funcion para obtener el coeficiente de un polinomio
double getCoef(int n, Polinomio *P){
    return P->coeficiente[n];
}

// Funcion para evaluar un polinomio en un X dado
double especializar(double x, Polinomio *P){
    double resultado = 0;
    for(int i = 0; i <= P->n; i++){
        resultado += P->coeficiente[i] * pow(x, i);
    }
    return resultado;
}

// Funcion para sumar dos polinomios
Polinomio * sum(Polinomio *P1, Polinomio *P2){
    int orden = P1->n > P2->n ? P1->n : P2->n;
    Polinomio *resultado = crearPolinomio(orden);
    for(int i = 0; i <= orden; i++){
        resultado->coeficiente[i] = getCoef(i, P1) + getCoef(i, P2);
    }
    return resultado;
}

// Funcion para multiplicar dos polinomios
Polinomio * mult(Polinomio *P1, Polinomio *P2){
    int orden = P1->n + P2->n;
    Polinomio *resultado = crearPolinomio(orden);
    for(int i = 0; i <= P1->n; i++){
        for(int j = 0; j <= P2->n; j++){
            resultado->coeficiente[i + j] += P1->coeficiente[i] * P2->coeficiente[j];
        }
    }
    return resultado;
}

// Funcion para derivar un polinomio
Polinomio * deriv(Polinomio *P){
    Polinomio *resultado = crearPolinomio(P->n - 1);
    for(int i = 0; i < P->n; i++){
        resultado->coeficiente[i] = P->coeficiente[i + 1] * (i + 1);
    }
    return resultado;
}

// Funcion para destruir un polinomio
void destruyePolinomio(Polinomio *P){
    free(P->coeficiente);
    free(P);
}

// Funcion para encontrar cero de un polinomio dentro de un intervalo [a,b]
double ceropol(Polinomio *P, double a, double b, double epsilon){
    double c = (a + b) / 2;
    double fa = especializar(a, P);
    double fb = especializar(b, P);
    double fc = especializar(c, P);
    if(fabs(fc) < epsilon){
        return c;
    }
    if(fa * fc < 0){
        return ceropol(P, a, c, epsilon);
    }
    if(fb * fc < 0){
        return ceropol(P, c, b, epsilon);
    }
    return 0;
}