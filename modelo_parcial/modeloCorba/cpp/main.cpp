#include <iostream>
#include <string>

class foo {
public:
    static int i;
};

int foo::i = 2;


using namespace std;

int main(void) {
    string palabra = "hola";

    cout << "el numero en la clase es: " << foo::i << endl; 
    cout << "la palabra es: " << palabra << endl;
    cout << "El primer caracter es: " << palabra[0] << endl;
}
