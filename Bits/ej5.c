#include <stdio.h>

int main() {
  unsigned int num = 271590900;
  unsigned char aux[5];
  
  printf("Orígen:\n");
  
  for (size_t i = 0; i < 4; i++) {
    aux[i] = (num >> ((3 - i) * 8)) & 0xFF;
    printf("X[%zd] = 0x%X\n", i, aux[i]);
  }
  
  unsigned int destino = 0;
  
  for (size_t i = 0; i < 4; i++) 
    destino += (aux[i] << ((3 - i) * 8));
  
  printf("\nDestino: %d", destino);
  
  return 0;
}
