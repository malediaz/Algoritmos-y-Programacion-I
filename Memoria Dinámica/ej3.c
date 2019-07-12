#include <stdio.h>
#include <stdlib.h>

char *cortar_sobrante(char *cadena, char caracter) {
  int posicion = 0, i = 0;
  char *copia = NULL;
  
  while (cadena[posicion] != caracter)
    posicion++;
    
  copia = malloc(sizeof(char) * posicion);
  
  for (; i < posicion; i++)
    copia[i] = cadena[i];
    
  copia[i] = '\0';
  
  return copia;
}

int main(void) {
  char *mensaje = "Esto va, esto no va.";
  char terminador = ',';
  char *msj_cortado = NULL;
  msj_cortado = cortar_sobrante(mensaje, terminador);
  
  printf("%s", msj_cortado);
  
  free(msj_cortado);
  
  return 0;
}
