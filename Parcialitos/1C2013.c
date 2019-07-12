#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

bool es_primo(int n) {
  int i = 1, divisores = 0;
  
  for (; i <= n; i++) 
    if (n % i == 0)
      divisores++;
      
  if (divisores == 2)
    return true;
      
  return false;
}


int main(void) {
  char numEntero[MAX];
  
  printf("Inserte un número entero: ");
  fgets(numEntero, MAX, stdin);
  int n = atoi(numEntero);
  
  printf("\nEl número ");
  es_primo(n) ? printf("%d es primo.", n) : printf("%d no es primo.", n);
  
  return 0;
}
