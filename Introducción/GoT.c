#include <stdio.h>
#include <stdlib.h>

#define MAX 8

void casas(char c);


int main(void) {
  char c[MAX];
  
  printf("Inserte la primer letra (en mayúscula) de una casa de Game of Thrones: ");
  fgets(c, MAX, stdin);
  
  casas(*c);
  
  return 0;
}
  
void casas(char c) {
  if (c == 'A')
    printf("House Arryn");
  if (c == 'B')
    printf("House Baratheon");
  if (c == 'F')
    printf("House Frey");
  if (c == 'G')
    printf("House Greyjoy");
  if (c == 'L')
    printf("House Lannister");
  if (c == 'M')
    printf("House Martell");
  if (c == 'S')
    printf("House Stark");
  if (c == 'T')
    printf("House Targaryen");
  if (c != 'A' && c != 'B' && c != 'F' && c != 'G' && c != 'L' && c != 'M' && c != 'S' && c != 'T')
    printf("No lo conozco");
}
