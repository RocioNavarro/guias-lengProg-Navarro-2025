// IDEM ej concatenateStrings.c pero sin usar strcat --> USO strcpy(result + len1, str2);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Concatenar dos strings dinámicas sin usar strcat
char* concat_strings(const char* str1, const char* str2) {
    if (!str1) str1 = "";
    if (!str2) str2 = "";

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char* result = (char*) malloc(len1 + len2 + 1);
    if (!result) {
        perror("Error al reservar memoria");
        return NULL;
    }

    // Copiamos str1 al inicio
    strcpy(result, str1);

    // Copiamos str2 justo después de str1 usando el puntero desplazado
    strcpy(result + len1, str2);strcpy(result + len1, str2); // ACA ESTA LA DIFERENCIA CON EL OTRO EJ

    return result;
}

int main() {
    char* a = "Hola, ";
    char* b = "mundo!";

    char* c = concat_strings(a, b);
    if (c) {
        printf("Concatenado: %s\n", c);
        free(c);
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
