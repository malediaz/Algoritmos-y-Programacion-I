#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

typedef struct punto {
  float coordenada_x;
  float coordenada_y;
} punto_t;

double distancia_puntos(punto_t p0, punto_t p1) {
  double distancia;
  float delta_x = p0.coordenada_x - p1.coordenada_y;
  float delta_y = p0.coordenada_y - p1.coordenada_y;
  distancia = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
  
  return distancia;
}


int main(void) {
  char aux[MAX];
  punto_t p0, p1;
  
  printf("Cálculo de la ditancia entre dos coordenadas.\n");
  printf("Inserte las coordenadas correspondientes. \n\n");

  printf("Primer punto:\n");
  
  printf("Coordenada en x: ");
  fgets(aux, MAX, stdin);
  p0.coordenada_x  = atof(aux);
  
  printf("Coordenada en y: ");
  fgets(aux, MAX, stdin);
  p0.coordenada_y  = atof(aux);
  
  printf("Segundo punto:\n");
  
  printf("\nCoordenada en x: ");
  fgets(aux, MAX, stdin);
  p1.coordenada_x  = atof(aux);
  
  printf("Coordenada en y: ");
  fgets(aux, MAX, stdin);
  p1.coordenada_y  = atof(aux);
  
  printf("\n\nLa distancia entre los puntos es %f\n", distancia_puntos(p0, p1));
  
  
  return 0;
}
