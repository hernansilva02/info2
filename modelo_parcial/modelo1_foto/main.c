#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long legajo;
    char nombre[60];
    long id;
    float promedio;
    unsigned int estado;
    char baja;
} alumno_t;

typedef struct nodo_t {
    int pos;
    struct nodo_t* prev;
} nodo_t;

nodo_t* ejercicio(nodo_t* top) {
    alumno_t alumno;
    FILE* fp = fopen("alumnos.dat", "rb+");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return NULL;
    }

    for (int i = 0; (fread(&alumno, sizeof(alumno_t), 1, fp)) == 1; i++) {
        if (alumno.baja == 'B' && (alumno.estado & 20) == 20) {
            printf("Entre al if por %d vez\n", i);
            nodo_t* nodoNuevo = (nodo_t*)malloc(sizeof(nodo_t));
            nodoNuevo->pos = i;

            nodoNuevo->prev = top;
            top = nodoNuevo;

            //hace una xor con el corrimiento de bits del 1 para cambiar los bits solicitados
            alumno.estado ^= (1 << 2); 
            alumno.estado ^= (1 << 4);
            
            fseek(fp, (1L) * sizeof(alumno_t) * -1, SEEK_CUR);
            
            fwrite(&alumno, sizeof(alumno_t), 1, fp);

        }
    }
    fclose(fp);
    return top;
}

int main(void) {
    nodo_t* top = NULL;

    top = ejercicio(top);

    nodo_t* temp = top;

    if (top == NULL) {
        printf("No hay nada para printear en la pila\n");
        return -1;
    }

    while (top != NULL) {
        printf("Pos: %d\n", top->pos);
        top = top->prev;

        free(temp);

        temp = top;
    }
}
