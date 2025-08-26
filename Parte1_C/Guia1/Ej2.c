#include <stdio.h>

int main() {
    int celsius_min = 0;
    int celsius_max = 300;
    int N;
    int step;
    int celsius;
    float fahrenheit;

    // Pedimos la cantidad de pasos
    printf("Ingrese la cantidad de pasos N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Cantidad de pasos inválida.\n");
        return 1;
    }

    // Calculamos el salto entre cada paso
    step = (celsius_max - celsius_min) / N;
    if (step == 0) step = 1; // por si N es muy grande

    // Encabezado de la tabla
    printf("\nC   \tF\n");
    printf("-------------------\n");

    // Generamos la tabla
    for (celsius = celsius_min; celsius <= celsius_max; celsius += step) {
        fahrenheit = (9.0 / 5.0) * celsius + 32;
        printf("%-6d\t%.0f\n", celsius, fahrenheit);
    }

    return 0;
}
