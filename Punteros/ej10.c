#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool veccpy(double *dest, size_t ldest, const double *orig, size_t lorig) {
  
  for (int i = 0; i < lorig;i ++)
    dest[i] = orig[i];
    
  return true;
}

bool son_iguales(double *v1, size_t lv1, double *v2, size_t lv2) {
  if (lv1 != lv2)
    return false;
  
  for (int i = 0; i < lv1; i++) {
    if (v1[i] != v2[i])
      return false;
  }
  
  return true;
}

int main() {
  const double orig[] = {1, 2, 3, 4, 5, 6, 7, 8};
  double dest[] = {1, 5, 6, 9, 6}; 
  size_t lorig = sizeof(orig) / sizeof (orig[0]);
  size_t ldest = sizeof(dest) / sizeof(dest[0]);
  
  
  if (veccpy(dest, ldest, orig, lorig)) {
    for (int i = 0; i < lorig; i++)
      printf("%f ", dest[i]);
  }
  
  double v1[] = {1234, 5678, 9};
  double v2[] = {1234, 5678, 9};
  
  printf("\nLos vectores%s son iguales", son_iguales(v1, 3, v2, 3) ? "" : " no");
  
  return 0;
}
