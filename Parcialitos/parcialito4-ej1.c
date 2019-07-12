#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *e;
  size_t n;
} conjunto_t;

conjunto_t *conjunto_interseccion(const conjunto_t *a, const conjunto_t *b) {
  conjunto_t *c = conjunto_crear();
  
  size_t i = 0, j = 0;
  
  while (i < a->n && j < b->n) {
    if (a->e[i] == b->e[j])
      agregar_al_final(c, a->e[i]);
      
    else {
      if (a->e[i] < b->e[j]) 
        i++;
      
      else
        j++;
    }
  }
  
  return c;  
}

conjunto_t *conjunto_union(const conjunto_t *a, const conjunto_t *b) {
  conjunto_t *c = conjunto_crear();
  size_t i = 0, j = 0;
  
  while (i < a->n && j < b->n) {
    if (a->e[i] < b->e[j]) {
      agregar_al_final(c, a->e[i]);
      i++;
    }
    
    else {
      if (a->e[i] > b->e[j]) {
        agregar_al_final(c, b->e[j]);
        j++;
      }
      
      else {
        agregar_al_final(c, a->e[i]);
        i++;
        j++;
      }
    }
  }
  
  return c;
}

