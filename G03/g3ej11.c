#include <stdio.h>
#include <string.h>

#define MAX 100

size_t strlen1(const char * c) {
  int i = 0;
  for (; c[i] != '\0'; i++);
  
  return i;
}

char * strcpy1(char * dest, const char * orig) {
  size_t i = 0;
  for (; orig[i] != '\0'; i++)
    dest[i] = orig[i];
  dest [i] = '\0';
  
  return dest;
}

char * strncpy1(char * dest, const char * orig, size_t n) {
  int i = 0;
  for (; i < n; i++)
    dest[i] = orig[i];
  dest[i] = '\0';
  
  return dest;
}

int strcmp1(const char * s1, const char * s2) {
  int i = 0;
  while (1) {
    for (; s1[i] != s2[i]; i++) {
      if (s1[i] > s2[i] || s2[i] == '\0')
        return 1;
     
      if (s1[i] < s2[i] || s1[i] == '\0')
        return -1;
    }
  
    for (; s1[i] == s2[i]; i++) {
      if (s2[i] == '\0')
        return 0;
    }
  }
  
  return 0;
}

int strncmp1(const char * s1, const char * s2, size_t n) {
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      if (s1[i] > s2[i] || s2[i] == '\0')
        return 1;
     
      if (s1[i] < s2[i] || s1[i] == '\0')
        return -1;
    }
  
    if (s1[i] == s2[i]) {
      if (s2[i] == '\0')
        return 0;
    }
  }
  
  return 0;
}

char * strcat1(char * dest, const char * orig) {
  for (int j = 0; orig[j] != '\0'; j++) {
    if (dest[j] == '\0') {
      int i = 0, k = j;
      while (orig[i] != '\0'){
        dest[k] = orig[i];
        i++;
        k++;
      }
      dest[k] = '\0';
    }
  }
  
  return dest;
}


int main(void) {
  char cadena[MAX];
  char orig[MAX] = "Malena Diaz Falvo";
  const char s1[MAX] = "Malena A";
  fgets(cadena, MAX, stdin);
  
  printf("Largo de la cadena: %ld. \n", strlen1(cadena));
  
  strcpy1(cadena, orig);
  puts(cadena);
  
  strncpy1(cadena, orig, 9);
  puts(cadena);
  
  printf("%3d\n", strcmp1(s1, orig));
  
  printf("%3d\n", strncmp1(s1, orig, 2));
  
  puts(strcat1(cadena, orig));
  
  
  return 0;
}
