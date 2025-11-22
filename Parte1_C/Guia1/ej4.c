/*
    Suma de 1 a N
    Lea un número N y calcule la suma de los números del 1 al N.
    Resolver con for y luego con while
*/

#include <stdio.h>

int sumFor(int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    return sum;
}

int main(){
    int n, sum;
    printf("Ingrese un número para calcular la suma desde 1 hasta ese número: \n");
    scanf("%d", &n);
    sum = sumFor(n);
    printf("La suma desde 1 hasta %d es: %d \n", n, sum);
}