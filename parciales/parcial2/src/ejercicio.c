#include "../libs/estruct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ejercicio(long id) {
    productos b; 
    char* ptr;
    int idCont = 0;

    FILE* fp = fopen("datos.dat", "rb+");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo para el cambio a mayusculas\n");
        return 1;
    }

    while ((fread(&b, sizeof(productos), 1, fp)) == 1 && b.id != id);

    if (feof(fp)) {
        printf("No existe ese ID\n");
        return 0;
    }

    
    ptr = b.categoria;

    while (*ptr != '\0') {
        if (*ptr == ' ' || (*ptr >= 'A' && *ptr <= 'Z')) {
            ptr++; 
        } else {
            *ptr -= 32;
            ptr++; 
        }
    }

    printf("la cadena en mayusculas es: %s\n", b.categoria);


    if ((b.estado & (1 << 2)) == 4) {
        fseek(fp, -sizeof(productos), SEEK_CUR);
        fwrite(&b, sizeof(productos), 1, fp);
        rewind(fp);
        fread(&b, sizeof(productos), 1, fp);
        while (!feof(fp)) {
            fread(&b, sizeof(productos), 1, fp);
            idCont++; 
        }
    }

    fclose(fp);
    return idCont++;
}
