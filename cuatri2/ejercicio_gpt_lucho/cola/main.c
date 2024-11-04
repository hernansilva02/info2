#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_t {
    char* nombre;
    struct nodo_t* siguiente;
}nodo_t;

nodo_t* enqueue(nodo_t* tail, char* nombre, nodo_t** head) {
    nodo_t* nuevoNodo = malloc(sizeof(nodo_t));
    nuevoNodo->nombre = nombre;
    nuevoNodo->siguiente = NULL;

    if (nuevoNodo == NULL) {
        printf("no se pudo crear espacio en memoria\n");
        return NULL;
    }

    if (tail == NULL) {
        tail = *head = nuevoNodo;  
        return tail;
    } 

    tail->siguiente = nuevoNodo;
    tail = nuevoNodo;
    return tail;
}

nodo_t* deque(nodo_t* head, nodo_t** tail) {
    if (head == NULL) {
        printf("no hay una cola para hacer deque\n");
        return NULL;
    }
    nodo_t* temp = head;
    head = head->siguiente;

    if (head == NULL) {
        *tail = head;
    }
    free(temp);
    return head;
}

void recorrerQ(nodo_t* head) {
    if (head == NULL) {
        printf("fila vacia\n");
    }
    nodo_t* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->nombre);
        temp = temp->siguiente;
    }
}


int main(void) {
    nodo_t* head = NULL;
    nodo_t* tail = NULL;

    tail = enqueue(tail, "hola", &head);
    tail = enqueue(tail, "sham", &head);
    tail = enqueue(tail, "poo", &head);
    head = deque(head, &tail);
    recorrerQ(head);
}
