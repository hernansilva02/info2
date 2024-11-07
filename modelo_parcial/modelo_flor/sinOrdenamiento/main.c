/* 
2)Una empresa requiere un programa para generar una lista de precios, para lo cual deberá solicitarse el ingreso de las siguientes ternas de datos: Código de Articulo - Precio de costo - Porcentaje de ganancia
Estas ternas se ingresan en cualquier orden. Para indicar el fin de datos se ingresará un código de artículo igual a 0.
Se pide realizar un programa que imprima dicha lista en dos columnas, una con el código de articulo y la otra con el precio de Venta [precio de costo *(1 + porcentaje /100)].
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    float precio;
    int ganancia;
}articulos_t;

typedef struct nodo_t {
    articulos_t articulo;
    struct nodo_t* prev;
    struct nodo_t* next;
}nodo_t;

void flushline(void) {
    int c;
    while((c = getchar()) != '\n');
}

void cargarLista(nodo_t** ppio, nodo_t** fin) {
    int op;
    articulos_t articulo;

    do {
        printf("\nIngresar codigo: ");
        scanf("%d", &articulo.codigo);
        flushline();

        printf("\nIngresar precio: ");
        scanf("%f", &articulo.precio);
        flushline();

        printf("\nIngresar ganancia: ");
        scanf("%d", &articulo.ganancia);
        flushline();

        nodo_t* nodoNuevo = (nodo_t*)malloc(sizeof(nodo_t));
        nodoNuevo->next = NULL;
        nodoNuevo->articulo = articulo;

        if (*ppio == NULL) {
            *ppio = *fin = nodoNuevo;
        } else {
            nodoNuevo->prev = *fin;
            (*fin)->next = nodoNuevo;
            *fin = nodoNuevo;
        }

        printf("\nSeguir ingresando? 1--Si 2--No\n");
        scanf("%d", &op);
        flushline();
    } while (op != 0);

}

void imprimirLista(nodo_t* ppio) {
    system("clear");

    float precio_venta;
    nodo_t* temp = ppio;

    while (temp != NULL) {
        precio_venta = temp->articulo.precio * ((float)1 + (((float)temp->articulo.ganancia)/100));
        printf("Codigo de articulo: %d\t\tPrecio de venta: %f\n", temp->articulo.codigo, precio_venta);
        temp = temp->next;
    }
}

void ordenarLista(nodo_t** ppio) {
    nodo_t* temp = *ppio;

    if (*ppio == NULL) {
        printf("No hay lista para ordenar\n");
        return; 
    }

    for(int i = 0; temp2 != NULL; i++) {
        nodo_t* posterior = temp->next;
        nodo_t* anterior = temp->prev;

        for (int j = 0;j < i; j++) {
            if (temp->articulo.codigo > posterior->articulo.codigo) {
                posterior->prev = anterior;
                posterior->next = temp;

                temp->prev = posterior
                temp
                
            }

        
        }

        temp = temp->next;
    }
}

int main(void) {
    nodo_t* ppio = NULL;
    nodo_t* fin = NULL;


    cargarLista(&ppio, &fin);
    imprimirLista(ppio);

}
