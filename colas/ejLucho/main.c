#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    char nombre[20];
    struct node_t* siguiente;
}node_t;

void flushline(char* palabra) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    node_t* principio = NULL;
    node_t* fin = NULL;
    int op = 1;

    do {
        node_t* nodoNuevo = (node_t*)malloc(sizeof(node_t));
        printf("Ingresar nuevo componente\n");
        scanf(" %s", nodoNuevo->nombre);

        nodoNuevo->siguiente = NULL;

        if (fin == NULL) {
            fin = principio = nodoNuevo; 
        } else {
            fin->siguiente = nodoNuevo;
            fin = nodoNuevo;
        }

        printf("Seguir ingresando componentes? 1--Si 2--No\n");
        scanf(" %d", &op);
    }while(op == 1);

    while (principio  != NULL) {
        printf("Nombre del componente: %s\n", principio->nombre);
        principio = principio->siguiente;
    }

    return 0;
}
