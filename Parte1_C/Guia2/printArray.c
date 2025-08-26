// PRINT ARRAY
// Imprimir un array usando aritmetica de punteros
// No se debe usar el acceso de tipo a[i].

#include <stdio.h>
#include <stddef.h>

void print_array(int* arr, size_t n) {
    if (arr == NULL || n == 0) {
        printf("Array vacío\n");
        return;
    }

    int* ptr = arr;       // apuntamos al inicio del array
    int* end = arr + n;   // apuntamos a la posición después del último elemento

    while (ptr < end) {
        printf("%d ", *ptr);  // desreferenciamos para obtener el valor
        ptr++;                 // avanzamos al siguiente elemento
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, n);    // llamamos a la función

    int empty_arr[0];       // ejemplo de array vacío
    print_array(empty_arr, 0);

    return 0;
}

