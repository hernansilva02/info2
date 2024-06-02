#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_string(char* frase) {
    char* ptr = frase;
    char palabra1[50];
    char* palabra2 = NULL;
    char* tmp = NULL;
    char* swaped;
    long buf;

    int j = 0;

    int letras = strlen(frase);

    if (frase[letras - 1] == '\n') {
        frase[letras - 1] = '\0';  
    }

    for (int i = 0; i < 50; i++) {
        palabra1[i] = '\0'; 
    }

    for (int i = 0; frase[i] != '\0'; i++) {
        ptr++; 
        if (*ptr == ' ') {
            palabra2 = ptr + 1;
            for (j = 0; j <= i; j++) {
                palabra1[j] = frase[j];
            }
            palabra1[j] = '\0';
      } 
    }    

    buf = strlen(palabra1) + strlen(palabra2);

    char buffer[buf + 1];
    strcpy(buffer, palabra2);
    buffer[strlen(buffer)] = ' ';
    strcat(buffer, palabra1);

    swaped = palabra2;
    printf("a ver: %s\n", buffer);
}

int main(void) {
    char* frase;
    int buf = 100; //si se elimina el malloc(creo que es lo mejor) tambien esta al dope esto pero alta paja a las 5 am

    frase = malloc(buf * sizeof(buf)); //se puede eliminar el malloc y usar un array de char onda char frase[100]

    printf("Ingresar frase: ");
    fgets(frase, buf, stdin);

    printf("la frase ingresada es: %s\n", frase);
    swap_string(frase); //si se elimina el malloc tambien se elimina esto

    free(frase);
}
