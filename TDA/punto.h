#ifndef PUNTO_H
#define PUNTO_H

#include <stdio.h>

typedef struct punto punto_t;

punto_t *punto_crear(double x, double y);
void punto_destruir(punto_t *p);
punto_t *punto_copiar(punto_t *dest, const punto_t *orig);
punto_t *punto_clonar(const punto_t *p);
double punto_get_x(const punto_t *p);
double punto_get_y(const punto_t *p);
double punto_set_x(punto_t *p, double x);
double punto_set_y(punto_t *p, double y);
punto_t *punto_sumar(punto_t *p1, const punto_t *p2);
punto_t *punto_restar(punto_t *p1, const punto_t *p2);
double punto_distancia(const punto_t *p1, const punto_t *p2);
double punto_norma(const punto_t *p);

#endif // PUNTO_H
