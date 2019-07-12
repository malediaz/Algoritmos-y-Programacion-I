#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 2000

void promedio(int n[], int i) {
   int s = n[0];
   
   for (int j = 1; j < i; j++) 
     s = s + n[j];
  
  printf("\nEl promedio de las %d notas es de %f", i, (float)s / i);
}

int main(void) {
  char notas[MAX];
  int num_notas[MAX];
  int a = 0, i = 0;
  
  while (true) {
    if (a == -1)
      break;
      
    for (; a != -1; i++) {
      printf("Ingrese una nota del 0 al 100 (-1 para terminar): ");
      fgets(notas, MAX, stdin);
        a = atoi(notas);
      
      if (a >= 0 && a <= 100) {
      num_notas[i] = a;
      
      }
      
      if ((a < 0 || a > 100) && a != -1) {
      printf("No es una nota válida.\n");
      i--;
      }
      
    }
  }
  promedio(num_notas, i - 1);

  return 0;
}
    
  
  
  
  
