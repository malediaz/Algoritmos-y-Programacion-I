#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char * invertir(char * c) {
  char aux[MAX];
  size_t n = strlen(c);
  strcpy(aux, c);
  
  for (int i = 0; i < n; i++)
    c[i] = aux[n - 1 - i];    
  
  return c;
}

int main(void) {
  char cadena[MAX];

  strcpy(cadena, "Male estas loca ");

  printf("%s\n", cadena);
  invertir(cadena);
  
  printf("%s", cadena);
  
  return 0;
}
