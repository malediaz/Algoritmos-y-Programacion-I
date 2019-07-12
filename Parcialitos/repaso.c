#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50

bool es_palindromo(char palabra[], size_t tam) {
  size_t limite = tam - 1;
  for (int i = 0; i < tam / 2; i++) {
    if (palabra[i] == palabra[limite - i])
      continue;
    
    return false;
    }
    
  return true;
}

int main(void) {
  char palabra[MAX];
  strcpy(palabra, "NEUQUEN");
  
  size_t largo = strlen(palabra);
  
  es_palindromo(palabra, largo) ? printf("%s es palíndromo.", palabra) : printf("%s no es palíndromo.", palabra);
  
  return 0;
}
