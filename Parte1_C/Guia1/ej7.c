/*
    Imprimir archivo
    Lea un archivo de texto y muestre todas sus líneas por pantalla
    Usar el texto.txt que ya lo guardé en el repo
*/

#include <stdio.h>

int main() {
    // Nombre del archivo a leer
    char filename[100];

    printf("Ingrese el nombre del archivo: ");
    scanf("%s", filename);

    // Intentar abrir el archivo en modo lectura
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Buffer para almacenar cada línea
    char line[256];

    // Leer línea por línea hasta EOF
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    printf("\n");

    fclose(file);
    return 0;
}