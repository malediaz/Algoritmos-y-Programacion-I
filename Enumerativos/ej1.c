#include <stdio.h>

typedef enum booleanos {
  FALSE, TRUE
} bool;

const char *booleano_cadena[] = {
  [FALSE] = "FALSE",
  [TRUE] = "TRUE", 
};

const char *nro_a_cadena(bool n) {
  return booleano_cadena[n];
}

int main(void) {
  bool n = 0;
  bool m = 1;
  
  printf("La condición de la variable n es: %s\n", nro_a_cadena(n));
  printf("La condición de la variable m es: %s", nro_a_cadena(m));
  
  return 0;
}
  

