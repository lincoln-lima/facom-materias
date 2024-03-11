#include<stdio.h>
#include<stdlib.h>

/*
 * codigo que demonstra aritmetica de ponteiros
 * para acesso em outras variaveis
*/
int main() {
	int i, *p = &i, b = 7;

	printf("i = %p\n", &i);
	printf("p = %p\n", &p);
	printf("b = %p\n", &b);

	p -= 4;
	
	printf("\n");
	printf("p = %p\n", p);
	printf("p = %p\n", &p);
	printf("p = %d\n", *p);
	
	*p = 8;
	printf("\n");
	printf("b = %d\n", b);

	return EXIT_SUCCESS;
}
