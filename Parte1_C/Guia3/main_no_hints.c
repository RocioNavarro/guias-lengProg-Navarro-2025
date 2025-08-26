#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Utility helpers
static void print_bytes(const char *label, const unsigned char *buf, size_t n) {
    printf("%s", label);
    for (size_t i = 0; i < n; ++i) printf("%02X ", buf[i]);
    putchar('\n');
}


static void bad1(void) {
    char buf[8];
    const char *s = "AAAAAAAAAAAAAAAA"; // ERROR: overflow porque reserve 8 lugares pero intento poner mas
    strcpy(buf, s);
    puts(buf);
} 

static void good1(void) {
    char buf[8];
    const char *s = "AAAAAAA";
    strcpy(buf, s);
    puts(buf);
}


static void bad2(void) {
    char *p = malloc(8);
    if (!p) { perror("malloc"); return; }

    for (int i = 0; i <= 8; ++i)  // ERROR: i tiene que ser menor a 8 porque sino estoy recorriendo 9 lugares
        p[i] = 'A';

    free(p);
}

static void good2(void) {
    char *p = malloc(8);
    if (!p) { perror("malloc"); return; }

    for (int i = 0; i < 8; ++i)
        p[i] = 'A';

    free(p);
}


static void bad3(void) {
    char s[4] = "abc"; 
    s[3] = 'x'; // overwrites '\0'
    puts(s);    // UB (Undefined Behavior)  ERROR: no termina en '\0'
}

static void good3(void) {
    char s[5] = "abc"; 
    s[3] = 'x'; 
    puts(s);
}


static void bad4(void) {
    size_t n = SIZE_MAX / 2 + 1;
    int *a = malloc(n * 2 * sizeof *a); // ERROR: n*2 = SIZE_MAX+2 y eso multiplicado por el tamaño de un int va a ser mas grande que el max soportado por malloc
    // esto hace que haya overflow y el valor "se enrolle" empezando desde cero y tomando un valor muy chiquito cuando creiamos que le habiamos asignado uno muy grande
    if (!a) { puts("malloc failed"); return; }
    a[0] = 1;
    free(a);
}

static void good4(void) {
    size_t n = SIZE_MAX / 2;
    int *a = malloc(n * 2 * sizeof *a); // Ahora le estaria asignando el maximo que puede tener
    if (!a) { puts("malloc failed"); return; }
    a[0] = 1;
    free(a);
}

// ERROR: malloc: Cannot allocate memory
static void bad5(void) {
    int len = -5;  // ERROR: len tiene que ser positivo, -5 se interpreta como un nro gigante
    char *p = (char*)malloc(len);
    if (!p) { perror("malloc"); return; }
    free(p);
}

static void good5(void) {
    int len = 5;
    char *p = (char*)malloc(len);
    if (!p) { perror("malloc"); return; }
    free(p);
}


static void bad6(void) {
    int *p = (int*)malloc(sizeof *p);
    if (!p) { perror("malloc"); return; }
    *p = 7;
    free(p); // devuelve memoria a heap
    *p = 42; // UAF write, ERROR: quiere escribir en un lugar de memoria liberado
}

static void good6(void) {
    int *p = (int*)malloc(sizeof *p);
    if (!p) { perror("malloc"); return; }
    *p = 7;
    free(p); 
    // no vuelvo a escribir en *p
}


static void bad7(void) {
    int *p = (int*)malloc(4);
    if (!p) { perror("malloc"); return; }
    free(p);  // devuelve memoria al heap
    free(p); // ERROR: free(): double free detected in tcache 2, Aborted (core dumped)
}

static void good7(void) {
    int *p = (int*)malloc(4);
    if (!p) { perror("malloc"); return; }
    free(p);  
    // no hago free(p) de nuevo
}


static void bad8(void) {
    char *p = (char*)malloc(100); // hace que p apunte a un bloque de memoria con 100 lugares
    if (!p) { perror("malloc"); return; }
    // Lost reference without freeing -> leak
    p = (char*)malloc(200); // hace que p apunte a otro bloque de memoria con 200 lugares, perdiendo referencia al anterior y sin liberar el otro 
    if (!p) { perror("malloc"); return; }
    free(p); // se libera el bloque de memoria 200 pero no el de 100
}

static void good8(void){
    char *p = (char*)malloc(100);
    if (!p) { perror("malloc"); return; }
    free(p); // libero los 100 bytes
    p = (char*)malloc(200); // ahora p apunta a 200 bytes nuevos
    if (!p) { perror("malloc"); return; }
    free(p); // libero los 200 bytes
}


static void bad9(void) {
    char *p = (char*)malloc(10);
    if (!p) { perror("malloc"); return; }
    char *q = p + 2;  
    free(q); // ERROR: not the start of allocation, free(): invalid pointer, Aborted (core dumped)
    // como q no apunta al inicio del espacio de memoria, no puede liberarse
}

static void good9(void){
    char *p = (char*)malloc(10);
    if (!p) { perror("malloc"); return; }
    
    char *q = p + 2;  // se puede usar q para acceder a memoria leyendo o escribiendo
    
    free(p); // libero apuntando al inicio del bloque
}


static int* returns_local_bad(void) {
    int x = 7;      // variable local en la pila
    return &x;      // devuelve la dirección de variable local pero esta se libera cuando se sale de la funcion
}

static void bad10(void) {
    int *p = returns_local_bad(); // p seria un puntero a un espacio ya liberado 
    // Using p is UB (Undefined Behavior), ERROR: Segmentation fault (core dumped)
    printf("dangling value: %d\n", *p);
}


static void bad11(void) {
    int x;
    if (x == 123) puts("equal"); // se esta queriendo verificar un valor pero no fue inicializada, tiene basura
}

static void good11(void) {
    int x = 0;
    if (x == 123) puts("equal");    
}


static void bad12(void) {
    size_t huge = (size_t)1 << 62; // << 62 (shift a la izquierda) representa 2^(62), nro demasiado grande
    char *p = (char*)malloc(huge); // malloc puede fallar
    p[0] = 'x'; // maybe NULL deref
    free(p);
}

static void good12(void) {
    size_t huge = (size_t)1 << 20; // ejemplo razonable: 1 MB
    char *p = (char*)malloc(huge);
    if (!p) { perror("malloc"); return; }

    p[0] = 'x';  // seguro: p no es NULL
    free(p);
}


static void bad13(void) {
    char *p = (char*)malloc(10);
    if (!p) { perror("malloc"); return; }
    p = (char*)realloc(p, SIZE_MAX/4); // ERROR: intenta ampliar a un tamaño enorme
    if (!p) {
        puts("realloc failed");
        return;
    }
    free(p);
}

static void good13(void) {
    char *p = malloc(10);
    if (!p) { perror("malloc"); return; }

    size_t new_size = 1024; // un tamaño razonable
    char *tmp = realloc(p, new_size); // usando un temp evito perder la referencia a la memoria original si falla el realloc
    if (!tmp) {
        puts("realloc failed");
        free(p);  // liberar bloque original
        return;
    }
    p = tmp; // ocurre si no fallo realloc

    free(p);
}


static void bad14(void) {
    char buf[16] = "abcdefgh";
    // void *memcpy(void *dest, const void *src, size_t n);
    // memcpy solo es seguro si source y destination no se tocan
    memcpy(buf+2, buf, 8); // overlap -> UB (Undefined Behavior), Se solapan porque quiere copiar y pegar en el mismo bloque de memoria
    puts(buf);
}

static void good14(void) {
    char buf[16] = "abcdefgh";
    memmove(buf+2, buf, 8); // memmove es seguro aunque haya solapamiento
    // copia del final hacia el principio, evitando pisar datos que todavia no se copiaron
    puts(buf);
}


static void bad15(void) {
    char buf[16];
    const char *a = "0123456789"; // 10 bytes
    const char *b = "ABCDEFGHIJ"; // 10 bytes
    // can overflow
    sprintf(buf, "%s %s", a, b); // lo que se quiere imprimir es mas grande que el tamaño de buf porque encima esta el espacio y el \0 al final
    puts(buf);
}

static void good15(void) {
    char buf[16];
    const char *a = "0123456789";
    const char *b = "ABCDEFGHIJ";

    // escribe como máximo sizeof(buf) - 1 bytes + '\0'
    snprintf(buf, sizeof(buf), "%s %s", a, b);
    puts(buf);
}

static void good15_v2(void) {
    char buf[22];
    const char *a = "0123456789";
    const char *b = "ABCDEFGHIJ";

    sprintf(buf, "%s %s", a, b); 
    puts(buf);
}


static void rec(int n){ if(n) rec(n-1); } // cada llamada queda en stack y llamandose tantas veces se llena causando overflow

static void bad16(void) {
    rec(1000000000);
}

static void good16(int n) {
    while(n) n--; // no usa stack, n es variable local, itera sin agregar nada a la pila
}

static int static_x;
static void bad18(void) {
    int local;
    (void)static_x;
    free(&local); // ERROR: pointer being freed was not allocated, Aborted (core dumped)
    free(&static_x); // free se usa con memoria asignada dinámicamente (malloc, calloc o realloc)
}


static void good18(void) {
    int *p = malloc(sizeof(int));  // asigno memoria dinámica
    if (!p) { perror("malloc"); return; }

    *p = 42;// uso la memoria
    printf("Valor dinámico: %d\n", *p);

    free(p); // libero memoria
    p = NULL; // opcional: evitar dangling pointer

    static_x = 7; // uso de variable estática, no hago free
    printf("Valor estático: %d\n", static_x);
}

static void bad20(void) {
    char *p = (char*)malloc(10);
    if (!p) { perror("malloc"); return; }
    char *alias = p;
    free(p);
    alias[0] = 'x'; // UAF (use after free) write, ERROR: quiere escribir en un lugar de memoria liberado
}

static void good20(void) {
    char *p = malloc(10);
    if (!p) { perror("malloc"); return; }

    // usar p o alias antes de free
    p[0] = 'x';

    free(p);
    p = NULL;  // opcional: ayuda a detectar UAF
}

static void good20_v2(void) {
    char *p = malloc(10);
    if (!p) { perror("malloc"); return; }

    char *alias = malloc(10); // nueva memoria
    if (!alias) { free(p); return; }

    memcpy(alias, p, 10);  // copio contenido de p en alias
    free(p); // libero p

    alias[0] = 'x';  // uso alias, es seguro porque tiene su propia memoria
    free(alias);
}



int main(int argc, char **argv) {
    //bad1();
    // bad2();
    // bad3();
    // bad4();
    // bad5();
    // bad6();
    // bad7();
    // bad8();
    // bad9();
    // returns_local_bad();
    // bad10();
    // bad11();
    // bad12();
    // bad13();
    // bad14();
    // bad15();
    // bad16();
    // bad18();
    // bad20();

    good15_v2();
    return 0;
}