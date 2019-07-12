#include <stdio.h>
#include <string.h>

#define MAX 100
#define N 4

void insertar_frase(char cad1[], char cad2[], int posicion) {
  int j = 0, i = 0;
  char aux[MAX];
  size_t s1, s2;
  
  s1 = strlen(cad1);
  s2 = strlen(cad2);
  
  strcpy(aux, cad1);
  
  if (posicion < 0 || posicion > s1 + s2)
    printf("Error.\n");
    
  else {
    for (j = 0; aux[posicion + j] != '\0'; j++)
      cad1[posicion + s2 + j] = aux[posicion + j];
    
    cad1[posicion + s2 + j] = '\0';

    for (i = 0; i < s2; i++)
      cad1[posicion + i] = cad2[i];
      
    printf("%s\n", cad1);
  }
}

int main(void) {
  char cad1[MAX];
  char cad2[MAX];
  
  strcpy(cad1, "Hola estas");
  strcpy(cad2, " como");
  
  insertar_frase(cad1, cad2, N);
    
  return 0;
}
