#include <stdio.h>

void imprimir_numero(int numero) {
    printf("el numero es: %d\n", numero);
}

int main(void) {
    void (*ptr_func)(int) = &imprimir_numero;
    ptr_func(25);
}
