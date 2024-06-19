#include <string.h>
#include <stdio.h>
#include "../libs/leer_bajas.h"
#include "../libs/piezas.h"

void leer_bajas() {
    system("clear");
    piezas bajas;
    FILE* fp = fopen("baja.dat", "rb");

    memset(&bajas, 0, sizeof(piezas));

    if (fp == NULL) {
        printf("No se pudo abrir ""bajas.dat""\n");
        return;
    }

    while ((fread(&bajas, sizeof(piezas), 1, fp)) == 1) {
        printf("ID: %ld\n", bajas.id); 
        printf("Descripcion: %s\n", bajas.descripcion);
        printf("Tipo: %d\n\n", bajas.tipo);
    }

    fclose(fp);
    return;
}
