#include <stdio.h>
#include <string.h>

#define MAX 100

char * strlower(char * c) {
  size_t lc = strlen(c);
  for (int i = 0; i < lc; i++)
    c[i] = c[i] + 32;

  return c;
}

char * strupper(char * c) {
  size_t lc = strlen(c);
  for (int i = 0; i < lc; i++)
    c[i] = c[i] - 32;

  return c;
}


int main(void) {
  char cadena1[MAX], cadena2[MAX];
  
  strcpy(cadena1, "mayuscula");
  strupper(cadena1);
  
  printf("%s\n", cadena1);
  
  strcpy(cadena2, "MINUSCULA");
  strlower(cadena2);
  
  printf("%s", cadena2);
  
  return 0;
}
