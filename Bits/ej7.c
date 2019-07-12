#include <stdio.h>

#define MASK 0x08


int main() {
  //Elijo un número random
  unsigned char orig = 167;            // Su representación en binario es 1010_0_111
  unsigned char dest = 0;                                              // 1001_1_101
  
  // Quiero obtener el número binario 10011101 que es 157 en base 10
  
  // Seteo los 1s
  dest = orig | MASK | (MASK << 1);
  
  // Seteo los 0s
  dest = dest & ~(MASK << 2) & ~(MASK >> 2);
  
  printf("Orígen: %d \nDestino: %d", orig, dest);
  
  return 0;  
}
