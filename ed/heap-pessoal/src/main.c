#include <stdio.h>
#include <stdlib.h>
#include "heap.c"

void print_array(int v[], int size) {
    for(int i = 0; i < size; i++)
	printf("%d ", v[i]);
    printf("\n");
}

void teste_constroi() {
    int v[] = {1, 5, 7, 6, 8, 9, 10, 12, 13, 15, 11, 14};
    int size = sizeof(v)/sizeof(v[0]);

    constroi_heap(v, size);
    print_array(v, size);
}

int main() {
    teste_constroi();

    return EXIT_SUCCESS;
}
