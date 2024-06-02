/*Escribe una función en C que cuente el número de palabras en una cadena de texto. 
Una palabra se define como una secuencia de caracteres alfanuméricos delimitada por 
espacios, puntuación u otros caracteres no alfanuméricos*/

#include <stdio.h>

int contador_palabras(char frase[200]) {
    int contador = 1;
    for (int i = 0; frase[i] != '\0'; i++ ) {
        if (frase[i] == ' ') {
            contador++;
        }
    }
    return contador;
}

int main(void) {
    char frase[200];
    for (int i = 0; i < 200; i++) {
        frase[i] = '\0';
    }
    printf("Ingresar frase\n");
    fgets(frase, sizeof(frase), stdin);
    printf("La frase tiene %d palabras \n", contador_palabras(frase));
}
