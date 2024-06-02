#include <stdio.h>
#include <string.h>
#define D 30

char frase[D];     // hola juan\o

void swapCadena(char frase[D]){
    char* inicio = frase;
    char subfrase1[D];
    char subfrase2[D];


    for (int i=0; i<D; i++){ 
        if(*inicio!=' '){
            subfrase1[i]=*inicio;
            inicio++;}
        } 

    for(int i=0; i<D; i++){
        inicio+1;
        if(*inicio!= '\0'){
            subfrase2[i]=*inicio;
            inicio++;
        }
    }

    printf("\nfrase 1: %s", subfrase1);
    printf("\nfrase 2: %s", subfrase2);
    }

int main()
{
    printf("ingrese la frase: ");
    fgets(frase, sizeof(frase), stdin);
    printf("la frase es: %s", frase);
    swapCadena(frase);
    return 0;
}
