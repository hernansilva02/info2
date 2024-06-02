#include <stdio.h>

int fact(int n);

int main(void) {
    int f = fact(3);
    printf("%d\n", f);
}

int fact(int n) {
    if(!n) {
        return 1;
    }
    return n * fact(n-1);
}
