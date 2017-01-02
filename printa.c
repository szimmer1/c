#include <stdio.h>
#include "printa.h"

void printa(int array[], size_t size) {
    char delim = '\0';
    printf("{");
    for (int i=0; i < size; i++) {
        printf("%c %d", delim, array[i]);
        delim = ',';
    }
    printf(" }\n");
}
