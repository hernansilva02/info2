#include <stdio.h>
#include <string.h>

typedef struct{
    long legajo;
    char nombre[60];
    long id;
    float promedio;
    unsigned int estado;
    char baja;
} alumno_t;

int main() {
    FILE* fp = fopen("alumnos.dat", "wb");
    alumno_t dato1, dato2, dato3, dato4, dato5;

    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    dato1.legajo = 12;
    strcpy(dato1.nombre, "Hernan");
    dato1.promedio = 7.5;
    dato1.id = 10;
    dato1.baja = 'B';
    dato1.estado = 38; //no apila
    

    dato2.legajo = 3;
    strcpy(dato2.nombre, "Flor");
    dato2.promedio = 8.75;
    dato2.id = 10;
    dato2.baja = 'B';
    dato2.estado = 54; //apila


    dato3.legajo = 5;
    dato3.id = 10;
    strcpy(dato3.nombre, "Lucho");
    dato3.promedio = 9;
    dato3.baja = 'B';
    dato3.estado = 20; //apila


    dato4.legajo = 9;
    dato4.id = 10;
    strcpy(dato4.nombre, "Nicote");
    dato4.promedio = 10;
    dato4.baja = 'A';
    dato4.estado = 48; //no apila

    dato5.legajo = 10;
    dato5.id = 10;
    strcpy(dato5.nombre, "Elias");
    dato5.promedio = 4.25;
    dato5.baja = 'B';
    dato5.estado = 52; //apila

    fwrite(&dato1, sizeof(alumno_t), 1, fp);
    fwrite(&dato2, sizeof(alumno_t), 1, fp);
    fwrite(&dato3, sizeof(alumno_t), 1, fp);
    fwrite(&dato4, sizeof(alumno_t), 1, fp);
    fwrite(&dato5, sizeof(alumno_t), 1, fp);
}
