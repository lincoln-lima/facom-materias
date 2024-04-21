#include <stdio.h>
#include <stdlib.h>
#include "heap.c"

void print_array(int v[], int size) {
    for(int i = 0; i < size; i++)
	printf("%d ", v[i]);
    printf("\n");
}

//passou
void teste_constroi() {
    int v[] = {1, 5, 7, 6, 8, 9, 10, 12, 13, 15, 11, 14};
    int size = sizeof(v)/sizeof(v[0]);

    constroi_heap(v, size);
    print_array(v, size);
}

//passou
int teste_insere() {
    int v[15] = {1, 5, 7, 6, 8, 9, 10, 12, 13, 15, 11, 14};
    int max_size = sizeof(v)/sizeof(v[0]);
    int size = 12;

    constroi_heap(v, max_size);
    //20, 3, 18
    insere_elemento(v, 20, max_size, &size);

    printf("%d --> limite\n", max_size);
    print_array(v, size);
    printf("%d --> tamanho\n", size);
}

//passou
void teste_ordena() {
    int v[] = {1489, 38, 2448, 32, 28, 952, 5478};
    int size = sizeof(v)/sizeof(v[0]);

    constroi_heap(v, size);
    heap_sort(v, size);
    
    print_array(v, size);
}

//passou
void teste_extrai() {
    int v[] = {1, 5, 7, 6, 8, 9, 10, 12, 13, 15, 11, 14};
    int max_size = sizeof(v)/sizeof(v[0]);

    constroi_heap(v, max_size);

    extrai_max(v, &max_size);

    printf("%d --> max-size\n", max_size);
    print_array(v, max_size);
}

//passou
void teste_altera() {
    int v[] = {1, 5, 7, 6, 8, 9, 10, 12, 13, 15, 11, 14};
    int max_size = sizeof(v)/sizeof(v[0]);

    constroi_heap(v, max_size);

    altera_prioridade(v, 0, max_size, 4);

    print_array(v, max_size);
}

int main() {
    teste_constroi();
    teste_insere();
    teste_ordena();
    teste_extrai();
    teste_altera();

    return EXIT_SUCCESS;
}
