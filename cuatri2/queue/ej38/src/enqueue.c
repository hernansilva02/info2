#include "../lib/enqueue.h"
#include <stdio.h>
#include <stdlib.h>

node_t* enqueue(node_t** head, node_t* tail, persona_t persona) {
    node_t* nodoNuevo = malloc(sizeof(node_t));
    nodoNuevo->persona = persona;
    nodoNuevo->next = NULL;

    if (nodoNuevo == NULL) {
        printf("No se pudo crear espacio en memoria\n");
        return NULL;
    }
    if (tail == NULL) {
        tail = *head = nodoNuevo;  
        return tail;
    }
    
    tail->next = nodoNuevo;
    tail = nodoNuevo;

    return tail;
}
