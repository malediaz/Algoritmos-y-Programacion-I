#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Los archivos ya deben estar creados

int main (int argc, char *argv[]) {
  FILE *fi = NULL;
  FILE *fi_2 = NULL;
  
  if (argc < 3) {
    fprintf(stderr, "Mal ingresado.\n");
    
    return EXIT_FAILURE;
  }
  
  if ((fi = fopen(argv[argc - 1], "r")) == NULL){
    fprintf(stderr, "No se pudo abrir el archivo <%s>.\n", argv[argc - 1]);
    
    return EXIT_FAILURE;
  }
  
  int c, linea = 0, palabra = 0, bytes = 0;
  
  while ((c = fgetc(fi)) != EOF) {
    if (c == '\n') {
      linea++;
      palabra++;
    }
      
    if (c == ' ')
      palabra++;
      
    bytes += sizeof(c);
  }
  
  if (argc == 4) {
    printf("%d %d %d <%s>\n", linea, palabra, bytes, argv[argc - 1]);
    fclose(fi);

    return EXIT_SUCCESS;
  }
  
  if (argc > 4) {
    if ((fi_2 = fopen(argv[argc - 2], "r")) == NULL) {
      fprintf(stderr, "No se pudo abrir el archivo <%s>.\n", argv[argc - 2]);
      fclose(fi);
      
      return EXIT_FAILURE;
    }
    
    int c_2, linea_2 = 0, palabra_2 = 0, bits_2 = 0;
  
    while ((c_2 = fgetc(fi_2)) != EOF) {
      if (c_2 == '\n') {
        linea_2++;
        palabra_2++;
      }
      
      if (c_2 == ' ')
        palabra_2++;
      
      bits_2 += sizeof(c_2);          //Arrgelar lo de los bytes
    }
    
    printf("%d %d %d <%s>\n", linea, palabra, bytes, argv[argc - 2]);
    printf("%d %d %f <%s>\n", linea_2, palabra_2, bits_2 / 8.0, argv[argc - 1]);
    printf("%d %d %f %s\n", linea + linea_2, palabra + palabra_2, (bytes + bits_2) / 8.0, "total");
    
    fclose(fi);
    fclose(fi_2);
    
    return EXIT_SUCCESS;
  }
    
  else {
    if (!strcmp(argv[1], "-l"))
      printf("%d <%s>\n", linea, argv[2]);
  
    if (!strcmp(argv[1], "-w"))
      printf("%d <%s>\n", palabra, argv[2]);
    
    if (!strcmp(argv[1], "-c"))
      printf("%d <%s>\n", bytes, argv[2]);
  }
    
  fclose(fi);
  
  return EXIT_SUCCESS;
}
