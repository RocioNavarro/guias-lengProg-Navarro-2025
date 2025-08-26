// STRING SIZE
// Calcular la longitud de una string usando aritmetica de punteros
// No se debe usar el acceso de tipo a[i].

#include <stdio.h>

int main() {
    char str[] = "Hola mundo";
    char* ptr = str;  // apunto al inicio del string

    // recorro hasta encontrar el carácter final '\0'
    while (*ptr != '\0') {
        ptr++;  // avanzo al siguiente carácter
    }

    // En C, restar punteros devuelve la diferencia en número de elementos, no en bytes.
    // El tipo de resultado de ptr - str es ptrdiff_t (un entero con signo definido en <stddef.h>).
    size_t length = ptr - str; 

    printf("La longitud del string es: %zu\n", length);

    return 0;
}
