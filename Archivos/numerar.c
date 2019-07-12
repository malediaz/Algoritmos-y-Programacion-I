#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fi = stdin;
  
  if (argc != 2) {
    fprintf(stderr, "Uso <salida>. Mal ingresado.\n");
   
    return EXIT_FAILURE;
  }
  
  if ((fi = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "No se pudo abrir el archivo <%s>.\n", argv[1]);
    
    return EXIT_FAILURE;
  }
  
  int i = 1;
  char cadena[100];
  
  while (fgets(cadena, 100, fi) != NULL) {
    printf("%d: ", i++);
    fputs(cadena, stdout);
  }
  
  return EXIT_SUCCESS;
}
