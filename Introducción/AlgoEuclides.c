#include <stdio.h>
#include <stdlib.h>

#define MAX 8

int algoritmo_euclides(int m, int n) {
  int r;
  
  r = m % n;
  
  while(r) {
    m = n;
    n = r;
    r= m % n;
  }
  
return n;
}


int main(void) {
  char numEnteros[MAX];
  int a, b, f;
  
  printf("Cálculo del MCD entre dos números enteros positivos.\n");
  
  printf("Inserte un número: ");
  fgets(numEnteros, MAX, stdin);
  a = atoi(numEnteros);
  
  printf("Inserte un segundo número: ");
  fgets(numEnteros, MAX, stdin);
  b = atoi(numEnteros);
  
  f = algoritmo_euclides(a, b);
  
  printf("El MCD de %d y %d es %d", a, b, f);
  
  return 0;
}
  
