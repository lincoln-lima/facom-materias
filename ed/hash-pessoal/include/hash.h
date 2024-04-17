#ifndef __HASH__
#define __HASH__
#include <stdint.h>
typedef struct {
    uintptr_t * array;
    int size;
    int max_size;
    uintptr_t deleted;
    char * (* get_key)(void *);
} thash;

uint32_t hashing_function(char * str, uint32_t h);
int insere(thash * hash, void * bucket);
void * busca(thash * hash, char * key);
int constroi(thash * hash, int n_buckets, char * (* get_key)(void *));
int remove(thash * hash, char * key);
void apaga(thash * hash);
#endif
