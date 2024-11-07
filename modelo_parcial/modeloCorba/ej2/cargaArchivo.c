#include <stdio.h>
#include <string.h>

typedef struct{
    int cl;
    char d[30];
    unsigned int tipo;
    char b;
} datos_t;


int main() {
    FILE* fp = fopen("datos.dat", "wb");
    datos_t dato1, dato2, dato3, dato4, dato5;

    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    dato1.cl = 12;
    strcpy(dato1.d, "salamin con queso");
    dato1.tipo = 102;
    dato1.b = 'B';
    

    dato2.cl = 3;
    strcpy(dato2.d, "Empanada brioche");
    dato2.tipo = 1;
    dato2.b = 'A';


    dato3.cl = 5;
    strcpy(dato3.d, "Pernil de cerdo");
    dato3.tipo = 30;
    dato3.b = 'B';


    dato4.cl = 9;
    strcpy(dato4.d, "transistor bc547b");
    dato4.tipo = 45;
    dato4.b = 'B';

    dato5.cl = 10;
    strcpy(dato5.d, "minuchi topu");
    dato5.tipo = 77;
    dato5.b = 'A';

    fwrite(&dato1, sizeof(datos_t), 1, fp);
    fwrite(&dato2, sizeof(datos_t), 1, fp);
    fwrite(&dato3, sizeof(datos_t), 1, fp);
    fwrite(&dato4, sizeof(datos_t), 1, fp);
    fwrite(&dato5, sizeof(datos_t), 1, fp);
}
