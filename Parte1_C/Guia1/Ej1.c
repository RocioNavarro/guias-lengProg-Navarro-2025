// CONVERSOR CELSIUS
// Programe un conversor de Celsius a Fahrenheit y escriba en pantalla la conversión desde 0 a 300 grados Celsius en N pasos.
// Sin funciones
// Sin números mágicos (#define)

#include <stdio.h>
#include <errno.h>

int main() {
    int celsius_min = 0;      // límite inferior
    int celsius_max = 300;    // límite superior
    int N;                    // cantidad de pasos
    int step;                 // incremento entre pasos
    int celsius;
    float fahrenheit;

    printf("Ingrese la cantidad de pasos N: ");
    if (scanf("%d", &N) != 1) {
        // Uso perror para que se muestre el error del sistema y mi mensaje
        perror("Error al leer el valor de N"); 
        return 1;
    }

    if (N <= 0) {
        errno = EINVAL; // argumento inválido
        perror("El número de pasos debe ser mayor que 0");
        return 1;
    }

    step = (celsius_max - celsius_min) / N;

    if (step == 0) {
        errno = ERANGE; // fuera de rango (demasiados pasos)
        perror("El número de pasos es demasiado grande para el rango dado");
        return 1;
    }

    printf("\nTabla de conversión Celsius → Fahrenheit\n");
    printf("----------------------------------------\n");
    printf("Celsius\tFahrenheit\n");

    celsius = celsius_min;
    while (celsius <= celsius_max) {
        fahrenheit = (9.0 / 5.0) * celsius + 32;
        printf("%7d\t%10.2f\n", celsius, fahrenheit);
        celsius = celsius + step;
    }

    return 0;
}
