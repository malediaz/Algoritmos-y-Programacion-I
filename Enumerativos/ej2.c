#include <stdlib.h>
#include <stdio.h>

#define MAX 40

typedef enum status {
  ST_ERR_VALOR_NULO, ST_OK, ST_ERR_VALOR_NEGATIVO, 
} status_t;

const char *mensajes[] = {
  [ST_OK] = "Gracias, vuelva prontos.",
  [ST_ERR_VALOR_NEGATIVO] = "Valor inválido.",
  [ST_ERR_VALOR_NULO] = "Valor nulo ingresado.",
};


void imprimir_mensaje() {
  char aux[MAX];
  int numero = 0;
  
  while (numero <= 0) {
    printf("Ingrese un número positivo: ");
    fgets(aux, MAX, stdin);
    numero = (int)atoi(aux);
    
    if (numero < 0)
      printf("%s\n", mensajes[ST_ERR_VALOR_NEGATIVO]);
    
    if (numero == 0)
      printf("%s\n", mensajes[ST_ERR_VALOR_NULO]);
      
    if (numero > 0)
      printf("%s\n", mensajes[ST_OK]);
  }
}

int main(void) {
  
  imprimir_mensaje();
  
  return 0;
}
  
  
