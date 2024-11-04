#include <stdio.h>
#include <stdlib.h>
#include "../lib/push.h"

node_t* push(persona_t persona, node_t* top) {
    node_t* nuevaPersona = (node_t*)malloc(sizeof(node_t));

    if (nuevaPersona == NULL) {
        printf("Error asignando espacio de memoria para nueva persona\n");
        return NULL;
    }

    nuevaPersona->x = persona;
    nuevaPersona->previo = top;
    top = nuevaPersona;

    return top;

}
