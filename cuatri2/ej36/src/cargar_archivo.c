#include "../lib/cargar_archivo.h"
#include "../lib/structs.h"
#include <stdio.h>

void cargar_archivo(char* nombre) {
    d dato;
    int opc;
    FILE* fp = fopen(nombre, "rb+");

    do {
        printf("Ingresar  una clave\n");
        scanf("%lu", &dato.clave);

        printf("Ingresar descripcion\n");
        fgets(dato.d, sizeof(dato.d), stdin);

        printf("Ingresar tipo: \n");
        scanf("%c", &dato.tipo);

        printf("Ingresar estado (alta o baja)");
        scanf("%c", &dato.b);

        fwrite(&dato, sizeof(d), 1, fp);

        printf("Desea seguir cargando datos? 1--Si 2--No");
        scanf("%d", &opc);
    }while (opc == 1);
}
