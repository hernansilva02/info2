#include <stdio.h>
#include <stdlib.h>
#include "lib/struct.h"
#include "lib/push.h"
#include "lib/funcion_edad.h"
#include "lib/flushline.h"

int main(void) {
    node_t* top = NULL; //Inicio del stack
    int opc, c;
    char* edad = malloc(sizeof(int));
    char* opcc = malloc(sizeof(int));
    persona_t nuevaPersona;

    printf("Bienvenido al ejercicio 35 sobre stacks\n");

    do {
        printf("Ingresar el nombre de la persona: ");
        fgets(nuevaPersona.nombre, sizeof(nuevaPersona.nombre), stdin);

        flushline(nuevaPersona.nombre);

        printf("Ingresar el apellido de la persona: ");
        fgets(nuevaPersona.apellido, sizeof(nuevaPersona.apellido), stdin);

        flushline(nuevaPersona.apellido);

        printf("Ingresar la edad de la persona: ");
        fgets(edad, sizeof(nuevaPersona.edad), stdin);

        flushline(edad);

        nuevaPersona.edad = atoi(edad);
        
        printf("Ingresar el telefono de la persona: ");
        fgets(nuevaPersona.telefono, sizeof(nuevaPersona.telefono), stdin);

        flushline(nuevaPersona.telefono);


        printf("Ingresar el mail de la persona: ");
        fgets(nuevaPersona.mail, sizeof(nuevaPersona.mail), stdin);

        flushline(nuevaPersona.mail);

        top = push(nuevaPersona, top);

        printf("Desea ingresar otra persona? 0--Si 1--No");
        fgets(opcc, sizeof(int), stdin);

        flushline(opcc);

        opc = atoi(opcc);
    }while (opc == 0);

    funcion_edad(top);
}
