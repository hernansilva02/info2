
/*
Simulación 2 parcial Informática 2


 Existe un archivo llamado "datos.dat" de tipo binario cuya organización es directa con la
siguiente estructura: cl(clave) entera, d(descripción) cadena de caracteres, t(Tipo) entero,
m(Marca 'A': Alta 'B': Baja), e(Estado) entero sin signo.
Se pide:
1. Realizar una función que pase como parámetro el Código de la pieza, y apile registro
coincidente si el campo e tiene el bit 7 con valor 0, en caso contrario no lo apile, y
retorne un puntero correspondiente al primero de la pila.
2. Realizar una clase pila que tenga un constructor, destructor y un método llamado
despilar() que se le pase el primero de la pila y desapile los registros grabándolos en el
archivo pila.dat . Realizar un pequeño main() usando la función y la clase.
 No usar variables globales. 
 */

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

typedef struct datos_t {
    int cl;
    char d[30];
    int t;
    unsigned int m;
    int e;
}datos_t;

typedef struct nodo_t {
    datos_t dato;
    struct nodo_t* prev;
}nodo_t;

nodo_t* push(nodo_t* top, int cl) {
    datos_t dato;
    FILE* fp = fopen("datos.dat", "rb");
    if (fp == NULL) {
        printf("no se pudo abrir el archivo\n");
        return top;
    }

    fseek(fp, (1L)*(cl - 1)*sizeof(datos_t), SEEK_SET); //por ser archivo de org directa.

    fread(&dato, sizeof(datos_t), 1, fp);

    if (dato.cl == cl && (dato.e & 128)) {
        nodo_t* nodoNuevo = (nodo_t*)malloc(sizeof(nodo_t));
        nodoNuevo->dato = dato;

        if (nodoNuevo == NULL) {
            printf("No se pudo crear espacio en memoria\n");
            return NULL;
        }

        if (top == NULL) {
            top = nodoNuevo;
            return top;
        }

        nodoNuevo->prev = top;
        top = nodoNuevo;

        fclose(fp);
        return top;
    }
    return top;
}

class Cpila {
    FILE* fp;
    public:
        //constructor
        Cpila() {
            fp = fopen("pila.dat", "rb+");
        }
        //destructor
        ~Cpila() {
            fclose(fp);
        }

        void despilar(nodo_t* top);
};

void::Cpila::despilar(nodo_t* top) {
    nodo_t* temp;

    if (!fp) {
        return; 
    }

    while (top) {
        temp = top;
        top = top->prev;
        fwrite(&temp->dato, sizeof(datos_t), 1, fp);
        delete(temp);
    }
}

int main(void) {
    Cpila ob;
    nodo_t* top = NULL;

    top = push(top, 10);

    ob.despilar(top);

    return 0;


}
