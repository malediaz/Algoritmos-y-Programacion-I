#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 30

int calcular_raices(float a, float b, float c, float d) {
  float x1, x2, disc, denom;

  if (a == 0) {
    x1 = (d - c) / b;

    printf("\nLa ec tiene una única raíz y es %f.\n", x1);

    return 0;
  }
  
  disc = pow(b, 2) - 4 * a * (c - d);
  
  if (disc > 0) {
    denom = 2 * a;
    x1 = (-b + sqrt(disc)) / denom;
    x2 = (-b - sqrt(disc)) / denom;

    printf("\nLas raíces de la ec son %f y %f.\n", x1, x2);

    return 0;
}

  return 1;
}

int main(void) {
	char coeficientes[MAX];
	float a, b, c, d;

	printf("\tSolución de una ec de segundo grado");
	printf(" de tipo ax²+bx+c=d.\n\n");

    printf("Inserte valor de a: ");
    fgets(coeficientes, MAX, stdin);
    a = atof(coeficientes);

    printf("Inserte valor de b: ");
    fgets(coeficientes, MAX, stdin);
    b = atof(coeficientes);

    printf("Inserte valor de c: ");
    fgets(coeficientes, MAX, stdin);
    c = atof(coeficientes);

    printf("Inserte valor de d: ");
    fgets(coeficientes, MAX, stdin);
    d = atof(coeficientes);

    
    while (!calcular_raices(a, b, c, d)) {
      
      printf("\t  ___________________________________________________\n\n");

      printf("\tSolución de una ec de segundo grado");
	  printf(" de tipo ax²+bx+c=d.\n\n");

      printf("Inserte valor de a: ");
      fgets(coeficientes, MAX, stdin);
      a = atof(coeficientes);

      printf("Inserte valor de b: ");
      fgets(coeficientes, MAX, stdin);
      b = atof(coeficientes);

      printf("Inserte valor de c: ");
      fgets(coeficientes, MAX, stdin);
      c = atof(coeficientes);

      printf("Inserte valor de d: ");
      fgets(coeficientes, MAX, stdin);
      d = atof(coeficientes);
   }
   
  printf("\nLas raíces son complejas.\n");

  return 0;
}
