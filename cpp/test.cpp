#include <cstdio>
#include <cstdlib>
#include <iostream>

typedef struct {
    int valor;
    char* desc[120];
}datos_t;

typedef struct nodo_t {
    datos_t reg;
    nodo_t* next;
}nodo_t;

class Pila {
    FILE* fp;
    public:
    Pila() {
        fp = fopen("datos.dat", "wb+");
    }

    ~Pila() {
        if (fp != NULL) {
            fclose(fp);
        }
    }

    nodo_t* push(nodo_t* top, datos_t reg) {
        nodo_t* nodoNuevo = new nodo_t;
        nodoNuevo -> reg = reg;

        if (top == NULL) {
            top = nodoNuevo;
            nodoNuevo -> next = NULL;
            return top;
        }
        nodoNuevo -> next = top;
        top = nodoNuevo;
        return top;
    }

    nodo_t* pop(nodo_t* top) {
        if (fp == NULL) {
            std::cout << "No se pudo abrir el archivo" << std::endl; 
            return NULL;
        }
        if (top == NULL) {
            std::cout << "Lista vacia" << std::endl; 
            return top;
        }
        nodo_t* temp = top;
        top = top -> next;


        fwrite(&temp->reg, sizeof(datos_t), 1, fp);

        delete temp;
        return top;

    }

    void printStack(nodo_t* top) {
        nodo_t* temp = top;
        while (temp != NULL) {
            std::cout << "Valor: " << temp -> reg.valor << std::endl << "Descripcion: " << temp -> reg.desc << std::endl; 
            temp = temp -> next;
        }
    }

    void printFile() {
        datos_t regs;

        fseek(fp, 0, SEEK_SET);

        while (fread(&regs, sizeof(datos_t), 1, fp) == 1) {
            std::cout << "Valor: " << regs.valor << std::endl << "Descripcion: " << regs.desc << std::endl; 
        }
    }
};

int main(void) {
    Pila pila;
    nodo_t* top = NULL;
    datos_t reg1, reg2, reg3, reg4, reg5;

    reg1.valor = 2;
    reg1.desc = "salamin con queso";

    reg2.valor = 120;
    reg2.desc = "Jamon iberico";

    reg3.valor = 98;
    reg3.desc = "Paleta de pobre";

    reg4.valor = 5;
    reg4.desc = "matambre de carne";

    reg5.valor = 254;
    reg5.desc = "leverburst";

    top = pila.push(top, reg1);
    top = pila.push(top, reg2);
    top = pila.push(top, reg3);
    top = pila.push(top, reg4);
    top = pila.push(top, reg5);

    std::cout << "Ahora popeamos locoo" << std::endl;
    top = pila.pop(top);
    top = pila.pop(top);
    top = pila.pop(top);

    pila.printStack(top);
    
    std::cout << "Lo que esta en el archivo es: " << std::endl;

    pila.printFile();
}
