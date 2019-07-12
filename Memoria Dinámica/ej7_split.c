#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 30

typedef struct {
  const char cadena[MAX];
  const int anchos[MAX];
} campos_t;

typedef struct {
  const char cadena[MAX];
  const char delimitador;
} partir_t;


char **split(campos_t datos, size_t ncampos) {
  char **particiones = NULL;
  particiones = malloc(sizeof(char *) * ncampos);
  
  if (particiones == NULL)
    return NULL;
  
  int posicion = 0, i = 0, j;
  
  for (; i < ncampos; i++) {
    particiones[i] = malloc(sizeof(char) * datos.anchos[i] + 1);
    
    if (particiones[i] == NULL) {
      for (int k = 0; k < i; k++) 
        free(particiones[k]);
        
      free(particiones);
    }
    
    for (j = 0; j < datos.anchos[i]; j++, posicion++)
      particiones[i][j] = datos.cadena[posicion];
      
    particiones[i][j] = '\0';
  }
  
  return particiones;
}
    

bool split_bool(campos_t datos, size_t ncampos, char ***particiones) {
  char **aux;
    
  aux = malloc(sizeof(char *) * ncampos);
  
  if (*aux == NULL)
    return false;
  
  int i, j, posicion = 0;
  
  for (i = 0; i < ncampos; i++) {
    aux[i] = malloc(sizeof(char) * (datos.anchos[i] + 1));
    
    if (aux[i] == NULL) {
      for (int k = 0; k < i; i++)
        free(aux[i]);
      free(aux);
      aux = NULL;
      
      return false;
    }
    
    for (j = 0; j < datos.anchos[i]; j++, posicion++)
      aux[i][j] = datos.cadena[posicion];
      
    aux[i][j] = '\0';
  }
  
  *particiones = aux;
  
  return true;
}

bool join(partir_t datos, char ***particiones) {
  size_t lcadena = strlen(datos.cadena);
  size_t ncampos = 0;
  
  for (int i = 0; i < lcadena; i++) {
    if (datos.cadena[i] == datos.delimitador)
      ncampos++;
  }
      
  char **aux = malloc(sizeof(char *) * ncampos);
  
  if (aux == NULL)
    return false;
    
  int i, j, posicion = 0;
  
  for (j = 0; j < ncampos; j++, posicion++) {
    for (i = 0; datos.cadena[i] != datos.delimitador || i < lcadena; i++, posicion++) {
      aux[i] = malloc(sizeof(char));
    
      if (aux[i] == NULL) {
        for (int k = 0; k < i; k++)
          free(aux[i]);
        free(aux);
      
        return false;
      }
    
    aux[j][i] = datos.cadena[posicion];
    }
  
  aux[i] = malloc(sizeof(char));
  aux[j][i] = '\0';
  }

  particiones = &aux;
  
  return true;
}

int main(void) {
  campos_t datos[] = {
    {"unodostres", {3, 3, 4}}, 
    {"cuatrocincoseis", {6, 5, 4}}
  };
  size_t ncampos = 3;
  
  partir_t datos1 = { "uno,dos,tres", ','};
  
  char **partido = NULL;
  partido = split(datos[0], ncampos);
  
  if (partido == NULL)
    return EXIT_FAILURE;
  
  printf("Por nombre:\n");
  
  for(int i = 0; i < ncampos; i++) 
    printf("%s\n", partido[i]);
    
  for (int i = 0; i < ncampos; i++)
    free(partido[i]);
  free(partido);
  
  printf("\nPor interfaz:\n");
  
  if (split_bool(datos[1], ncampos, &partido)) {
    for(int i = 0; i < ncampos; i++) 
      printf("%s\n", partido[i]);
  }
  else 
    return EXIT_FAILURE;
  
  for (int i = 0; i < ncampos; i++)
    free(partido[i]);
  free(partido);
    
  if (join(datos1, &partido)) {
    for(int i = 0; i < ncampos; i++) 
      printf("%s\n", partido[i]);
  }
  
  return EXIT_SUCCESS;
}

char **split_manu(char *frase) {
    size_t n = 0;
    size_t j = 0;
    size_t k;
    char **ss = malloc(sizeof(char *) * 4);

    for (size_t i = 0; frase[i] != '\0'; i++) {
        for (; frase[n] != ','; n++);

        ss[i] = malloc(sizeof(char)*(n - j + 1));
        
        for (k = 0; j < n; j++, k++)
            ss[i][k] = frase[j];
        n++; j++;
    }
    return ss;
}
