#include "../lib/flushline.h"
#include <string.h>

char* flushline(char *palabra) {
    if (palabra[strlen(palabra) - 1] == '\n') {
        palabra[strlen(palabra) - 1] == '\0';
    }
    return palabra;
}
