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

/* 
static void bad1(void) {
    char buf[8];
    const char *s = "AAAAAAAAAAAAAAAA"; // ERROR: overflow porque reserve 8 lugares pero intento poner mas
    strcpy(buf, s);
    puts(buf);
} 
*/
static void good1(void) {
    char buf[8];
    const char *s = "AAAAAAA";
    strcpy(buf, s);
    puts(buf);
}

/*
static void bad2(void) {
    char *p = malloc(8);
    if (!p) { perror("malloc"); return; }

    for (int i = 0; i <= 8; ++i)  // ERROR: i tiene que ser menor a 8 porque sino estoy recorriendo 9 lugares
        p[i] = 'A';

    free(p);
}
*/
static void good2(void) {
    char *p = malloc(8);
    if (!p) { perror("malloc"); return; }

    for (int i = 0; i < 8; ++i)
        p[i] = 'A';

    free(p);
}

/*
static void bad3(void) {
    char s[4] = "abc"; 
    s[3] = 'x'; // overwrites '\0'
    puts(s);    // UB   ERROR: no termina en '\0'
}
*/
static void good3(void) {
    char s[5] = "abc"; 
    s[3] = 'x'; 
    puts(s);
}

/*
static void bad4(void) {
    size_t n = SIZE_MAX / 2 + 1;
    int *a = malloc(n * 2 * sizeof *a); // ERROR: n*2 = SIZE_MAX+2 y eso multiplicado por el tamaño de un int va a ser mas grande que el max soportado por malloc
    // esto hace que haya overflow y el valor "se enrolle" empezando desde cero y tomando un valor muy chiquito cuando creiamos que le habiamos asignado uno muy grande
    if (!a) { puts("malloc failed"); return; }
    a[0] = 1;
    free(a);
}
*/

// todo
static void good4(void) {
    size_t n = SIZE_MAX / 2;
    int *a = malloc(n * 2 * sizeof *a); // Ahora le estaria asignando el maximo que puede tener
    if (!a) { puts("malloc failed"); return; }
    a[0] = 1;
    free(a);
}

static void bad5(void) {
    int len = -5;
    char *p = (char*)malloc(len);
    if (!p) { perror("malloc"); return; }
    free(p);
}

static void bad6(void) {
    int *p = (int*)malloc(sizeof *p);
    if (!p) { perror("malloc"); return; }
    *p = 7;
    free(p);
    *p = 42; // UAF write
}

static void bad7(void) {
    int *p = (int*)malloc(4);
    if (!p) { perror("malloc"); return; }
    free(p);
    free(p); // double free
}

static void bad8(void) {
    char *p = (char*)malloc(100);
    if (!p) { perror("malloc"); return; }
    // Lost reference without freeing -> leak
    p = (char*)malloc(200);
    if (!p) { perror("malloc"); return; }
    free(p);
}

static void bad9(void) {
    char *p = (char*)malloc(10);
    if (!p) { perror("malloc"); return; }
    char *q = p + 2;
    free(q); // not the start of allocation
}

static int* returns_local_bad(void) {
    int x = 7;
    return &x;
}

static void bad10(void) {
    int *p = returns_local_bad();
    // Using p is UB
    printf("dangling value: %d\n", *p);
}

static void bad11(void) {
    int x;
    if (x == 123) puts("equal");
}

static void bad12(void) {
    size_t huge = (size_t)1 << 62;
    char *p = (char*)malloc(huge);
    p[0] = 'x'; // maybe NULL deref
    free(p);
}

static void bad13(void) {
    char *p = (char*)malloc(10);
    if (!p) { perror("malloc"); return; }
    p = (char*)realloc(p, SIZE_MAX/4);
    if (!p) {
        puts("realloc failed");
        return;
    }
    free(p);
}

static void bad14(void) {
    char buf[16] = "abcdefgh";
    memcpy(buf+2, buf, 8); // overlap -> UB
    puts(buf);
}

static void bad15(void) {
    char buf[16];
    const char *a = "0123456789";
    const char *b = "ABCDEFGHIJ";
    // can overflow
    sprintf(buf, "%s %s", a, b);
    puts(buf);
}

static void rec(int n){ if(n) rec(n-1); }

static void bad16(void) {
    rec(1000000000);
}

static int static_x;
static void bad18(void) {
    int local;
    (void)static_x;
    free(&local);
    free(&static_x);
}
static void bad20(void) {
    char *p = (char*)malloc(10);
    if (!p) { perror("malloc"); return; }
    char *alias = p;
    free(p);
    alias[0] = 'x';
}


int main(int argc, char **argv) {
    //bad1();
    // bad2();
     bad3();
    // bad4();
    // bad5();
    // bad6();
    // bad7();
    // bad8();
    // bad9();
    // bad10();
    // bad11();
    // bad12();
    // bad13();
    // bad14();
    // bad15();
    // bad16();
    // bad18();
    // bad20();
    return 0;
}