/*
    Factorial de un número
    Calcule el factorial de un número ingresado por teclado usando while. Ejemplo:

    Ingrese un número: 5
    Factorial = 120
*/

#include <stdio.h>

int factorial(int n){
    if(n==0 || n==1) return 1;
    while(n>1){
        return n * factorial(n-1);
        n--;
    }
} // f(3)=3*2*1

int main(){
    int n = 0;
    printf("Ingrese un nro para calcular su factorial: \n");
    scanf("%d", &n);
    int fac = factorial(n);
    printf("El factorial de %d es %d \n", n, fac);
    return 0;
}