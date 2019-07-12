#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

typedef struct punto {
  float *coordenada_x;
  float *coordenada_y;
} punto_t;


float x[][2] = {
  {0, 0},
  {1, 1},
  {2, 2}
};

float y[][2] = {
  {2, 2},
  {1, 1},
  {0, 0}
};

punto_t *coordenadas[2] = {
  &x, &y,
  &y, &x
};

int main(void) {
  printf("%f, %f", coordenadas->coordenada_x[0] , coordenadas->coordenada_y[1]);
  
  return 0;
}
