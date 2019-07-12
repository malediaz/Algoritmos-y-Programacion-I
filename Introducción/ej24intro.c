#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void billetes_minimos(int n) {
  int mil, quinientos, doscientos, cien, cincuenta, veinte, diez, cinco, dos, uno;
  
  mil = (n / 1000) * 1000;
  quinientos = ((n % 1000) / 500) * 500;
  doscientos = ((n % 500) / 200) * 200;
  cien = ((n % 200) / 100) * 100;
  cincuenta = ((n % 100) / 50) * 50;
  veinte = ((n % 50) / 20) * 20;
  diez = ((n % 20) / 10) * 10;
  cinco = ((n % 10) / 5) * 5;
  dos = ((n % 5) / 2) * 2;
  uno = (n % 2);
  
  int monto[MAX] = {mil, quinientos, doscientos, cien, cincuenta, veinte, diez, cinco, dos, uno};
  
  printf("$%d = ", n);
  
  for (int i = 0; i < MAX; i++) {
    if (monto[i] != 0)
      printf("$%d ", monto[i]);
  }
}

int main(void) {
  char dinero[MAX];
  int n;
  
  printf("Insertar cantidad de dinero: ");
  fgets(dinero, MAX, stdin);
  n = atoi(dinero);
  
  billetes_minimos(n);
  
  return 0;
}
