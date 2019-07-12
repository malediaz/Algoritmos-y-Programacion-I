#include <stdio.h>

int main() {
	unsigned char original = 0x00;
	unsigned char mascara = 0x01;
	unsigned char resultado;

	mascara = mascara << 1;
	resultado = original | mascara;
	printf("resultado = %d\n", resultado);

	mascara = mascara << 2;
	resultado = resultado | ~ mascara;
	printf("resultado = %d\n", resultado);

	mascara = mascara >> 1;
	resultado = resultado ^ mascara;
	printf("resultado = %d\n", resultado);

	return 0;

}

