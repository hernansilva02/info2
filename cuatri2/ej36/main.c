#include "lib/structs.h"
#include "lib/ejercicio.h"
#include "lib/cargar_archivo.h"
#include "lib/leer_archivo.h"
#include "lib/crear_archivo.h"
#include <stdio.h>

int main(void) {
    int opc;
    do {
        printf("Bienvenido al programa del ejericio 36 sobre pilas. Ingresar que desea hacer\n");
        printf("0)Salir 1) Crear archivo \n2)Cargar archivo \n3)Leer archivo \n4)Realizar el ejercicio\n");

        scanf("%d", &opc);
        switch (opc) {
            case 1:
                crear_archivo("archivo.dat");
                break;
            case 2:
                cargar_archivo("archivo.dat");
                break;
            case 3:
                leer_archivo("archivo.dat");
                break;
            case 4:
                nodo_t* res = ejercicio("archivo.dat");
        }
    }while (opc != 0);
}
