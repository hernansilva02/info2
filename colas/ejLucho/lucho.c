#include <stdio.h>
    #include <stdlib.h>
    #include <malloc.h>
    #include <string.h>


    typedef struct{
        char nombre[30];
    } registro_t;

    typedef struct nodo_t {
        registro_t registro;
        struct nodo_t *sig;
    } nodo_t;


    int main(){
        registro_t tanda1; 
        nodo_t *pila=NULL;
        nodo_t *aux=NULL;

        nodo_t *cola=NULL;
        nodo_t* principio=NULL;
        nodo_t* fin=NULL;                                                   
        int op=1;

        do
        {
            printf("Ingrese el nombre del componente\n");
            scanf("%s",tanda1.nombre);

            //carga COLA
            cola=(nodo_t*)malloc(sizeof(nodo_t));
            strcpy(cola->registro.nombre, tanda1.nombre);

            if(fin==NULL){
                principio=fin=cola;
            }
            else{
                fin->sig = cola;
                fin=cola;
                }
            
            
            // cargar PILA x
            aux=(nodo_t*)malloc(sizeof(nodo_t));
            strcpy(aux->registro.nombre, tanda1.nombre);
            aux-> sig=pila;                         
            pila=aux;

            printf("\nDesea seguir ingresando datos?\n1) Si   2)No \n");
            scanf("%d",&op);

        } while (op==1);
        

        //recorrer PILA
        printf("\nPILA\n");
         aux=pila;
        while(aux!=NULL){
            printf("\nNOMBRE: %s",aux->registro.nombre);
            aux = aux->sig;
            free(pila);
            pila=aux;
        }

        //Recorrer cola
        printf("\nCOLA\n");
        principio=fin;
        if(principio!=NULL){
            printf("\nNOMBRE: %s",fin->registro.nombre);
        }

        return 0;

    }
