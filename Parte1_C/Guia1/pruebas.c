#include <stdio.h>
#include <string.h>

int main(void) {
	int a, b, *p, **q;
	a = 10; b = 15;
	p = &a; // p guarda la dirección de a
	printf("a = %d b = %d\n", a, b); // a=10 b=15

	*p = 11; // a=11
	q = &p; // q tiene la direc de p y p tiene la direc de a
	p = &b; // p = direc b
	**q = 20; // q tiene la direc de p y p tiene la de b, b=20
	printf("a = %d b = %d\n", a, b); // a=11 b=20

	*q = p + 1; // *q (es p) se actualiza a p+1 (uso ilustrativo; puede provocar comportamiento indefinido)
	**q = 40;
	printf("a = %d b = %d\n", a, b); // comportamiento indefinido may occur in real programs

    struct Person {
    char *name;
    int age;
    float height;
    };
    
    struct Person john;
    char myName[50] = "John Doe";
    john.name = myName;  // john.name == &myName[0]
    john.age = 30;                  
    john.height = 170; 
    printf("Name: %s, Age: %d, Height: %.2f cm\n", john.name, john.age, john.height);

    struct Person Tais = {"Taisita", 25, 160.5};
    printf("Name: %s, Age: %d, Height: %.2f cm\n", Tais.name, Tais.age, Tais.height);


    struct Person2 {
    char name[50];
    int age;
    float height;
    };

    struct Person2 pepe;
    strcpy(pepe.name, "Pepe");  
    pepe.age = 30;                  
    pepe.height = 170;              

    printf("Name: %s, Age: %d, Height: %.2f cm\n", pepe.name, pepe.age, pepe.height);

    // Un array de chars con 5 lugares puede almacenar 4 porque el ult es un '\0'
    char prueba[5];
    strcpy(prueba, "Hola");  // Correcto: "Hola" tiene 4 caracteres + '\0'
    printf("prueba: %s\n", prueba);
    strcpy(prueba, "Adio"); // Incorrecto: "Adios" tiene 5 caracteres + '\0', puede causar desbordamiento
    printf("prueba: %s\n", prueba);
    printf("sadsd %d\n", prueba[4]);

    // Un array de nros con 5 lugares puede almacenar 5 nros
    int z[5] = {10, 20, 30, 40, 50};
    printf("z: %d %d %d %d %d\n", z[0], z[1], z[2], z[3], z[4]);
    
    return 0;
}