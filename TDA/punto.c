#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct punto {
    double x;
    double y;
};


punto_t *punto_crear(double x, double y) {
  punto_t *p = malloc(sizeof(punto_t));
  
  if (p == NULL)
    return NULL;
    
  p->x = x;
  p->y = y;

  return p;
}

void punto_destruir(punto_t *p) {
  free(p);
}

punto_t *punto_copiar(punto_t *dest, const punto_t *orig) {
  dest = malloc(sizeof(punto_t));
  
  if (dest == NULL)
    return NULL;
    
  *dest = *orig;
  
  return dest;
}

punto_t *punto_clonar(const punto_t *p) {
  punto_t *clon = malloc(sizeof(punto_t));
  
  if (clon == NULL)
    return NULL;
  
  *clon = *p;
  
  return clon;
}

double punto_get_x(const punto_t *p) {
  return p->x;
}

double punto_get_y(const punto_t *p) {
  return p->y;
}

double punto_set_x(punto_t *p, double x) {
  p->x = x;
  
  return x;
}

double punto_set_y(punto_t *p, double y) {
  p->y = y;
  
  return y;
}

punto_t *punto_sumar(punto_t *p1, const punto_t *p2) {
  p1->x += p2->x;
  p1->y += p2->y;
  
  return p1;
}

punto_t *punto_restar(punto_t *p1, const punto_t *p2) {
  p1->x -= p2->x;
  p1->y -= p2->y;
  
  return p1;
}

double punto_distancia(const punto_t *p1, const punto_t *p2) {
  double distancia_x = p1->x - p2->x;
  double distancia_y = p1->y - p2->y;
  double distancia = sqrt(pow(distancia_x, 2) + pow(distancia_y, 2));
  
  return distancia;
}

double punto_norma(const punto_t *p) {
  return sqrt(pow(p->x, 2) + pow(p->y, 2));
}
