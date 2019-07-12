#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(void) {
  size_t i = 0;
  char c;
  
  printf("Ingrese una oración: ");
  
  while ((c = getchar()) != EOF)
    i++;
    
  printf("La cadena contiene %ld caracteres", i);
  
  return 0;
}
