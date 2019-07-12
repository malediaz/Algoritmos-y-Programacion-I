#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct vector {
    void **datos;
    size_t largo;
};

typedef struct vector vector_t;

typedef void (*vector_destructor_t) (void *);

vector_t *vector_crear(size_t n) {
  vector_t *v = malloc(sizeof(vector_t));
  if (v == NULL)
    return NULL;
    
  v->datos = calloc(n, sizeof(void *));
  if (v->datos == NULL) {
    free(v);
    v->largo = 0;
    
    return NULL;
  }
  
  v->largo = n;
  
  return v;
}

void vector_destruir(vector_t *v, vector_destructor_t destructor) {
  if (destructor != NULL) {
    for (size_t i = 0; i < v->largo; i++)
      destructor(v->datos[i]);
  }
    
    free(v->datos);
    free(v);
}

bool vector_guardar(vector_t **v, size_t posicion, void *elemento) {
  if (posicion >= (*v)->largo)
    return false;
    
  (*v)->datos[posicion] = elemento;
  
  return true;
}

vector_t *vector_copiar(vector_t *orig) {
  vector_t *dest = NULL;
  
  dest = malloc(sizeof(vector_t));
  
  if (dest == NULL)
    return NULL;
  
  dest->datos = malloc(sizeof(void *) * orig->largo);
  
  if (dest->datos == NULL) {
    vector_destruir(dest, NULL);
    
    return NULL;
  }
  
  for (int i = 0; i < orig->largo; i++) 
    dest->datos[i] = orig->datos[i];
  
  dest->largo = orig->largo;
  
  return dest;
}

/*bool vector_leer(vector_t *v, size_t i, void *valor) {
  if (i >= v->largo)
    return false;
    
  valor = v->datos[i];
  
  return true;
}*/
void *vector_leer(const vector_t *v, size_t i) {
	if(i >= v->largo)
		return NULL;

	return v->datos[i];
}



int main() {
  vector_t *v = vector_crear(10);
  int num = 23456;
  char c = 'f';
  int *valor;
  
  for(size_t i = 0; i < 10; i++) {
		int *pi = malloc(sizeof(int));
		*pi = i;
		vector_guardar(&v, i, pi);
	}

  
  vector_guardar(&v, 0, "HOLA");
  vector_guardar(&v, 1, &num);
  vector_guardar(&v, 7, &c);
  
  vector_t *dest = NULL;
  dest = vector_copiar(v);
  
  printf("%s\n", (char *)v->datos[0]);
  printf("%d\n", *((int *)v->datos[1]));
  printf("%c\n", *((char *)v->datos[7]));
  
  printf("%s\n", (char *)dest->datos[0]);
  printf("%d\n", *((int *)dest->datos[1]));
  printf("%c\n", *((char *)dest->datos[7]));
  
  valor = vector_leer(dest, 1);
  printf("%d\n", *valor);
  
  vector_destruir(v, NULL);
  vector_destruir(dest, NULL);
  
  return 0;
}

