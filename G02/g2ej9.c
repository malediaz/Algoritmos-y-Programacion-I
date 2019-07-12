#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool veccpy(double dest[], size_t ldest, double orig[], size_t lorig) {
  double aux[lorig];
  
  if (ldest == lorig) {
    for (int i = 0; i < lorig; i++)
      aux[i] = orig[i];
    
    for (int i = 0; i < ldest; i++)
      orig[i] = dest[i];
    
    for (int i = 0; i < lorig; i++)
      dest[i] = aux[i];
      
    return true;
  }
    
  return false;
  }

int main(void) {
  size_t ldest = 6, lorig = 6;
  double orig[] = {0, 1, 2, 3, 4};
  double dest[] = {5, 6, 7, 8, 9, 10};
  
  if (veccpy(dest, ldest, orig, lorig)) {
      
    printf("Vector orígen: \n{");
  
    for(int i = 0; i < lorig; i++) 
      printf("%f, ", orig[i]);
    printf("}\n");
  
    printf("Vector destino: \n{");
  
    for(int i = 0; i < ldest; i++) 
      printf("%f, ", dest[i]);
    printf("}");
  }
   
   else
    printf("La dimensión de los vectores no es la misma.");
    
  return true;
}
