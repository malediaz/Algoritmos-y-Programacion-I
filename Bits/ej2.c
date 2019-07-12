#include <stdio.h>

int main() {
	unsigned int a = 0152, b = 0701, c = 0673, d = 067;
	unsigned int resultado;

	printf("a = %o\n", a);
	printf("b = %o\n", b);
	printf("c = %o\n", c);
	printf("d = %o\n", d);

	resultado = a << 1;
	printf("resultado = %o\n", resultado);

	resultado = b << 1;
	printf("resultado = %o\n", resultado);

	resultado = c << 1;
	printf("resultado = %o\n", resultado);

	resultado = d << 1;
	printf("resultado = %o\n", resultado);


	return 0;
}