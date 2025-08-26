#include <stdio.h>

int main() {
    int a, b, *p, **q;
    a = 10;
    b = 15;
    p = &a;
    printf("a=%d b=%d\n", a, b);
    // a=10, b=15

    *p = 11;
    q = &p;
    p = &b;
    **q = 20;
    printf("a=%d b=%d\n", a, b);
    // a=11 b=20

    *q = p + 1; // ahora apunta hacia a (pero cuidado, esto puede causar comportamiento indefinido)
    **q = 40;
    printf("a=%d b=%d\n", a, b);

    return 0;
}
