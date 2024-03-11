#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int pai(int n) {
	return (n-1)/2;
}

int filho_esq(int n) {
	return 2*n+1;
}

int filho_dir(int n) {
	return 2*n+2;
}

void troca(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void desce(int v[], int n, int tam) {
	int fesq, fdir, waybig;
	fesq = filho_esq(n);
	fdir = filho_dir(n);
	waybig = n;

	if (fesq < tam && v[fesq] > v[waybig]) waybig = fesq;
	if (fdir < tam && v[fdir] > v[waybig]) waybig = fdir;
	if (waybig != n) {
		troca(&v[waybig], &v[n]);
		desce(v, waybig, tam);
	}
}

void constroi_heap(int v[], int tam) {
	int i;
	for(i = pai(tam-1); i >= 0; i--) desce(v, i, tam);
}

void test_pai() {
	/*inicializacao*/
	int r;
	/*chamada*/
	/*verificacao*/
	r = pai(6);
	assert(r == 2);
	r = pai(5);
	assert(r == 2);
	r = pai(0);
	assert(r == 0);
}

void test_filho_esq() {
	/*inicializacao*/
	int r;
	/*chamada*/
	/*verificacao*/
	r = filho_esq(0);
	assert(r == 1);
	r = filho_esq(1);
	assert(r == 3);
	r = filho_esq(2);
	assert(r == 5);
}

void test_filho_dir() {
	/*inicializacao*/
	int r;
	/*chamada*/
	/*verificacao*/
	r = filho_dir(0);
	assert(r == 2);
	r = filho_dir(1);
	assert(r == 4);
	r = filho_dir(2);
	assert(r == 6);
} 

void test_desce() {
	int entrada[7] = {1, 5, 3, 4, 10, 2, 0};
	int saida[7] = {5, 10, 3, 4, 1, 2, 0};
	/*implementar funcao de tamanho do vetor*/
	desce(entrada, 0, 7);
	/*fazer um for com assert para comparar a entrada e a saida esperada*/
	assert(entrada[1] == 10);
}

void test_constroi_heap() {
	int entrada[] = {1, 50, 20, 62, 60, 25, 30};
	int saida[]   = {62, 60, 30, 50, 1, 25, 20};
	int tam = sizeof(entrada)/sizeof(entrada[0]);

	constroi_heap(entrada, tam);

	assert(entrada[0] == 62);	
}

int main() {
	test_constroi_heap();

	return EXIT_SUCCESS;
}
