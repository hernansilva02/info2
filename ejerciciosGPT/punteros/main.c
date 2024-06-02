/*Intercambiar palabras*/
#include <stdio.h>
#include <string.h>

char* swap(char frase[]) {
    int contador = 0;
    char* point = frase;
    char* segundapal = NULL;
    char* primerpal = NULL;
    char* tempfrase;
    char tempsegundaPalabra[200];

    int pos = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        point++; 
        if (*point == ' ') {
           segundapal = point + 1; 
        }
    }

    printf("\nLa segunda palabra es: %s", segundapal);

    for (int i = 0; frase[i] != ' '; i++) {
        tempsegundaPalabra[i] = frase[i];
    }

    primerpal = tempsegundaPalabra;
    printf("\nLa primer palabra es: %s\n", primerpal);

    if (contador <= 2) {
        printf("Entre al if");
        char* tmp = segundapal;
        segundapal = frase;
        frase = tmp;
        printf("\n%s", segundapal);
    } else {
        printf("Se ingresaron mas de 2 palabraas\n");
    }

    tempfrase = strcat(primerpal, segundapal);

    printf("\n\nLa frase final es: %s\n", tempfrase);
}

int main(void) {
    char frase[200];
    for (int i = 0; i < 200; i++) {
        frase[i] = '\0';
    }

    printf("Ingresar palabra \n");
    fgets(frase, sizeof(frase), stdin);
    printf("la palabra ingresada fue: %s\n", frase);
    swap(frase);
}
