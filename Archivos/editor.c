#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CAD 999

int main(int argc, char *argv[]) {
  FILE *fichero = stdin;
  
  if (argc != 3) {
    fprintf(stderr, "Uso <archivo> <centinela>, mal ingresado.\n");
    
    return EXIT_FAILURE;
  }
  
  if ((fichero = fopen(argv[1], "w")) == NULL) {
    fprintf(stderr, "No se pudo abrir el archivo\n");
    
    return EXIT_FAILURE;
  }
    

  char linea[MAX_CAD];
  
  printf("*** Guardaré todo lo que escribas en el archivo: texto.txt ***\n");
  printf("*** Para terminar, el centinela es: %s      ***\n",argv[2]);

  fgets(linea, MAX_CAD, stdin);
  
  while(strncmp(linea, argv[2], strlen(argv[2])) != 0) {
    fputs(linea, fichero);
    fgets(linea, MAX_CAD, stdin);
  }
  
  printf("*** Hasta acá llegué ***\n");
  
  fclose(fichero);
  
  return EXIT_SUCCESS;
}
    
      
    
