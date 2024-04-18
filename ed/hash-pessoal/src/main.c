#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/hash.h"

typedef struct {
    char nome[30];
    char cpf[11];
} tpessoa;

char * get_key_pessoa(void * pes) {
    return (*((tpessoa *) pes)).cpf;
}

void * aloca_pessoa(char * nome, char * cpf) {
    tpessoa * pessoa = malloc(sizeof(tpessoa));
    
    strcpy(pessoa->nome, nome);
    strcpy(pessoa->cpf, cpf);

    return pessoa;
}

void teste_insere() {
    thash tabela;
    int n_buckets = 10;

    constroi(&tabela, n_buckets, get_key_pessoa);

    assert(insere(&tabela, aloca_pessoa("kung lao", "897.456.135.48"))==EXIT_SUCCESS);
}

int main() {
    teste_insere();

    return EXIT_SUCCESS;
}
