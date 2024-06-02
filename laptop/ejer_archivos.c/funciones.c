#include "myLib.h"
#include <stdio.h>

void mostrarNtoRegulares(void) {
    FILE *fp;
    alumons_t alumno;

    if ((fp = fopen("alumnos.dat", "rb")) == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    fread(&alumno, sizeof(alumons_t), 1, fp);
    while (!feof(fp)) {
        if (alumno.regular == "N" && alumno.legajo & (1<<3)) {
            printf("El alumno %s con legajo %d no es regular", alumno.nombre, alumno.legajo);
            fclose(fp);
            return;
        }
        fread (&alumno, sizeof(alumons_t), 1, fp);//sirve como un acumulador (i++ en un for/while)
    }
    fclose(fp);
    return;
}

void mostrar_alumno(int legajo) {
    FILE *fp;
    alumons_t alumno;

    if ((fp = fopen("alumnos.dat", "rb")) == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }
    fread(&alumno, sizeof(alumons_t), 1, fp);
    while(!feof(fp)) {
        if (alumno.legajo == legajo) {
            printf("el alumno con legajo %d es %s", legajo, alumno.nombre);
            fclose(fp);
            return;
        }
        fread(&alumno, sizeof(alumons_t), 1, fp);//sirve como un acumulador (i++ en un for/while)
    }
    fclose(fp);
    return;
}
