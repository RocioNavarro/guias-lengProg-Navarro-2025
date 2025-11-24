/*
    Contar saltos de línea, espacios y tabs
    Lea un archivo de texto y cuente:

    Cantidad de \n (líneas)
    Cantidad de espacios ' '
    Cantidad de tabs \t
*/
 
#include <stdio.h>

int main(){

    char fileName[100];

    printf("Ingrese el nombre del archivo: \n");
    scanf("%s", fileName);

    FILE* file = fopen(fileName, "r");

    if(file == NULL){
        printf("Error: el archivo no fue encontrado \n");
        return 1;
    }

    int ch;  // OBS: fgetc devuelve un int, porque puede devolver EOF que es -1 y no entra en un char
    int lineas, espacios, tabs, ultimoChar;
    lineas = espacios = tabs = 0, ultimoChar = 0;

    while( (ch = fgetc(file)) != EOF ){
        ultimoChar = ch;
        if(ch == '\n')
            lineas++;
        else if(ch == ' ')
            espacios++;
        else if(ch == '\t')
            tabs++;
    }

    if (ultimoChar != 0)
    {
        lineas++; // Porque c solo cuenta saltos de linea entonces si tengo 3 renglones tengo 2 saltos de linea, faltaria contar el ultimo renglon
    }
    

    printf("Cantidad de líneas: %d\n", lineas);
    printf("Cantidad de espacios: %d\n", espacios);
    printf("Cantidad de tabs: %d\n", tabs); // OBS: como arme el .txt en visual no aparecen tabs porque el maldito pone 4 espacios en vez de un tab, me dio fiaca armarlo en otro lado pero sino funcionaría esto

    fclose(file);

    return 0;
}