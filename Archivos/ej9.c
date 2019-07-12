#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO "structs.txt"

struct materia {
    unsigned char codigo_departamento;
    unsigned char codigo_materia;
    char nombre[100];
};

typedef struct materia materia_t;

// Oredenamiento por selección
void ordenar_struct(materia_t **s, size_t n_structs) {
  for (int j = 0; j < n_structs - 1; j++) {
    unsigned char min = (*s)[j].codigo_departamento;
    int pos = j;
    
    for (int i = j + 1; i < n_structs; i++) {
      if ((*s)[i].codigo_departamento < min) {
        min = (*s)[i].codigo_departamento;
        pos = i;
      }
    }
      
    materia_t aux;
    
    // Swap
    aux = (*s)[j];
    (*s)[j] = (*s)[pos];
    (*s)[pos] = aux;
  }
}
  
  

int main() {
  materia_t materia_v[] = {
    {5, 81, "Análisis Matemático"},
    {2, 03, "Química"},
    {7, 32, "Dispositivos Semiconductores"},
    {5, 80, "Probabilidad y estadística"},
    {3, 42, "Economía"}
  };
  
  FILE *binario = NULL;
  
  if ((binario = fopen(ARCHIVO, "w+")) == NULL) {
    fprintf(stderr, "No se pudo abrir el alchivo %s.\n", ARCHIVO);
    
    return 1;
  }
  
  size_t n_structs = sizeof(materia_v) / sizeof(materia_v[0]);
  size_t escritos = 0;
  
  escritos = fwrite(materia_v, sizeof(materia_t), n_structs, binario);
  
  if (escritos != n_structs) {
    fprintf(stderr, "Hubo un error en la escritura del archivo.\n");
    fclose(binario);
    
    return 1;
  }
  
  fclose(binario);
  binario= fopen(ARCHIVO, "r");
  
  // Levanto la información escrita en un vector dinámico
  materia_t *v = malloc(sizeof(materia_t) * n_structs);
  
  if (v == NULL) {
    fprintf(stderr, "Hubo un error al asignar memoria.\n");
    fclose(binario);
    
    return 1;
  }
    
  size_t leidos = 0;
  
  leidos = fread(v, sizeof(materia_t), n_structs, binario);
  
  if (leidos != n_structs) {
    fprintf(stderr, "Hubo un error al leer el archivo.\n");
    fclose(binario);
    
    return 1;
  }
  
  ordenar_struct(&v, n_structs);
  
  printf("Departamento / Código / Asignatura\n\n");
  
  // Verifico que haya quedado ordenado
  for (int i = 0; i < n_structs; i++)
    printf("\t%d\t%2d\t%s\n", v[i].codigo_departamento, v[i].codigo_materia, v[i].nombre);
  
  free(v);
  fclose(binario);
  
  return 0;
}
