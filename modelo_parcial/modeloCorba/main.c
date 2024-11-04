/*Existe un archivo medidas.dat, binario de organización directa con la siguiente estructura:
c
id(long), descripción(char[120]), double medida, estado(unsigned), baja(int 0:alta 1:baja)
Se pide, usando funciones de lenguaje C, que pase como argumento el id entre otros parámetros y agregue un elemento en una pila (estructura dinámica) con el elemento de un registro coincidente con el id, si está marcado como alta, que los bits 0,1,2 y 3 del campo estado estén en 1, y las 3 primeras letras de la descripción son "ESP", además modificar el campo baja y regrabar el registro en este caso. La función deberá retornar lo adecuado, teniendo en cuenta que no hay variables globales.

En la función main() correr la función 10 veces y luego mostrar el contenido de la pila
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long id;
    char desc[120];
    double medida;
    unsigned int estado;
    int baja;
}medidas_t;

typedef struct nodo_t {
    medidas_t medidas;
    struct nodo_t* prev;
}nodo_t;

void flushline(void) {
    int c;
    while((c = getchar()) != '\n');
}

nodo_t* push(long id, nodo_t* top) {
    medidas_t nuevaMedida;
    nodo_t* nodoNuevo = (nodo_t*)malloc(sizeof(nodo_t));

    if (nodoNuevo == NULL) {
        printf("No se pudo crear memoria\n");
        return NULL;
    }

    FILE* fp = fopen("medidas.dat", "rb+");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return NULL;
    }

    fseek(fp, (1L) * (id - 1) * sizeof(medidas_t), SEEK_SET);

    fread(&nuevaMedida, sizeof(medidas_t), 1, fp);

    if (nuevaMedida.id == id && nuevaMedida.estado & 15 && (nuevaMedida.desc[0] + nuevaMedida.desc[1] + nuevaMedida.desc[2]) == 232 && !nuevaMedida.baja) {
        if (top == NULL) {
            top = nodoNuevo;
            nodoNuevo->prev = NULL; 
        } else {
            nodoNuevo->medidas = nuevaMedida;
            nodoNuevo->prev = top;
            top = nodoNuevo;
        }

        nuevaMedida.baja = 1;

        fseek(fp, (1L) * (id - 1) * sizeof(medidas_t), SEEK_SET);
//        fseek(fp, (1L) * sizeof(medidas_t) * -1, SEEK_CUR); Mueve el cursor una pos antes para estar en el registro

        fwrite(&nuevaMedida, sizeof(medidas_t), 1, fp);
        return top;
    }
    return top;
}

void cargarArchivo(void) {
    int op;
    medidas_t medida;
    FILE* fp = fopen("datos.dat", "wb");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }

    do {
        printf("\nIngresar ID: ");
        scanf("%ld", &medida.id);
        flushline();

        printf("Ingresar descripcion: ");
        fgets(medida.desc, sizeof(medida.desc), stdin);
        flushline();

        printf("Ingresar medida: ");
        scanf("%lf", &medida.medida);
        flushline();

        printf("Ingresar estado: ");
        scanf("%ud", &medida.estado);
        flushline();

        printf("Ingresar baja: ");
        scanf("%d", &medida.baja);
        flushline();

        printf("Desea seguir ingresando Medidas? 1--Si 2--No");
        scanf("%d", &op);
        flushline();
    } while (op == 1);
    fclose(fp);
}

void leerArchivo(void) {
    medidas_t medidas;
    FILE* fp = fopen("medidas.dat", "rb");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }

    while (fread(&medidas, sizeof(medidas_t), 1, stdin) == 1) {
        printf("ID: %ld\nDescripción: %s\n, Medida(cm): %lf\nEstado: %ud\nBaja: %d", medidas.id, medidas.desc, medidas.medida, medidas.estado, medidas.baja);
    }

}

int main(void) {
    long id;
    nodo_t* top = NULL;
    nodo_t* temp = NULL;
    int op;

    do {
        printf("Elegir una opcion: \n");
        printf("1)Realizar ejercicio\n2)Cargar Archivo\n3)Leer Archivo");
        scanf("%d", &op);
        flushline();

        switch (op) {
            case 1:
                for (int i = 0; i <= 3; i++) {
                    printf("Ingresar ID: ");
                    scanf("%ld", &id);
                    flushline();

                    top = push(id, top);
                }
                temp = top;
                while (top != NULL) {
                    printf("ID: %ld\nDescripción: %s\n, Medida(cm): %lf\nEstado: %ud\nBaja: %d", top->medidas.id, top->medidas.desc, top->medidas.medida, top->medidas.estado, top->medidas.baja);
                    top = top->prev;
                }
                break;

            case 2:
                cargarArchivo();
                break;

            case 3:
                leerArchivo();
                break;

            case 0:
                printf("\nChauuuuu");
                return 0;


        }

    } while(op != 0);
}
