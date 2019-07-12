#include <stdio.h>
#include <stdlib.h>

#define TEMP_MAX 50000
#define TEMP_MIN 1700
#define MAX 10

typedef enum clasificacion_espectral {
  O, B, A, F, G, K, M
} espectral_t;

const char *color[] = {
  [O] = "Azul",
  [B] = "Blanco azulado",
  [A] = "Blanco",
  [F] = "Blanco amarillento",
  [G] = "Amarillo",
  [K] = "Naranja",
  [M] = "Rojo",
};


void imprimir_color() {
  char aux[MAX];
  int temp = TEMP_MIN;
  
  while (temp >= TEMP_MIN  && temp <= TEMP_MAX ) {
    printf("\nIngrese la temperatura de la estrella (en kelvins): ");
    fgets(aux, MAX, stdin);
    temp = (int)atoi(aux);
    
    if (temp >= TEMP_MIN && temp <= 3200)
      printf("%s\n", color[M]);
    
    if (temp > 3200 && temp <= 4600)
      printf("%s\n", color[K]);
      
    if (temp > 4600 && temp <= 5700)
      printf("%s\n", color[G]);
      
    if (temp > 5700 && temp <= 7100)
      printf("%s\n", color[F]);
      
    if (temp > 7100 && temp <= 9600)
      printf("%s\n", color[A]);
      
    if (temp > 9600 && temp <= 28000)
      printf("%s\n", color[B]);
      
    if (temp > 28000 && temp <= TEMP_MAX)
      printf("%s\n", color[O]);
  }
}

int main(void) {
  imprimir_color();
  
  printf("\nExcede los límites de temperatura establecidos.\n");
  
  return 0;
}
