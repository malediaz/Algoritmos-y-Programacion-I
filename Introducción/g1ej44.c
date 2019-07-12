#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main(void) {
  int c, nl = 0;
  
  printf("Ingrese un texto a elección:\n");
  
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      nl++;
    }
    
  printf("____\nLa cantidad de saltos de lineas que contiene el texto es de %d\n",nl);
  
  return 0;
}
