#include <stdio.h>
#include <stdlib.h>

int main(void) {

  float *pfloat0, manzana = 40.0, pera = 35.0;

  pfloat0 = &manzana;
  printf("&pfloat: %p\n", &pfloat0);
  printf("&manzana: %p\n", &manzana);
  printf("&pera: %p\n", &pera);
 
  int i = 3, * pint;
  float f = 10.55;

  pint = &i;
  printf("pint: %d\n", *pint);
  *pint = 10;
  printf("pint: %d\n", *pint);
  *pint = f;        // Esta bien porque el float se castea solo a int
  printf("pint: %d\n", *pint);
  //pint = &f;      Mal porque pint es de tipo int y apunt a un float sin un casteo  
  //pint = 4321;    Mal porque pint apunta a un número
  
  float var, set[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  float *p;

  p = set;
  printf("pint: %f\n", *p);
  var = *p;
  printf("pint: %f\n", var);
  *p=10.0;
  printf("pint: %f\n", *p);
  
  int conj[5], list[]={5, 4, 3, 2, 1};
  int *punt;

  punt = list;
  *punt = 9;
  //conj = punt;      //MAL, en todo caso seria conj[0] = *punt
  //list = conj;      //MAL
  //punt = &conj;     //MAL
  
  int *pint1, arrayint[] = {9, 8, 7, 6, 5};
  float *pfloat, arrayfloat[] = {1, 2, 3, 4, 5};

  pint1 = arrayint;
  printf("pint inicial: %d\n", *pint1);
  pfloat = arrayfloat;
  printf("pfloat inicial: %f\n", *pfloat);
  pint1 += 1;
  printf("pint me corro un cuadradito: %d\n", *pint1);
  pfloat += 1;
  printf("pfloat me corro un cuadradito: %f\n", *pfloat);
  pint1++;
  printf("pint otro: %d\n", *pint1);
  pfloat++;
  printf("pfloat otro: %f\n", *pfloat);
  pint1 -= 1;
  printf("pint vuelvo 1: %d\n", *pint1);
  pfloat -=1;
  printf("pfloat vuelvo 1: %f\n", *pfloat);
  
  
  int *p0, a[] = {0, 36, 2, 3, 4, 99, 6, 10000, 8, 9};
  int var0;

  p0 = a;
  printf("p0: %d\n", *p0);
  *p0 = 33;                   // Acá digo que LO APUNTADO por p0 vale 33, entonces modifico a[0]
  printf("a: %d\n", a[0]);
  printf("p0: %d\n", *p0);
  var0 = *p0;
  printf("var0: %d\n", var0);
  var0 = *(p0+1);             // Acá corro una dirección de memoria de p0, osea voy a a[1]
  printf("var0: %d\n", var0);
  var0 = *(p0+3);             // Apunto a a[3]
  printf("var0: %d\n", var0);
  var0 = *(p0++);
  printf("var0: %d\n", var0); // Primero asigno var = *p0 y despues lo corro un cuadradito opsea quedo en a[1]
  var0 = *p0++;               
  printf("var0 p0 a[1]: %d\n", var0);
  printf("a: %d\n", a[2]); // *p0++ = *p0 = *p0 + 1 quedo en a[2]
  var0 = *(++p0);
  printf("var0 a[3]: %d\n", var0);    //Estoy en a[3]
  var0 = *++p0;
  printf("var0 a[4]: %d\n", var0);     
  var0 = *p0++;           
  printf("var0: %d\n", var0);
  var0 = (*p0)++;
  var0 = ++(*p0);
  var0 = *p0+1;
  
  int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  var = *(b+1);
  //var = *(b++);       MAL, b es un arreglo, no un puntero, solo puedo sumar asi b+x, no b++
  
  return 0;
}

