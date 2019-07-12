#include <stdio.h>
#include <stdlib.h>

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
  
  size_t largo = 1001, leidos;
  int *v = malloc(sizeof(int) * largo);
  
  if (v == NULL) {
    fprintf(stderr, "Error de memoria.\n");
    
    return 1;
  }
  
  leidos = fread(v, sizeof(int), largo, binario);
  
  if (leidos != largo) {
    fprintf(stderr, "Hubo un error de lectura.\n");
    fclose(binario);
    
    return 1;
  }
  
  printf("%d\n", v[583]);                // Se guradó, vamos carajo
  
  free(v);
  fclose(binario);
  
  return 0;
}
  
  
