/*
    Serie de Fibonacci
    Imprima los primeros N números de la serie de Fibonacci.
*/

#include <stdio.h>

int fibonacci(int i){
    if(i==0)   return 0;
    if(i==1)    return 1;
    return fibonacci(i-1)+fibonacci(i-2);
}

int main(){

    int n = 0;

    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    printf("Los primeros %d números de la serie de fibonacci son: ", n);

    for(int i=0; i<n-1; i++){
        printf("%d, ", fibonacci(i));
    }

    printf("%d \n", fibonacci(n));


    return 0;
}