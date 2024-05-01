#ifndef __ABB__
#define __ABB__
typedef struct _node {
	void * reg;
	struct _node * esq;
	struct _node * dir;
} Node;

typedef struct {
	Node * raiz;
	int (* cmp)(void *, void *);
	void (* printa)(void *);
} Arv;

void constroi_abb(Arv * arv, int (* cmp)(void *, void *), void (* printa)(void *));
void insere_abb(Arv * arv, void * reg);
void insere_node_abb(Arv * arv, Node ** node, void * reg);
void * busca_abb(Arv * arv, void * reg);
void * busca_node_abb(Arv * arv, Node * node, void * reg);
//int remove_abb(Arv * arv, void * reg);
//int remove_node_abb(Arv * arv, Node * node, void * reg);
void libera_abb(Arv * arv);
void libera_node_abb(Node * node);
void printa_abb(Arv * arv);
void printa_node_abb(Arv * arv, Node * node);
#endif
