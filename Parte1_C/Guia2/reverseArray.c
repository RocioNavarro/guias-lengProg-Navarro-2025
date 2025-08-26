// Invertir un array in place
// Se debe revertir el orden de un array. Se debe reordenar la lista sobre el mismo array.

#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]); // En C, restar punteros devuelve la diferencia en número de elementos, no en bytes.

    int* left = arr; // apunto al primer elemento
    int* right = arr + n - 1; // apunto al último elemento

    // intercambio los elementos de los extremos hasta encontrarnos
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++; // avanzo desde el principio
        right--; // retrocedo desde el final
    }

    // imprimo array invertido
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
