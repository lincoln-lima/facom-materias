#include <stdlib.h>
#include <string.h>
#include "../include/hash.h"

#define SEED 0x12345678

//funcao especifica de has
uint32_t hashing_function(char * str, uint32_t h) {
    /*
     * One-byte-at-a-time Murmur hash
     * Source: https://github.com/aappleby/smhasher/blob/master/src/Hashes.cpp
    */
    for (; *str; ++str) {
        h ^= *str;
        h *= 0x5bd1e995;
        h ^= h >> 15;
    }
    return h;
}

int insere(thash * hash, void * bucket) {
    int pos = hashing_function(hash->get_key(bucket), SEED) % hash->max_size;
    int ret;

    //checagem se o array da tabela está cheio
    if(hash->size == hash->max_size) {
	free(bucket);
	ret = EXIT_FAILURE;
    }
    else {
	//garante que a posição para alocação da estrutura esteja desocupada
        while(hash->array[pos] != 0 || hash->array[pos] != hash->deleted)
	    pos = (pos+1) % hash->max_size;
	    // sondagem linear dos elementos
        
	//armazena ponteiro para o bucket específico
        hash->array[pos] = (uintptr_t) bucket;
        hash->size++;
	//acréscimo ao tamanho ocupado pelo vetor;

	ret = EXIT_SUCCESS;
    }

    return ret;
}

void * busca(thash * hash, char * key) {
    int pos = hashing_function(key, SEED) % hash->max_size;

    //criação do objeto para retorno
    void * ret = NULL; 

    while(hash->array[pos] != 0 && ret == NULL) {
	if(strcmp(hash->get_key((void *) hash->array[pos]), key) == 0)
	    ret = (void *) hash->array[pos];
	else
	    pos = (pos+1) % hash->max_size;
    }

    return ret;
}

int constroi(thash * hash, int n_buckets, char * (* get_key)(void *)) {
    int ret;
    //aloca espaco para array da tabela
    hash->array = calloc(sizeof(void *), n_buckets + 1);

    //em caso de falha na alocação
    if(hash->array == NULL)
        ret = EXIT_FAILURE;
    else {
	//inicialização dos parâmetros necessários
	hash->size = 0;
	hash->max_size = n_buckets + 1;
	hash->deleted = (uintptr_t) &(hash->size);
	hash->get_key = get_key;

	ret = EXIT_SUCCESS;
    }

    return ret;
}

//remove elemento específico
int remover(thash * hash, char * key) {
    int ret = EXIT_FAILURE;
    int pos = hashing_function(key, SEED) % hash->max_size;

    //caso determinada posição esteja nula, o elemento não deve existir
    while(hash->array[pos] != 0) {
	//compara a chave do registro com a chave informada na chamada da função
        if(strcmp(hash->get_key((void *) hash->array[pos]), key) == 0) {
	    //diminui tamanho ocupado, libera a posição e diz que a mesma foi deletada
	    hash->size--;
	    free((void *) hash->array[pos]);
	    hash->array[pos] = hash->deleted;
	    ret = EXIT_SUCCESS;
	}
        else
            pos = (pos+1) % hash->max_size;
    }

    return ret;
}

//elimina todos os registros da tabela
void apaga(thash * hash) {
   //libera posição a posição do array
   for(int pos = 0; pos < hash->max_size; pos++)
      free((void *) hash->array[pos]);

   //libera o array
   free(hash->array);
}
