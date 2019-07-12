#include <stdio.h>
#include <stdlib.h>

int main() {
  int matriz[3][4] = {{ 1, 2, 3, 4}, { 5, 6, 7, 8}, { 9,10,11,12}};
  int * ptr;
  int (*ptr2vector)[4];
  //int fila, col;

  for (int i = 0; i < 3; i++) {
    ptr2vector  = matriz;
    ptr = ptr2vector[i];
    
    for (int j = 0; j < 4; j++) {
    printf("%d ", ptr[j]);
    }
  printf("\n");
  }
  
  return 0;
}

