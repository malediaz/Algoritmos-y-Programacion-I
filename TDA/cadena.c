#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_CADENA 100

struct cadena {
  char cad[MAX_CADENA];
  size_t largo;
};

typedef struct cadena cadena_t;

cadena_t *cadena_crear(const char *str) {
  cadena_t *cad = malloc(sizeof(cadena_t));
  
  if (cad == NULL)
    return NULL;
  
  strcpy(cad->cad, str);
  cad->largo = strlen(str);
  
  return cad;
}

void cadena_destruir(cadena_t *cad) {
  free(cad);
}

cadena_t *cadena_copiar(cadena_t *dest, const cadena_t *orig) {
  dest = malloc(sizeof(cadena_t));
  
  if (dest == NULL)
    return NULL;
    
  *dest = *orig;
  
  return dest;
}

cadena_t *cadena_clonar(const cadena_t *cad) {
  cadena_t *clon = malloc(sizeof(cadena_t));
  
  if (clon == NULL)
    return NULL;
    
  *clon = *cad;
  
  return clon;
}

cadena_t *cadena_concatenar(cadena_t *dest, const cadena_t *orig) {
  cadena_t *aux = malloc(sizeof(cadena_t));
  
  if (aux == NULL)
    return NULL;
  
  strcpy(aux->cad, dest->cad);
  strcat(aux->cad, orig->cad);
  aux->largo = strlen(aux->cad);
  
  return aux;
}

cadena_t *cadena_strcpy(cadena_t *dest, const char *orig) {
  dest = malloc(sizeof(cadena_t));
  
  if (dest == NULL)
    return NULL;
    
  strcpy(dest->cad, orig);
  dest->largo = strlen(orig);
  
  return dest;
}

cadena_t *cadena_strcat(cadena_t *dest, const char *str) {
  dest = malloc(sizeof(cadena_t));
  
  if (dest == NULL)
    return NULL;
  
  strcat(dest->cad, str);
  dest->largo = strlen(dest->cad);
  
  return dest;
}

int main() {
  cadena_t *string = cadena_crear("HOLA");
  cadena_t *copia = NULL;
  copia = cadena_copiar(copia, string);
  
  cadena_t *concatenada;
  concatenada = cadena_concatenar(copia, string);
  
  printf("%s\n", concatenada->cad);
  
  return 0;
}


