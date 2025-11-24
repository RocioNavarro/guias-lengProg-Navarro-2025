/*
    Compactar espacios
    Lea un archivo y reemplace cualquier secuencia de múltiples espacios por uno solo. Guardar el resultado en otro archivo
*/

#include <stdio.h>

int main(){

    // OBS: NO FUNCIONA, crea un nuevo archivo pero con espacios idem al original

    char fileName[100];

    printf("Ingrese el nombre del archivo: \n");
    scanf("%s", fileName);

    FILE* file = fopen(fileName, "r");

    if(file == NULL){
        printf("El archivo no fue encontrado \n");
        return 1;
    }

    int cantEspacios = 0;
    int ch;

    FILE* outFile = fopen("archivo_sin_espacios.txt", "w");

    while( (ch = fgetc(file)) != EOF ){
        if(ch == ' '){
            cantEspacios++;
        } else {
            if(cantEspacios > 0){
                fputc(' ', outFile); // Escribo un solo espacio
                cantEspacios = 0;
            }
            fputc(ch, outFile); // Escribo el caracter que no es espacio
        }
    }

    fclose(file);
    fclose(outFile);

    return 0;
}