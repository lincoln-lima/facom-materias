#ifndef __HEAP__
#define __HEAP__
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int size;
	void ** vector;
} theap;

int pai(int n);
int f_esq(int n);
int f_dir(int n);
void troca(int *a, int *b);
void desce(int v[], int pos, int max_size);
void sobe(int v[], int pos);
int acessa_max(int v[]);
void constroi_heap(int v[], int max_size);
int extrai_max(int v[], int *size);
int insere_elemento(int v[], int new_element, int max_size, int *size);
void altera_prioridade(int v[], int pos, int max_size, int value);
void heap_sort(int v[], int max_size);
#endif
