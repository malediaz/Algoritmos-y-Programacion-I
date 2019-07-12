#include <stdlib.h>

typedef struct {
  double x;
  double y;
} complejo_t;


complejo_t *complejo_crear(double x, double y) {
  complejo_t *c = malloc(sizeof(complejo_t));
  
  if (c == NULL) 
    return NULL;
    
  c->x = x;
  c->y = y;
  
  return c;
}

void complejo_destruir(complejo_t *c) {
  free(c);
}

complejo_t *complejo_copiar(complejo_t *dest, const complejo_t *orig) {
  dest = malloc(sizeof(complejo_t));
  
  if (dest == NULL)
    return NULL;
    
  *dest = *orig;
  
  return dest;
}

complejo_t *complejo_clonar(const complejo_t *c) {
  complejo_t *clon = malloc(sizeof(complejo_t));
  
  if (clon == NULL)
    return NULL;
    
  *clon = *c;
  
  return clon;
}

double complejo_get_real(const complejo_t *c) {
  return c->x;
}

double complejo_get_imag(const complejo_t *c) {
  return c->y;
}

double complejo_set_real(complejo_t *c, double x) {
  c->x = x;
  
  return x;
}

double complejo_set_imag(complejo_t *c, double y) {
  c->y = y;
  
  return y;
}

complejo_t *complejo_conjugar(complejo_t *c) {
  c->y = -c->y;
  
  return c;
}

