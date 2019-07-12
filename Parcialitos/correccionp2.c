#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

struct alumno {
  char nombre[MAX];
  unsigned int padron;
  float promedio;
};

typedef struct alumno alumno_t;


bool alumno_son_iguales(const alumno_t *a, const alumno_t *b) {
  return a->padron == b->padron && 
         strcmp(a->nombre, b->nombre) == 0 && 
         a->promedio == b->promedio;
}

//------------------------------------------------------------------

typedef struct {
  float *v;
  size_t n;
} vector_t;

vector_t *vector_crear(const float vals[], size_t n) {
  vector_t *v = malloc(sizeof(vector_t));
  
  if (v == NULL)
    return NULL;
  
  v->v = malloc(sizeof(float) * n);
  
  for (size_t i = 0; i < n; i++)
    v->v[i] = vals[i];
    
  v->n = n;
  
  return v;
}

void vector_destruir(vector_t *v) {
  free(v->v);
  free(v);
}

//---------------------------------------------------------------------

bool leer_enteros(int **pv, size_t *n) {
  char aux[MAX];
  int *v = NULL;
  size_t i = 0;
  *n = 0;
  
  while (fgets(aux, MAX, stdin) != NULL) {
    v = realloc(*pv, sizeof(int) * (i + 1));
    if (v == NULL)
      return false;
      
    v[i] = atoi(aux);
    *pv = v;
    
    i++;
  }
  
  *n = i;
  
  return true;
}

int main() {
  int *pv = NULL;
  size_t n;
  
  leer_enteros(&pv, &n);
  
  for (size_t i = 0; i < n; i++)
    printf("%d\n", pv[i]);
  
  return 0;
}
