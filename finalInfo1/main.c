 //Una Empresa Registra mensualmente la siguiente información:
 //Sucursal - entera (1 a 3 ) Articulo - entero (1 a 60) Cantidad - entero Descripción del Artículo - Cadena de caracteres.
 //
 //Usar un menú para:
 //
 //A. Cargar las fichas (no se saben cuantas son) teniendo en cuenta cargar las descripciones una sola vez, mostrando en pantalla la misma si ya fue ingresada.
 //
 //B. Al finalizar el punto 1 emitir un listado ordenado por totales de artiíulo de la siguiente forma:
 //
 //Ej. Articulo Sucursal 1 Sucursal 2 Sucursal 3 Total Martillo xxx xxx xxx xxx Pala xxx xxx xxx xxx
 //
 //Como seria una estructura para el punto anterior


#include <stdio.h>
#include <string.h>

int main(void) {
    int articulos_sucursales[60][6] = {0}; //Matriz de articulos, sucursales y total e indice
    int fichas, op = 0;
    char articulos_descrip[60][50] = {0};

     do {
         int sucursalTemp, articuloTemp, cantidadTemp;
         char descTemp[50] = {0};

         do {
             printf("Ingresar sucursal: \n");
             scanf("%d", &sucursalTemp);
         }while (sucursalTemp < 1 || sucursalTemp > 3);

         do {
             printf("Ingresar articulo: \n");
             scanf("%d", &articuloTemp);
         }while (articuloTemp < 1 || articuloTemp > 60);

         articuloTemp--;

     do {
         printf("Ingresar descripción: \n");
         scanf("%s", descTemp);


         for (int i = 0; i < 60; i++) {
             if (articulos_descrip[i] == 0) {
                break;        
             } if (!strcmp(descTemp, articulos_descrip[i])) {
                 printf("Esta descripcion esta repetida y es: %d\n", i);
                 op = 1;
                 break;
                 }
             }
         }while(op);


         printf("Ingresar cantidad: \n");
         scanf("%d", &cantidadTemp);

         articulos_sucursales[articuloTemp][sucursalTemp] = cantidadTemp;

         int suma = 0;
         for (int i = 1; i < 3; i++) {
            articulos_sucursales[articuloTemp][i] += suma; 
         }
         articulos_sucursales[articuloTemp][4] = suma;
         articulos_sucursales[articuloTemp][0] = articuloTemp;

         strcpy(articulos_descrip[articuloTemp], descTemp);

         printf("Seguir cargando fichas? 1-No 2-Si\n");
         scanf("%d", &fichas);

    }while (fichas == 2);

    return 0;
}
