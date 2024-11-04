#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_t {
    int valor;
    struct nodo_t* izq;
    struct nodo_t* der;
} nodo_t;

nodo_t* crearNodo(int valor) {
    nodo_t* nuevoNodo = malloc(sizeof(nodo_t));

    if (nuevoNodo == NULL) {
        printf("No se pudo crear espacio en memoria\n");
        return NULL;
    }

    nuevoNodo->valor = valor;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;
    return nuevoNodo;
}

void inorder(nodo_t* root) {
    if (root == NULL) {
        return; 
    }

    inorder(root->izq);
    printf("%d-", root->valor);
    inorder(root->der);
}

void preorder(nodo_t* root) {
    if (root == NULL) {
        return; 
    }

    printf("%d-", root->valor);
    preorder(root->izq);
    preorder(root->der);
}

void postorder(nodo_t* root) {
    if (root == NULL) {
        return; 
    }

    postorder(root->izq);
    postorder(root->der);
    printf("%d-", root->valor);
}

int main(void) {
    nodo_t* n1 = crearNodo(5);
    nodo_t* n2 = crearNodo(6);
    nodo_t* n3 = crearNodo(7);
    nodo_t* n4 = crearNodo(8);
    nodo_t* n5 = crearNodo(9);

    //root
    n1->izq = n2;
    n1->der = n5;

    n2->izq = n3;
    n2->der = n4;

    //inorder
    printf("En orden\n");
    inorder(n1);
    printf("\nPreorder\n");
    preorder(n1);
    printf("\nPostorder\n");
    postorder(n1);
    printf("\n");

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}
