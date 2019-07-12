#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 30

bool estan_ordenados(char *vec1, size_t lvec1, const char *vec2) {
  for (size_t i = 0; i < lvec1; i++) {
    if (vec1[i] != vec2[i]) {
      if (vec1[i] != '\0' && vec2[i] == '\0')
        return false;
      
      if (vec1[i] < vec2[i])
        return true;
      else 
        break;
    }
      
    if (vec1[i] == vec2[i]) {
      if (vec1[i] == '\0')
        return true;
    }
  }

return false;
}

int main(void) {
  char vec1[] = "MALENAA";
  const char vec2[] = "MALENA";

  size_t lvec1 = sizeof(vec1);
  bool r;
  int r2;
  
  r = estan_ordenados(vec1, lvec1, vec2);
  
  printf("Mi función:\n\t");
  
  if (r)
    printf("Están ordenados.\n");
  else
    printf("No están ordenados.\n");
    
  r2 = strcmp(vec1, vec2);
  
  printf("\nFunción strcmp():\n\t");
  
   if (r2 > 0)
    printf("No están ordenados.");
   if (r2 < 0)
    printf("Están ordenados.");
   if (r2 == 0)
    printf("Son iguales.");
    
  return r;
}
