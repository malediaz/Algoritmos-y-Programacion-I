#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMEROS 10
#define MAX 50

int elegir_max(int lista[][MAX], int n) {
  int i = 0;
  int max = 0;
  
  for (; i < n; i++) 
    if (lista[i] > max)
      max = lista[i];

  return max;
}

int elegir_min(int lista[][MAX], int n) {
  int i = 0;
  int * min = 0;
  
  for (; i < n; i++) 
    if (lista[i] < min)
      min = lista[i];

  return * min;
}

double promedio(int lista[][MAX], int n) {
  int i = 0, * suma = 0;
  double * resultado;
  
  for (; i < n; i++) 
    suma += lista[i];
  
  resultado = suma / n;
  
  return * resultado;
}

void recibir_enteros(int lista[][MAX], int n) {
  int i = 0;
  char aux[MAX];
  
  for (; i < NUMEROS; i++) {
    fgets(aux, MAX, stdin);
    lista[i] = atoi(aux);
  }
}


int main(void) {
  int numeros[NUMEROS][MAX];
  int n = NUMEROS;
  recibir_enteros(numeros, n);
  
  printf("El mayor número del arreglo es %d\n", elegir_max(numeros, n));
  printf("El menor número del arreglo es %d\n", elegir_min(numeros, n));
  printf("Promedio: %f\n", promedio(numeros, n));
  
  return 0;
}
