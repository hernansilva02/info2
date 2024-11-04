#include "../lib/flushline.h"
#include <stdio.h>

void flushline(char* palabra) {
    int c;
 //    if (palabra[strlen(palabra) - 1] == '\n') {
 //        printf("Entre al if");
 //        palabra[strlen(palabra) - 1] = '\0';
 //    }
    
    while((c = getchar()) != '\n' && c != EOF);
    return;
}
