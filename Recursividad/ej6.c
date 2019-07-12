#include <stdio.h>


float mayor_elem(float *v, size_t n) {
  if (n - 1 == 0) 
    return v[0];
  
  float res = mayor_elem(v, n - 1);
  
  if (res > v[n - 1])
    return res;
    
  else
    return v[n - 1];
}

int fibonacci(size_t n) {
  if (n == 1)
    return 0;
    
  if (n == 2)
    return 1;
    
  int res = fibonacci(n - 1);

  res += fibonacci(n - 2);
  
  return res;
}

// Uso el algoritmo de Euclides
int gcd(int x, int y) {
  if (x == 0 || ((x % y) == 0 && x > y))
    return y;
  
  if (y == 0 || ((y % x) == 0 && y > x))
    return x;
  
  if (x == y)
    return x;
  
  return gcd(y, x % y);
}




int main() {
  float v[100] = {0, 1, 2, 3, 7, 9.432543, 3, 9.8758765, 0, 3};
  size_t n = 8;
  int x = 17650, y = 78900;
  
  printf("Ej6 : %f\n", mayor_elem(v, sizeof(v) / sizeof(v[0])));
  printf("Ej8 : %d\n", fibonacci(n)); 
  printf("Ej9 general : el dcm de %d y %d es %d\n", x, y, gcd(x, y));
  
  return 0;
}
