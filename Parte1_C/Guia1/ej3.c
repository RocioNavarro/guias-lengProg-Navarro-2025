// Par o impar
// Lea un número desde teclado e imprima si es par o impar.

#include <stdio.h>

void isEven(int num){
    if(num%2 == 0)
        printf("El número ingresado es par \n");
    else
        printf("El número ingresado es impar\n");
}

int main() {
    int num = 0;
    printf("Ingrese un número entero: \n");
    scanf("%d", &num);
    isEven(num);
    return 0;
}
