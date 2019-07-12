#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Quiero modificar hacia dónde apuntan los punteros, entonces le agrego un nivel más

void swap(float **a, float**b) {
  float *auxiliar;
  
  auxiliar = *a;
  *a = *b;
  *b = auxiliar;
}

void suma(int a, int b, long int * suma) {
  *suma = a + b;
}

void resta(int a, int b, long int * resta) {
  *resta = a - b;
}

void producto(int multiplicando, int multiplicador, float * producto) {
  *producto = multiplicando * multiplicador;
}

void division(int dividendo, int divisor, double *cociente) {
  *cociente = dividendo / divisor;
}

void mod(int dividendo, int divisor, int *resto) {
  *resto = dividendo % divisor;
}

bool segundos_a_hms(int segundos_totales, int *horas, int *minutos, int *segundos) {
  if (segundos_totales < 0)
    return false;
  
  *horas = segundos_totales / 360;
  *minutos = (segundos_totales % 360) / 60 ;
  *segundos = (segundos_totales % 360) % 60;
  
  return true;
}

bool suma_elementos(int vector[], int longitud, int *suma) {
  *suma = 0;
  
  if (longitud < 0)
    return false;
  
  for (int i = 0; i < longitud; i++)
    *suma += vector[i];
  
  return true;
}
    
bool valor_maximo(int vector[], int longitud, int *maximo) {
  
  if (longitud < 0)
    return false;
  
  int i = 0;
  *maximo = vector[i];
  
  for (i = 1; i < longitud; i++) {
    if (vector[i - 1] < vector[i])
      *maximo = vector[i];
  }
  
  return true;
}

bool valores_al_cuadrado(int *vector, int longitud) {
 
  if (longitud < 0)
    return false;
    
  for (int i = 0; i < longitud; i++) 
    vector[i] = vector[i] * vector[i];
  
  return true;
}


int main() {
  int arreglo[] = {0, 2, 4, 6, 8, 10};
  int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
  int maximo = 0;
  
  if (valor_maximo(arreglo, longitud, &maximo))
    printf("El máximo número es %d\n", maximo);
  
  if (valores_al_cuadrado(arreglo, longitud)) {
    printf("El cuadrado de cada uno de los elementos del arreglo es: ");
    for (int i = 0; i < longitud; i++)
      printf("%d ", arreglo[i]);
  }
    
  return 0;
}


