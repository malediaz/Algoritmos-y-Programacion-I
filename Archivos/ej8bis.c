#include <stdio.h>
#include <stdlib.h>

#define BLOQUE 100

int main(int argc, char *argv[]) {
  FILE *binario = NULL;
  
  if (argc != 2) {
    fprintf(stderr, "Mal ingresado. Uso ./<programa> <archivo binario>\n");
    
    return 1;
  }
  
  if ((binario = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "El archivo %s no pudo abrirse correctamente.\n", argv[1]);
    
    return 1;
  }
  
  int leidos, *v = malloc(sizeof(int) * BLOQUE);
  size_t n = 0;
  
  while ((leidos = fread(v + n, sizeof(int), BLOQUE, binario)) == BLOQUE) {     // Si lo quiero hacer de a uno pongo != EOF
    n += BLOQUE;                                                                // Y acá n++
    
    int *aux = realloc(v, sizeof(int) * (n + BLOQUE));                          // Y acá sizeof(int) * (n + 1)
    
    if (aux == NULL) {
      fprintf(stderr, "Hubo un error al asignar memoria.\n");
      free(v);
      
      return 1;
    }
    
    v = aux;
  }
  
  printf("%d\n", v[1000]);
  
  free(v);
  fclose(binario);
  
  return 0;
}
  
    
