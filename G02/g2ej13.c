#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int busqueda_lineal(const int v[], size_t n, int objetivo) {
  for (size_t i = 0; i < n; i++) {
    if (v[i] == objetivo)
      return i;
  }
  return n;
}

int main(void) {
  const int v[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  char numero[MAX];
  size_t n = sizeof(v);
  int obj, r;
  
  printf("Inserte un valor a buscar: ");
  fgets(numero, MAX, stdin);
  obj = atoi(numero);
  
  r = busqueda_lineal(v, n, obj);
  
  if (r >= 0 && r < n)
    printf("El número se encuentra en la posición v[%d].", r);
  else
    printf("El número no se encuentra en el vector.");
    
  return 0;
}
