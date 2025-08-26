// Concatenar strings
// Concatenar dos strings dinámicas en una tercera usando malloc. Tener en cuenta edge cases, como un NULL o una string vacia.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función que concatena dos strings dinámicas usando strcpy y strcat
char* concat_strings(const char* str1, const char* str2) {
    // Considerar NULL como string vacía
    if (!str1) str1 = "";
    if (!str2) str2 = "";

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    // Reservar memoria para la nueva string + '\0'
    char* result = (char*) malloc(len1 + len2 + 1);
    if (!result) {
        perror("Error al reservar memoria para concatenar");
        return NULL;
    }

    // Copiar str1 al resultado
    strcpy(result, str1);

    // Concatenar str2 al resultado
    strcat(result, str2);

    return result;
}

int main() {
    char* a = "Hola, ";
    char* b = "mundo!";

    char* c = concat_strings(a, b);
    if (c) {
        printf("Concatenado: %s\n", c);
        free(c); // liberar memoria
    }

    // Ejemplo con NULL
    char* d = concat_strings(NULL, "Solo esto");
    printf("%s\n", d);
    free(d);

    // Ejemplo con strings vacías
    char* e = concat_strings("", "");
    printf("Vacio: '%s'\n", e);
    free(e);

    return 0;
}
