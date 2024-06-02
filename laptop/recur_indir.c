//Se llama recursion indirecta cuando una funcion se llama a si misma por medio de otra
#include <stdio.h>

int par(int n);
int impar(int n);

int main(void) {
   int numero;
   do {
       printf("Ingresar Numero\n");
       scanf(" %d", &numero);
   }
   while(numero < 0);

   int resultado = par(numero);
   if (resultado) {
       printf("Es Impar\n");
   }
   else {
       printf("Es Par\n");
   }
}

int par(int n) {
   if(n == 0) {
       return 0;
   }
   return impar(n - 1);
}

int impar(int n) {
    if(n==0) {
        return 1;
    }
    return par(n - 1);
}
