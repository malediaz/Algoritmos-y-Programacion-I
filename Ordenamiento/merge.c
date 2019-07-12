#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TM 100


void merge(int array[], int l, int m, int r) {
  int temp[TM];
  int i = l, j = m + 1, k = 0;

  while (i <= m && j <= r) {
    if (array[i] < array[j]) 
      temp[k++] = array[i++];
    else
      temp[k++] = array[j++];
  }
  
  while (i <= m) 
    temp[k++] = array[i++];
  
  while (j <= r) 
    temp[k++] = array[j++];
    
  for (i = l, j = 0; i <= r; i++, j++) 
    array[i] = temp[j];
}

void mergesort(int array[], int l, int r){
  int mid;
  
  if (l < r) {
    mid = (l + r) / 2;
    
    mergesort(array, l, mid);             //left recursion
    mergesort(array, mid + 1, r);         //right recursion
    
    merge(array, l, mid, r);              //merging of two sorted sub-arrays
  }
}

/*
void mergesort_3(int array[], int l, int r) {
  if (l < r) {
    int seccion1 = (l + r) / 3;
    int seccion2 = (l + r) * 2 / 3;
    
    mergesort_3(array, l, seccion1);
    mergesort_3(array, seccion1 + 1, seccion2);
    mergesort_3(array, seccion2 + 1, r);
    
    merge(array, l, seccion1, seccion2, r);
  }
}
*/


int main() {
  srand(time(NULL));
  int vector[TM];
  for (size_t i = 0; i < TM; i++) 
    vector[i] = rand() % TM;
    
  mergesort(vector,0,TM - 1);
    
  for (size_t i = 0; i < TM; i++) 
    printf("%zd: %d\n", i + 1, vector[i]);
    
  return 0;
}
