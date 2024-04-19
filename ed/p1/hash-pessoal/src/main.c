#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.c"

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

void teste() {
    thash tabela;
    int n_buckets = 10;
    int status;

    status = constroi(&tabela, n_buckets, get_key_pessoa);

    if(status == EXIT_SUCCESS)
        printf("constroi passou\n");

    tpessoa * pessoa = aloca_pessoa("kung lao", "498.589.739-47");

    if(pessoa != NULL)
	printf("alocação passou\n");
    
    status = insere(&tabela, pessoa);

    if(status == EXIT_SUCCESS)
	printf("insere passou\n");

    tpessoa * pessoa_busca = busca(&tabela, "498.589.739-47");
    
    if(pessoa_busca != NULL)
	printf("busca passou --> %s\n", pessoa_busca->nome);

    status = remover(&tabela, "498.589.739-47");

    if(status == EXIT_SUCCESS)
        printf("remover passou\n");
    
    apaga(&tabela);

    printf("apagar passou\n");
}

int main() {
    teste();

    return EXIT_SUCCESS;
}
