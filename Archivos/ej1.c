#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CADENA 9999

char *readline(FILE *fp){
  char *line = NULL;
  char aux[MAX_CADENA];
  
  if (fgets(aux, MAX_CADENA, fp) == NULL) 
    return NULL;
  
  line = aux;
  
  return line;
}

char *readline_g(FILE *fp){
  char c, *aux = NULL;
  int i = 0;
  
  while ((c = fgetc(fp)) != EOF) {
    aux = realloc(aux, sizeof(char) * (i + 1));
    
    if (aux == NULL)       
      return NULL;
    
    aux[i++] = c;
  }
  
  return aux;
}

bool readline_bool(FILE *fp, char **line) {
  char aux[MAX_CADENA];

  if (fgets(aux, MAX_CADENA, fp) != NULL) {
    *line = aux;
  
    return true;
  }
  
  return false;
}

bool readline_bool_g(FILE *fp, char **line) {
  char *aux = NULL;
  int c;
  size_t i = 0;
  
  while ((c = fgetc(fp)) != EOF) {
    aux = realloc(aux, sizeof(char) * (i + 1));
    aux[i++] = c;
  }
  
  *line = aux;
  
  return true;
}


int main() {
  char *cadena = NULL;
  
  if(!readline_bool_g(stdin, &cadena))
    return 1;
  
  printf("%s", cadena);
  
  return 0;
}
