#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

const int *busqueda_lineal(const int *v, size_t n, int objetivo) {
  for (int i = 0; i < n; i++) {
    if (v[i] == objetivo)
      return &v[i];
  }
  
  return NULL;
}
  

bool busqueda_lineal_bool(int * v, size_t n, int objetivo, int ** resultado) {
  
  for (int i = 0; i < n; i++) {
    if (v[i] == objetivo) {
      *resultado = &v[i];         // Le asigno una dirección de memoria a lo apuntado por resultado
                                  //No puedo "tocar" el puntero más exterior cuando lo devuelvo por interfaz
      return true;
    }
  }
  
  return false;
}

// Precondición: que el vector esté ordenado
bool busqueda_binaria(int * v, /* vector donde buscar */
                       size_t n,      /* largo del vector */
                       int objetivo,  /* elemento a buscar */
                       size_t izq,    /* franja del vector donde buscar, */
                       size_t der,    /* delimitada por izq y der */
                       int ** resultado) {
  
  int i = n / 2;
  izq = 0;
  der = n - 1;
  
  while (izq <= der) {
    if (v[i] == objetivo) {
      *resultado = &v[i];
      
      return true;
    }
    
    if (v[i] < objetivo) 
      izq = i + 1;
    
    else 
      der = i - 1;
      
    i = (der + izq) / 2;
  }
  
  return false;
}




int main () {
  int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
  int *resultado;
  size_t l = sizeof(v) / sizeof(v[0]);
  
  if (busqueda_lineal_bool(v, l, 8, &resultado))
    printf("%d\n", *resultado);
  
  const int *resultado2;
  
  if ((resultado2 = busqueda_lineal(v, l, 10)) != NULL)
    printf("%d\n", *resultado2);
    
  int *resultado3 = NULL;  
  size_t min = 0, max = 0; 
  if (busqueda_binaria(v, l, 16, min, max, &resultado3))
    printf("%d", *resultado3);
  
  return 0;
}
    
