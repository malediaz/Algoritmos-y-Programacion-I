#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 30

bool son_iguales(int *vec1, size_t lvec1, int *vec2, size_t lvec2) {
  for (size_t i = 0; i < lvec1; i++) {
    if (vec1[i] != vec2[i])
      return false;
    }
  
  for (size_t i = 0; i < lvec2; i++) {
    if (vec2[i] != vec1[i])
      return false;
    }
return true;
}

int main(void) {
  typedef int tipoVec;
  size_t lvec1, lvec2;
  bool r;
  
  tipoVec vec1[] = {6, 5, 5, 9, 3, 5, 0, 7, 9, 1};
  tipoVec vec2[] = {6, 5, 5, 9, 3, 5, 0, 7, 9, 1, 0};
  
  lvec1 = sizeof(vec1);
  lvec2 = sizeof(vec2);
  
  r = son_iguales(vec1, lvec1, vec2, lvec2);
  
  if(r)
    printf("Son iguales.");
  else
    printf("No son iguales.");
  
  return r;
}
  
