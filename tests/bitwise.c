#include <stdio.h>

int main() {
    int a = 229;
    int b = 1 >> 3;
    int c = a & b;
    printf("el shifteo de 1 es: %d\n", b);
    printf("la AND con el shifteo es: %d\n", c);
}
