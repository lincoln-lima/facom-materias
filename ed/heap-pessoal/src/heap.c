#include "../include/heap.h"

/* funcoes para encontrar pai e filhos, recebendo como parametro o indice do vetor  */
int pai(int n) {
    return (n-1)/2;
}

int f_esq(int n) {
    return (n*2)+1;
}

int f_dir(int n) {
    return (n*2)+2;
}

/* realiza a troca de valores de duas variaveis  */
void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

/* percorre os filhos em busca do valor maior  */
void desce(int v[], int pos, int max_size) {
    int e, d, max_value;

    /* guardando valores dos índices dos filhos e posição do maior valor  */
    e = f_esq(pos);
    d = f_dir(pos);
    max_value = pos;

    /* checagem de tamanho e se os filhos são maiores que o pai  */
    if(e < max_size && v[max_value] < v[e]) max_value = e;
    if(d < max_size && v[max_value] < v[d]) max_value = d;

    /* caso o pai não seja o maior valor, trocar com o filho */
    if(max_value!=pos) {
        troca(&v[pos],&v[max_value]);
	desce(v, max_value, max_size);
    }
}

/* percorre os pais a partir de um nó determinando se seu valor é menor que seu filho  */
void sobe(int v[], int pos) {
    while(v[pai(pos)] < v[pos]) {
        troca(&v[pai(pos)], &v[pos]);
       	pos = pai(pos);
    }
}

/* retorn o maior valor, como no caso da max_heap, está no índice 0 */
int acessa_max(int v[]) {
    return v[0];
}

/* percorre a partir do último pai da heap e engloba os demais nós a partir da função desce */
void constroi_heap(int v[], int max_size) {
    for(int i = pai(max_size-1); i>=0; i--) desce(v, i, max_size);
}

/* retorna extraindo o maior valor da heap, reajustando-a após tal */
int extrai_max(int v[], int *size) {
    int ret = acessa_max(v);
    
    *size -= 1;
    v[0] = v[*size];
    desce(v, 0, *size);

    return ret;
}

/* insere elemento na última posição e chama a função sobe para adequação do valor */
int insere_elemento(int v[], int new_element, int max_size, int *size) {
    int ret = EXIT_FAILURE;

    if(*size < max_size) {
	v[*size] = new_element;
	*size += 1;
	sobe(v, *size);
        ret = EXIT_SUCCESS;
    }

    return ret;
}

/* realiza a alteração de um valor do vetor e a partir de seu nó, reajusta a heap */
void altera_prioridade(int v[], int pos, int max_size, int value) {
    v[pos] = value;

    if(v[pos] > value) sobe(v, pos);
    else if(v[pos] < value) desce(v, pos, max_size);
}

/* troca o primeiro elemento com o último, posiciando o maior ao fim, assim ordenando o vetor */
void heap_sort(int v[], int max_size) {
    for(int i = max_size-1; i >= 0; i--) {
	troca(&v[i], &v[0]);
	max_size--;
	desce(v, i, max_size);
    }    
}