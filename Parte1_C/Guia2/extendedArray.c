// Ampliar un array con realloc
// Se debe demostrar cómo expandir un array de tamaño N a tamaño M (donde M > N) usando realloc, preservando la información original.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t N, M; // size_t es unsigned y se usa para representar tamaños y cantidades de elementos en memoria

    printf("Ingrese el tamaño inicial del array (N): ");
    if (scanf("%zu", &N) != 1 || N == 0) {
        fprintf(stderr, "Error: N debe ser un número positivo.\n");
        return 1;
    }

    printf("Ingrese el nuevo tamaño del array (M > N): ");
    if (scanf("%zu", &M) != 1 || M <= N) {
        fprintf(stderr, "Error: M debe ser mayor que N.\n");
        return 1;
    }

    // Reservo memoria inicial
    int *arr = malloc(N * sizeof(int));
    if (arr == NULL) {
        perror("malloc");
        return 1;
    }

    // Inicializo array original
    for (size_t i = 0; i < N; i++) {
        arr[i] = (int)(i + 1);
    }

    printf("Array original:\n");
    for (size_t i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Expando con realloc
    int *tmp = realloc(arr, M * sizeof(int));
    if (tmp == NULL) {
        perror("realloc");
        free(arr); // Liberar memoria original si falla
        return 1;
    }
    arr = tmp;

    // Inicializo las nuevas posiciones
    for (size_t i = N; i < M; i++) {
        arr[i] = 0; // valor por defecto
    }

    printf("Array ampliado:\n");
    for (size_t i = 0; i < M; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Libero memoria
    free(arr);
    return 0;
}
