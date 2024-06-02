#include <stdio.h>
#include <math.h>

int cuadrado(int x);
int area(int radio);
int scan(void);
void scan();
void print_enunciado(void);

int main (void) {
    int valor1;
    valor1 = cuadrado(2);
    int area;
    area = area(2);
    valor = print(2);
    print_enunciado();
}

int cuadrado(int x) {
    return x*x;
}

int area(int radio) {
    return 3.1416*radio*radio;
}

int scan(void) {
    int valor;
    scanf("%d", &valor);
    return valor;
}

void print(int valor) {
    printf("%d\n", valor);
}

void print_enunciado(void) {
    printf("Este es el enunciado\n");
}


