/*Se requiere desarrollar un código C para determinar los clasificados para una carrera de fórmula 1, y el consecuente orden de “largada”. 
 Dicho orden se determina en base a una prueba de clasificación, en la que cada conductor debe realizar varias vueltas al circuito, 
 quedándose con el mejor tiempo de todas ellas. 
Participan en total 58 participantes, de los cuales se conocen los siguientes datos de cada participante:
-Número de auto (no son necesariamente correlativos)
-Tiempo de vuelta (correspondiente a cada una de las vueltas)
-Nombre y Apellido
-Escudería (Lotus, Ferrari, etc.)
Clasificarán los 30 mejores conductores. La prueba consiste en que cada conductor realiza varias vueltas durante un tiempo determinado, 
quedándose con el mejor tiempo de todas ellas (es decir, el menor). Observe que podría darse que un conductor de más vueltas que otro, que un
 conductor de una sola vuelta, e incluso que no llegue a completar ninguna (en este caso, obviamente no clasificará).
El programa debe cargar los datos por teclado. Cuando termine la prueba, se ingresará un número de auto negativo como condición de fin de carga.
A continuación, se informará un listado de los 30 clasificados (o menos, si no se alcanza este número) ordenados por orden de largada (o sea, por mejor tiempo).
 En caso que más de 30 conductores completen la prueba, se emitirá un listado de suplentes con los mejores tiempos a partir del 31º conductor.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    float tiempo;
    char nombre[30];
    char apellido[30];
    char escuderia[20];
}datos_t;

typedef struct nodo_t {
    datos_t dato;
    struct nodo_t* next;
    struct nodo_t* prev;
} nodo_t;

//Funcion para no comerme los \n que quedan del scanf o del fgets. No le des bola en otras palabras.
void flushline(void) {
    int c;
    while ((c = getchar()) != '\n');
}

int carga(nodo_t** principio, nodo_t** fin) {
    int op = 1;
    int largo = 0; //largo de la lista
    datos_t corredor;


    printf("Bienvenido al menu de carga. Ingrese los siguientes datos: \n");
    while (op != 0) {
        printf("\nNumero de vehiculo: ");
        scanf("%d", &corredor.numero);
        flushline();

        printf("\nMejor tiempo de vuelta: ");
        scanf("%f", &corredor.tiempo);
        flushline();


        printf("\nNombre del corredor: ");
        fgets(corredor.nombre, sizeof(corredor.nombre), stdin);
        flushline();
    
        printf("\nApellido del corredor: ");
        fgets(corredor.apellido, sizeof(corredor.apellido), stdin);
        flushline();


        printf("\nEscuderia: "); 
        fgets(corredor.escuderia, sizeof(corredor.escuderia), stdin);
        flushline();
        
        nodo_t* nodoNuevo = (nodo_t*)malloc(sizeof(nodo_t));

        if (nodoNuevo == NULL) {
            printf("No se pudo crear espacio en memoria\n");
            return -1;
        }

        nodoNuevo->dato = corredor;

        if (*fin == NULL) {
            largo++;
            *principio = *fin = nodoNuevo;
        } else {
            nodoNuevo->prev = *fin;
            nodoNuevo->next = NULL;

            (*fin)->next = nodoNuevo;
            *fin = nodoNuevo;

            largo++; //mantengo el largo de la lista actualizado
        }

        printf("\nDesea seguir añadiendo corredores? 1--Si <0--No\n"); 
        scanf("%d", &op);
        flushline();
    }
    return largo;
}

void ordenarLista(nodo_t* principio, int largo){
    printf("Entre en ordenar Lista");

    if (principio == NULL) {
        printf("No hay lista para ordenar\n");
        return;
    }

    nodo_t* temp = principio;

    for (int i = 0; i < largo; i++) {
        for (int j = 0; j < largo - 1 - i; j++) {
            for (int k = 0; k < j; temp = temp->next);
            
            if (temp->dato.tiempo > temp->next->dato.tiempo) {
                nodo_t* anterior = temp->prev;
                nodo_t* posterior = temp->next;

                if (posterior->next == NULL) {
                    posterior->prev = anterior;
                    anterior->next = posterior;

                    posterior->next = temp;
                    temp->prev = posterior;
                    temp->next = NULL;
                
                }

                if (anterior->prev == NULL) {
                    anterior->next = posterior;
                    anterior->prev = temp;

                    posterior->prev = anterior;
                    
                    temp->next = anterior;
                    temp->prev = NULL;
                }

                posterior->prev = anterior;
                anterior->next = posterior;

                temp->next = posterior->next;
                posterior->next->prev = temp;

                posterior->next = temp;
                temp->prev = posterior;
            }
        }
    }
}

void imprimirLista(nodo_t* principio) {
    printf("Entre en imprimir Lista");
    system("clear"); //No le des bola, es para que se limpie toda la terminal y empezar "de cero" en linux, en windows, si lo queres modificar, es system("cls");
    nodo_t* temp = principio;
    int cont = 1;

    while (temp != NULL && cont <= 5) {
        printf("\nNombre: %s\nApellido: %s\nEscuderia: %s\nNumero de vehiculo: %d\nTiempo: %f", temp->dato.nombre, temp->dato.apellido, temp->dato.escuderia, temp->dato.numero, temp->dato.tiempo);
        temp = temp->next;
        cont++;
    }
}

int main(void) {
    int largo;
    nodo_t* principio = NULL;
    nodo_t* fin = NULL;

    largo = carga(&principio, &fin);

    ordenarLista(principio, largo);

    imprimirLista(principio);
}
