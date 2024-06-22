#include <stdio.h>
#include "libs/ubicar.h"
#include "libs/crear_archivo.h"
#include "libs/escritura.h"
#include "libs/ejercicio.h"
#include "libs/cambio_mayusc.h"

int main() {
    long id_selec;
    long id;
    int op;
    char nueva_cat[90];

    system("clear");

    do {
        printf("Elija una opción\n");
        printf("1-Crear Archivo\n");
        printf("2-Realizar ejercicio\n");
        printf("3-Salir\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                crear_archivo();
                id = escritura(&id);
                break;
            case 2:
                printf("Seleccionar ID\n");
                scanf("%ld", &id);

                int i = 
                break;
        }
    }while (op != 3);

}
