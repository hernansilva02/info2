#include <stdio.h>
#include "libs/crear_archivo.h"
#include "libs/escritura.h"
#include "libs/ejercicio.h"
#include "libs/leer_archivo.h"

int main() {
    long id_selec;
    long id = 0;
    int op;

    system("clear");

    do {
        printf("Elija una opción\n");
        printf("1-Crear Archivo\n");
        printf("2-Realizar ejercicio\n");
        printf("3-Leer archivo\n");
        printf("4-Salir\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                crear_archivo();
                escritura(&id);
                break;
            case 2:
                printf("Seleccionar ID\n");
                scanf("%ld", &id_selec);
                ejercicio(id_selec);
                break;
            case 3:
                system("clear");
                leer_archivo();
                break;
        }
    }while (op != 4);

}
