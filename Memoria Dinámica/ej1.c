#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *strcopy(const char *cadena) {
  char *copia;
  copia = (char *)malloc(sizeof(cadena)/sizeof(cadena[0]));
  
  if (copia == NULL)
    return copia;
  
  int i = 0;
  for (; cadena[i] != '\0'; i++)
    copia[i] = cadena[i];
    
  copia[i] = '\0';
  
  return copia;
}

int *arraycopy(const int *vector) {
  int *copia;
  copia = malloc(sizeof(vector)/sizeof(vector[0]));
  
  if (copia == NULL)
    return copia;
    
  int i = 0;
  for (; vector[i] != '\0'; i++)
    copia[i] = vector[i];
    
  copia[i] = '\0';
  
  return copia;
}

bool strcopy_i(const char *cadena) {
  char *copia = strcopy(cadena);
  
  if (copia == NULL)
    return false;
    
  else {
    printf("%s", copia);
    return true;
  }
  return false;
}

bool copia_arreglo_interfaz(const int *vector) {
  int *copia;
  copia = arraycopy(vector);
  
  if (copia == NULL)
    return copia;
    
  else {
    for (int i = 0; copia[i] != '\0'; i++)
      printf("%d, ", copia[i]);
    
    return true;
  }
  return false;
}



/*int main(void) {
  const char *nombre = "Malena";
  const int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  char *str = NULL;
  int *array = NULL;
  
  printf("Copia retornando el nombre:\n");
  printf("%s\n\n", strcopy(nom));
  
  printf("Retorno en interfaz:\n");
  copia_rpor_interfaz(mi_nombre);
  
  free(copia_mi_nombre);
  
  printf("\n\nCopiado del arreglo:\n");
  copia_mi_arreglo = copia_arreglo(mi_arreglo);
  
  for (int i = 0; copia_mi_arreglo[i] != '\0'; i++)
    printf("%d, ", copia_mi_arreglo[i]);
  
  printf("\n\nRetorno en interfaz:\n");
  copia_arreglo_interfaz(mi_arreglo);
  
  free(copia_mi_arreglo);
  
  return 0;
}
*/
