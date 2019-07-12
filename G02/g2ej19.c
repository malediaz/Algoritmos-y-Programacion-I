#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 2
#define N 3
#define M 4
#define RANGO1 100
#define RANGO2 50
#define TRASLADAR -2


void cargar_mat_cuadrada(int m[][N], size_t tam, size_t rang) {
  srand(time(NULL));
  
  for (int i = 0; i < tam; i++)
    for (int j = 0; j < tam; j++) 
      m[i][j] = rand() % rang;
}

void impr_mat_cuadrada(int m[][N], size_t tam) {
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++)
      printf("%3d ", m[i][j]);
    printf("\n");
  }
}

int calcular_traza(int m[][N], size_t tam) {
  int traza = 0;
  for (int i = 0; i < tam; i++) 
    traza += m[i][i];
    
  return traza;
}

void cargar_mat_nxm(int m[][M], size_t fila, size_t columna, size_t rang) {
  srand(time(NULL));
  
  for (int i = 0; i < fila; i++) {
    for (int j = 0; j < columna; j++)
      m[i][j] = rand() % rang;
  }
}
    
void mat_mas_n(int m[][M], size_t fila, size_t columna, int n) {
  for (int i = 0; i < fila; i++) {
    for (int j = 0; j < columna; j++)
      m[i][j] += n;
  }
}

void cargar_transpuesta(int m[][M], int aux[][N], size_t fila, size_t columna) {
  for (int i = 0; i < fila; i++)
    for (int j = 0; j < columna; j++)
      aux[j][i] = m[i][j];
}

void impr_mat_nxm(int m[][M], size_t fila, size_t columna) {
  for (int i = 0; i < fila; i++) {
    for ( int j = 0; j < columna; j++)
      printf("%3d ", m[i][j]);
    printf("\n");
  }
}
  
int * prod_de_mat(int a[][K], int b[][M], int resultado[][M], size_t filA, size_t filB) { 
  for (int i = 0; i < filA; i++)
    for (int j = 0; j < filB; j++)
      resultado[i][j] += a[i][j] * b[j][i];
    
  return * resultado;
}
  

int main(void) {
  int cuadrada[N][N];
 
  printf("Matriz cuadrada:\n");
  cargar_mat_cuadrada(cuadrada, N, RANGO1);
  impr_mat_cuadrada(cuadrada, N);
  
  
  int rectangular1[N][M]; //auxiliar[K][N];
  
  printf("\nMatrices rectangulares:\n");
  cargar_mat_nxm(rectangular1, N, M, RANGO2);
  impr_mat_nxm(rectangular1, N, M);
  
  printf("\n");
  
  int rectangular2[K][M];
  cargar_mat_nxm(rectangular2, K, M, RANGO1);
  impr_mat_nxm(rectangular2, K, M);
  
  printf("\nOperaciones:\n\n");
  
  int traza;
  traza = calcular_traza(cuadrada, N);
  printf("La traza de la matriz cuadrada es de %d.\n", traza);
  
 /* printf("La matriz de NxK sumando %d a cada uno de sus elementos es la siguiente:\n", TRASLADAR);
  mat_mas_n(rectangular1, N, M);
  impr_mat_nxm(rectangular1, N, M);
  
  printf("\nLa transpuesta de la matriz anterior es la siguiente:\n");
  cargar_transpuesta(rectangular2, auxiliar, K, M);
  impr_mat_nxm(auxiliar, M, K);*/
  
  return 0;
}
  
  
