#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(void) {
  char cadena[MAX];
  int dia = 9;
  
  sprintf(cadena, "Hola buen día, hoy es %d de abril", dia);
  
  printf("%s", cadena);
  
  return 0;
}
