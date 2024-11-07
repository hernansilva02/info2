/*Existe un archivo llamado "datos.dat" de tipo binario cuya organización es secuencial con la siguiente estructura: cl(clave ) entera, d(descripción) cadena de 30 caracteres, tipo (tipo de datos),entero sin signo, valor entero, b( 'A': Alta 'B': Baja),Se pide: Realizar una función que pase como parámetro la clave, entre otro(s) parámetros, y encole dos valores: la clave y su posición física respecto al archivo (registro 1,2, etc), si el campo “tipo” tiene el bit 0 con valor 1, en caso de no encontrarlo crear un nuevo registro en el archivo (sin encolarlo). La función retornara un puntero a la primer posicion de la cola. Realizar el main() con la llamada a dicha función. No utilizar variables Globales
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cl;
    char d[30];
    unsigned int tipo;
    char b;
} datos_t;

typedef struct {
    int cl;
    int pos;
}valores_t;

typedef struct nodo_t {
    valores_t valores;
    struct nodo_t* next;
} nodo_t;

nodo_t* cargarCola(nodo_t* ppio, nodo_t* fin, int clave) {
    FILE* fp = fopen("datos.dat", "rb+");
    datos_t registro;
    int existe = 0;

    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return NULL;
    }

    for (int i = 0; (fread(&registro, sizeof(datos_t), 1, fp)) == 1; i++) {
        if (clave == registro.cl) {
            existe = 1;
            if (registro.tipo & 1) {
                nodo_t* nodoNuevo = (nodo_t*)malloc(sizeof(nodo_t));

                nodoNuevo->valores.pos = i;
                nodoNuevo->valores.cl = clave;
                nodoNuevo->next = NULL;

                if (ppio == NULL) {
                    ppio = fin = nodoNuevo;
                    return ppio;            
                }

                fin->next = nodoNuevo;
                fin = nodoNuevo;

                return ppio;
            }
            printf("El ultimo bit no es 0\n");
        }
    }

    if (!existe) {
        datos_t nuevoRegis;
        int c;
        printf("El registro con la clave %d no existe. Hay que crearlo\nTipo: ", clave);
        scanf("%u", &nuevoRegis.tipo);

        printf("Estado(Baja o Alta): ");
        scanf("%c", &nuevoRegis.b);

        printf("\nDescripcion: ");
        fgets(nuevoRegis.d, sizeof(nuevoRegis.d), stdin);
        while((c = getchar()) != '\n');

        nuevoRegis.cl = clave;

        fseek(fp, 0, SEEK_END);

        fwrite(&nuevoRegis, sizeof(datos_t), 1, fp);
        return ppio;
    }
    return ppio;
}

void imprimirList(nodo_t* ppio) {
    nodo_t* temp = ppio;
    while (temp != NULL) {
        printf("Pos: %d\nClave: %d", temp->valores.pos, temp->valores.cl);
        temp = temp->next;
    }
}

int main(void) {
    nodo_t* ppio = NULL;
    nodo_t* fin = NULL;

    ppio = cargarCola(ppio, fin, 12);

    imprimirList(ppio);
}
