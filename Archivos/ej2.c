#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fi = stdin;
  FILE *fo = stdout;
  
  if (argc != 3) {
    fprintf(stderr, "Uso: <entrada> <salida>. Mal ingresado.");
    
    return 0;
  }
  
  if ((fi = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "No se pudo abrir el archivo <%s>.\n", argv[1]);
    
    return EXIT_FAILURE;
  }
  
  if ((fo = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "No se pudo abrir el archivo <%s>.\n", argv[2]);
    fclose(fi);
    
    return EXIT_FAILURE;
  }
  
  int c; 
  
  while ((c = fgetc(fi)) != EOF)
    fputc(c, fo);
    
  fclose(fi);
  fclose(fo);
  
  return EXIT_SUCCESS;
}
    
    
