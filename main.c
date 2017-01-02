#include <stdio.h>
#include "isort.h"
#include "printa.h"

int main(int argc, char *argv[]) {
    const size_t SIZE = 5;
    int array[SIZE] = { 2, 4, 8, 1, 3 };

    printf("Before: ");
    printa(array, SIZE);

    // sorting function call here
    //selection_sort(array, 0, SIZE - 1);
    //insertion_sort(array, 0, SIZE - 1);
    merge_sort(array, 0, SIZE - 1);

    printf("After: ");
    printa(array, SIZE);
}
