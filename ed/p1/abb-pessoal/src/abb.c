#include "../include/abb.h"

void constroi_abb(Arv * arv, int (* cmp)(void *, void *), void (* printa)(void *)) {
	arv->raiz = NULL;
	arv->cmp = cmp;
	arv->printa = printa;
}

void insere_abb(Arv * arv, void * reg) {
	insere_node_abb(arv, &(arv->raiz), reg);
}

void insere_node_abb(Arv * arv, Node ** node, void * reg) {
	if(!(*node)) {
		*node = malloc(sizeof(Node));
		(*node)->reg = reg;
		(*node)->esq = NULL;
		(*node)->dir = NULL;
	}
	else if(arv->cmp((*node)->reg, reg) > 0) insere_node_abb(arv, &((*node)->esq), reg);
	else if(arv->cmp((*node)->reg, reg) < 0) insere_node_abb(arv, &((*node)->dir), reg);
}

void * busca_abb(Arv * arv, void * reg) {
	return busca_node_abb(arv, arv->raiz, reg);
}
void * busca_node_abb(Arv * arv, Node * node, void * reg) {
	Node * ret;

	if(!node) ret = NULL;
	else if(arv->cmp(node->reg, reg) > 0) busca_node_abb(arv, node->esq, reg);
	else if(arv->cmp(node->reg, reg) < 0) busca_node_abb(arv, node->dir, reg);
	else ret = node->reg;

	return ret;
}
//int remove_abb(Arv * arv, void * reg);
//int remove_node_abb(Arv * arv, Node * node, void * reg);

void libera_abb(Arv * arv) {
	libera_node_abb(arv->raiz);
}

void libera_node_abb(Node * node) {
	if(node) {
		libera_node_abb(node->esq);
		libera_node_abb(node->dir);
		free(node->reg);
		free(node);
	}
}

void printa_abb(Arv * arv) {
	printa_node_abb(arv, arv->raiz);
}

void printa_node_abb(Arv * arv, Node * node) {
	if(node) {
		printa_node_abb(arv, node->esq);
		arv->printa(node->reg);
		printa_node_abb(arv, node->dir);
	}
}
