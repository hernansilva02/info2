#include "lib/deque.h"
#include "lib/enqueue.h"
#include "lib/ejercicio.h"
#include "lib/structs.h"
#include "lib/flushline.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    persona_t persona;
    int op;
    char edad[3];
    node_t* head = NULL;
    node_t* tail = NULL;

    printf("Bienvenido al ejercicio 38 sobre filas/colas\n");
    do {
        printf("Ingresar nombre: ");
        fgets(persona.nombre,sizeof(persona.nombre), stdin);
        flushline(persona.nombre);

        printf("\nIngresar apellido: ");
        fgets(persona.apellido,sizeof(persona.apellido), stdin);
        flushline(persona.apellido);

        printf("\nIngresar edad: ");
        fgets(edad,sizeof(edad), stdin);
        flushline(edad);
        persona.edad = atoi(edad);

        printf("\nIngresar telefono: ");
        fgets(persona.telefono,sizeof(persona.telefono), stdin);
        flushline(persona.telefono);

        printf("\nIngresar mail: ");
        fgets(persona.mail,sizeof(persona.mail), stdin);
        flushline(persona.mail);

        tail = enqueue(&head, tail, persona);

        printf("Seguir añadiendo registros de personas? 1--Si 2--No\n");
        scanf(" %d", &op);
    }while(op == 1);

    lectura(head);
}
