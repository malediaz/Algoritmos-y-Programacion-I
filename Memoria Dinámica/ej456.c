#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool left_trim(char *cadena) {
  size_t pos = 0, i = 0;
  size_t lcadena = strlen(cadena);
  char *copia = NULL;
  
  while (cadena[pos] == ' ')
    pos++;
    
  copia = malloc(sizeof(char) * (lcadena - pos));
  
  if (copia == NULL)
    return false;
    
  else {
    for (; pos < lcadena; pos++, i++)
      copia[i] = cadena[pos];
      
    copia[i] = '\0';
    
    printf("Cadena left trimmed: %s.", copia);
    
    return true;
  }
  
  return false;
}


bool right_trim(char *mensaje) {
  size_t lmensaje = strlen(mensaje);
  int i, pos = lmensaje;
  char *copia;
  
  while (mensaje[pos - 1] == ' ')
    pos--;
  
  copia = malloc(sizeof(char) * (pos + 1)); 
 
  if (copia == NULL)
    return false;
    
  else {
    copia[pos] = '\0';
  
    for (i = pos - 1; pos >= 0; i--, pos--)
      copia[i] = mensaje[pos - 1];
    
    printf("\nCadena right trimmed: %s.", copia);
    
    return true;
  }
    
  return false;
}

bool full_trim(char *mensaje) {
  size_t lcadena = strlen(mensaje);
  int pos_izquierda = 0, pos_derecha = lcadena - 1;
  int i = 0;
  char *copia = NULL;
  
  while (mensaje[pos_izquierda] == ' ')
    pos_izquierda++;
  
  while (mensaje[pos_derecha] == ' ')
    pos_derecha--;
    
  int fin_copia = pos_derecha - pos_izquierda;
  copia = malloc(sizeof(char) * (fin_copia + 1));
  
  if (copia == NULL)
    return false;
    
  else {
    copia[fin_copia] = '\0';
    
    for (i = 0; i < fin_copia + 1; i++, pos_izquierda++)
      copia[i] = mensaje[pos_izquierda];
      
    copia[i] = '\0';
    
    printf("\nCadena centrada: %s.", copia);
    
    return true;
  }
  
  return false;
}


int main(void) {
  char *mensaje0 = "       la izquierda     ";
  left_trim(mensaje0);
  
  char *mensaje1 = "     la derecha     ";
  right_trim(mensaje1); 
  
  char *mensaje2 = "     el centro      ";
  full_trim(mensaje2);
  
  return 0;
}
  
  
  
