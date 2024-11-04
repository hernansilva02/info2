#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int valor;
    struct node_t* siguiente;
}node_t;

int main(void) {
    int op, valor, deque;
    node_t* head = NULL;
    node_t* tail = NULL;

    do {
        printf("Ingresar valor a añadir a la cola: \n");
        scanf(" %d", &valor);
        node_t* nodoNuevo = malloc(sizeof(node_t));
        nodoNuevo->valor = valor;
        nodoNuevo->siguiente = NULL;
        if (tail == NULL) {
            tail = head = nodoNuevo; 
        } else {
            tail->siguiente = nodoNuevo;
            tail = nodoNuevo;
        }

        printf("Desea seguir ingresando valores a la cola? 1--Si 2--No\n");
        scanf(" %d", &op);
    }while(op == 1);
    
    //lectura de la queue
    node_t* temp = head;
    while (temp != NULL) {
        printf("Valor: %d\n", temp->valor);
        temp = temp->siguiente;
    }

    temp = NULL;

    //dequeue
    printf("Cuantos valores desea sacar de la cola?: ");
    scanf(" %d", &deque);
    if (!deque) {
        printf("Nada para sacar\n");
        return 0;
    }
    for (int i = 0; i < deque; i++) {
        node_t* temp2 = head; 
        head = head->siguiente;
        free(temp2);
    }

    temp = head;
    while (temp != NULL) {
        printf("Valor: %d\n", temp->valor);
        temp = temp->siguiente;
    }
}
