#include "../lib/ejercicio.h"
#include <stdio.h>

void carga_archivo(persona_t persona) {
    FILE* fp = fopen("contactos.dat", "ab+");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    fwrite(&persona, sizeof(persona_t), 1, fp);
}

void lectura(node_t* head) {
    printf("Entre a lectura\n");
    node_t* temp = head;
    while (temp != NULL) {
        if (temp->persona.edad > 21) {
            printf("Nombre: %s\nApellido: %s\nEdad: %d\nTelefono: %s\nMail: %s\n\n", temp->persona.nombre, temp->persona.apellido, temp->persona.edad, temp->persona.telefono, temp->persona.mail);
            carga_archivo(temp->persona);
        }
        temp = temp->next;
    }
}
