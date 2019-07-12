#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


double suma(double z, int k) {
  if (k == 0)
    return z;
    
  return suma(z, k - 1) + 1;
}

double producto(double z, int k) {
  if (k == 0)
    return 0;
    
  return producto(z, k - 1) + z;
}

double potencia(double z, int k) {
  if (k == 0)
    return 1;
    
  return potencia(z, k - 1) * z;
}

size_t cant_digitos(long long n) {
  if (abs(n / 10) < 1)
    return 1;
    
  return cant_digitos(n / 10) + 1;
}

void espejado(size_t n) {
  if (n  < 10) 
    printf("%zd", n);

  else {
    printf("%zd", n % 10);
    
    espejado(n / 10);
  }
}

bool es_potencia(float n, float b) {
  if (n == b) 
    return true;
  
  if (n < b)
    return false;
    
  return es_potencia(n / b * 1.0, b);
}

int triangular(int n) {
  if (n == 0)
    return 0;
  
  return triangular(n - 1) + n;
}


int main() {
  double pi = 3.141592;
  int x = 5;
  long long entero = -543746;
  size_t entero_1 = 748;
  float n = 410.0625, b = 4.5;
  
  printf("Ej1\n\nLa suma entre %f y %d es %f\n", pi, x, suma(pi, x));
  printf("El producto entre %f y %d es %f\n", pi, x, producto(pi, x));
  printf("%f elevado a la %d es %f\n------------------\n",pi, x, potencia(pi, x));
  
  // --------------------------------------------
  
  printf("\nEj 2, 3, 4, 5\n\n");
  
  printf("Cantidad de dígitos de %lld: %zd\n", entero, cant_digitos(entero));
  printf("%zd || ", entero_1);
  espejado(entero_1);
  printf("\n%f %ses potencia de %f\n", n, es_potencia(n, b) ? "" : "no ", b);
  printf("El n-ésimo número triangular de %d es %d\n", x, triangular(x));
  
  return 0;
}
