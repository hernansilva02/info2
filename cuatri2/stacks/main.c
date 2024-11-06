#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int valor;
    struct node_t* previo;
} node_t ;

node_t* push(int valor, node_t* top) {
    node_t* nodoNuevo = (node_t*)malloc(sizeof(node_t));
    if (nodoNuevo == NULL) {
        printf("No hay espacio en memoria o hubo un error\n");
        return NULL;
    }
    nodoNuevo->valor = valor;
    nodoNuevo->previo = top;
    top = nodoNuevo;
    return nodoNuevo;
}

node_t* pop(node_t* top) {
    if (top == NULL) {
        printf("El stack esta vacio, no hay por que hacer pop\n");
        return NULL;
    }
    node_t* temp = top;
    top = top->previo;
    free(temp);
    return top;
}

void printStack(node_t* top) {
    if (top == NULL) {
        printf("Stack vacio\n");
    }

    while (top != NULL) {
        printf("%d\n", top->valor);
        top = top->previo; 
    }
}

int main() {
    node_t* top = NULL; //Seteo del inicio de la lista/pila
    top = push(2, top);
    top = push(3, top);
    top = push(4, top);
    top = push(7, top);
    printStack(top);
    printf("Con el elemento popeado queda:\n");
    top = pop(top);
    top = pop(top);
    printStack(top);
}
