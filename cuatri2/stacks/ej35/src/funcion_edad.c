#include "../lib/funcion_edad.h"
#include <stdio.h>

void funcion_edad(node_t* persona) {
    node_t* temp = persona;
    FILE* fp = fopen("contactos.dat", "rb+");
    if (fp == NULL) {
        printf("No se puedo abrir el archivo\n");
        return;
    }

    printf("Los registros mayores a 21 años son: \n");
    while (temp != NULL) {
        if (temp->x.edad > 21) {
            printf("Nombre: %s, Apellido: %s, Edad: %d, Telefono: %s, Mail: %s\n", temp->x.nombre, temp->x.apellido, temp->x.edad, temp->x.telefono, temp->x.mail);
            fwrite(&(temp->x), sizeof(temp->x), 1, fp);
        }
    }

}
