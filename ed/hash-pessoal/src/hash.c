#include <stdlib.h>
#include <string.h>
#include "../include/hash.h"

#define SEED 0x12345678

uint32_t hashing_function(char * str, uint32_t h);
int insere(thash * hash, void * bucket);
void * busca(thash * hash, char * key);
int constroi(thash * hash, int n_buckets, char * (* get_key)(void *));
int remove(thash * hash, char * key);
void apaga(thash * hash);
