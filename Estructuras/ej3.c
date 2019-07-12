#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MSJ 143

typedef struct usuarios {
  char nombre[30];
  char mensaje[143];
  unsigned long long mensaje_nro;
  time_t fecha;
} usuarios_t;

void imprimir_mensaje(usuarios_t usuario) {
  usuario.fecha = time(0);
  struct tm *tlocal = localtime(&usuario.fecha);
  
  char fecha_aux[128];
  strftime(fecha_aux,128,"\n\n%d/%m/%y %H:%M:%S",tlocal);
  
  printf("%s\n",fecha_aux);
  printf("%s\n", usuario.mensaje);
}

int main(void) {
  char aux[MAX_MSJ];
  usuarios_t malena;

  printf("Escriba un mensaje a mandar:\n");
  fgets(aux, MAX_MSJ, stdin);
  
  size_t i ;
  for (i = 0; i != '\n'; i++) 
    malena.mensaje[i] = aux[i];
    
  malena.mensaje[i] = '\0';
  
  imprimir_mensaje(malena);
  
  return 0;
}
  
  
  
