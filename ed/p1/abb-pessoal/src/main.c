#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.c"

typedef struct {
	int rg;
	char nome[50];
} Pessoa;

void * aloca_pessoa(int rg, char * nome) {
	Pessoa * pes = malloc(sizeof(Pessoa));
	pes->rg = rg;
	strcpy(pes->nome, nome);

	return pes;
}

int compara_rg(void * pes1, void * pes2) {
	return ((Pessoa *) pes1)->rg - ((Pessoa *) pes2)->rg; 
}

void printa_pessoa(void * pes) {
	Pessoa * pessoa = (Pessoa *) pes;
	printf("RG: %d\n", pessoa->rg);
	printf("Nome: %s\n", pessoa->nome);
	printf("\n");
}

void teste() {
	Arv arv;
	constroi_abb(&arv, compara_rg, printa_pessoa);
	insere_abb(&arv, aloca_pessoa(2730862, "Lincoln Lima"));
	insere_abb(&arv, aloca_pessoa(2730862, "Lincoln Lima"));
	insere_abb(&arv, aloca_pessoa(2730869, "Kung Lao"));
	insere_abb(&arv, aloca_pessoa(2730861, "Liu Kang"));
	insere_abb(&arv, aloca_pessoa(2730870, "Ben 10"));
	printa_abb(&arv);

	libera_abb(&arv);
}

int main() {
	teste();

	return EXIT_SUCCESS;
}
