#include <string.h>
#include <stdio.h>

int main() {
    char* p1 = "hola";
    char* p2 = "chau";

    char* frase = strcat(p1, p2);

    printf("Frase: %s", frase);
}
