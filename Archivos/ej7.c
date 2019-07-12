#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *binario = NULL;
  
  if (argc != 2) {
    fprintf(stderr, "Mal ingresado. Uso ./<programa> <archivo binario>\n");
    
    return 1;
  }
  
  if ((binario = fopen(argv[1], "w+")) == NULL) {
    fprintf(stderr, "El archivo %s no pudo abrirse correctamente.\n", argv[1]);
    
    return 1;
  }
  
  int n = 0;
  char s = '\n';
  
  while (n < 1001) {
    fwrite(&n, sizeof(int), 1, binario);
    n++;
  }
  
  fwrite(&s, sizeof(char), 1, binario);
  
  
  fclose(binario);
  
  return 0;
}
