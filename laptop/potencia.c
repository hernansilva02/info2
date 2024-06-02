#include <stdio.h>

int pot(int b, int e);

int main(void) {
    int pote = pot(3,3);
    printf("%d\n", pote);
}

int pot(int b, int e) {
    if(!e) {
        return 1;
    }
    return b * pot(b, e - 1);
}
