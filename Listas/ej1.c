#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "listas.h"

struct nodo {
  void *dato;
  struct nodo *sig;
};

struct lista{
  struct nodo *prim;
};


lista_t *lista_crear() {
  lista_t *l = malloc(sizeof(lista_t));
  
  if (l == NULL)
    return NULL;
    
  l->prim = NULL;
  
  return l;
}

void lista_destruir(lista_t *l, void (*destruir_dato)(void *d)) {
  struct nodo *n = l->prim;
  
  while (n != NULL) {
    struct nodo *sig = n->sig;
    
    if (*destruir_dato != NULL)
      destruir_dato(n->dato);
      
    free(n);
    
    n = sig;
  }
    
  free(l);
  l = NULL;
}

bool lista_es_vacia(const lista_t *l) {
  return l->prim == NULL;  
}

struct nodo *nodo_crear(void *d) {
  struct nodo *n = malloc(sizeof(struct nodo));
  
  if (n == NULL)
    return NULL;
  
  n->dato = d;
  n->sig = NULL;
  
  return n;
}

bool lista_insertar_comienzo(lista_t *l, void *d) {
  struct nodo *n = nodo_crear(d);
  
  if (n == NULL)
    return false;
  
  if (l->prim == NULL) {
    l->prim = n;
      
    return true;
  }
      
  n->sig = l->prim;
  l->prim = n;
  
  return true;
}

bool lista_insertar_final(lista_t *l, void *d) {
  struct nodo *aux = l->prim;
  struct nodo *n = nodo_crear(d);
  if (n == NULL)
    return false;
  
  if (aux == NULL) {
    l->prim = n;
    
    return true;
  }
  
  while (aux->sig != NULL)
    aux = aux->sig;
    
  aux->sig = n;
  
  return true;
}

void *lista_extraer_primero(lista_t *l) {
  if (lista_es_vacia(l))
    return NULL;
    
  struct nodo *n = l->prim;
  void *d = n->dato;
  
  l->prim = n->sig;
  free(n);
  
  return d; 
}

void *lista_extraer_ultimo(lista_t *l) {
  struct nodo *n = l->prim;
  if (n == NULL)
    return NULL;
    
  struct nodo *aux =n->sig;
  
  while (aux->sig != NULL) {
    n = aux;
    aux = aux->sig;
  }
    
  void *d = aux->dato;
  
  free(aux);
  n->sig = NULL;
  
  
  return d;  
}

void *lista_buscar(const lista_t *l, const void *dato, int (*cmp)(const void *a, const void *b)) {
  struct nodo *n = l->prim;
  
  if (n == NULL)
    return NULL;
  
  while (n != NULL) {
    if (cmp(dato, n->dato))
      return n->dato;
      
    n = n->sig;
  }
  
  return NULL;
}

void *lista_borrar(lista_t *l, const void *dato, int (*cmp)(const void *a, const void *b)) {
  struct nodo *ant = l->prim;
  
  if (ant == NULL)
    return NULL;
  
  if (cmp(dato, ant->dato) == 0)
    return lista_extraer_primero(l);
    
  struct nodo *prox = ant->sig;
    
  while (prox != NULL) {
    if (cmp(dato, prox->dato) == 0) {
      void *d = prox->dato;
      
      ant->sig = prox->sig;
      free(prox);
      
      return d;
    }
    
    prox = prox->sig;
    ant = ant->sig;
  }
  
  return NULL;
}

void lista_recorrer(const lista_t *l, bool (*visitar)(const void *dato, void *extra), void *extra) {
  struct nodo *n = l->prim;
  
  if (n == NULL)
    return;
    
  while (n != NULL) {
    if(!visitar(n->dato, extra))
      return;
    
    n = n->sig;
  }
}

void lista_mapear(lista_t *l, void *(*f)(void *dato)) {
  struct nodo *n = l->prim;
  
  while (n != NULL) {
    n->dato = f(n->dato);
    n = n->sig;
  }
}

lista_t *lista_filtrar(lista_t *l, bool (*f)(void *dato)) {
  struct nodo *n = l->prim;
  if (lista_es_vacia(l))
    return NULL;
    
  lista_t *filtro = lista_crear();
  struct nodo *aux = n->sig;
  void *d;
  
  if (f(n->dato)) {
    d = lista_extraer_primero(l);
    lista_insertar_comienzo(filtro, d);
  } 
  
  while (aux != NULL) {
    if (f(aux->dato)) {
      d = aux->dato;
      n->sig = aux->sig;
      lista_insertar_final(filtro, d);
      
    }
    
    n = aux;
    aux = aux->sig;
  }
  
  return filtro;
}

bool lista_extender(lista_t *a, const lista_t *b) {
  struct nodo *nodo_a = a->prim;
  struct nodo *nodo_b = b->prim;
  
  if (nodo_b == NULL)
    return false;
  
  while (nodo_a->sig != NULL)
    nodo_a = nodo_a->sig;
    
  nodo_a ->sig = nodo_b;
  
  return true;
}

void **lista_a_vector(const lista_t *l, size_t *n) {
  if (lista_es_vacia(l))
    return NULL;
    
  struct nodo *nod = l->prim;
  void **v = NULL;
  size_t i = 0;
  *n = 0;
  
  while (nod != NULL) {
    void **aux = realloc(v, sizeof(void *) * (i + 1));
    aux[i] = nod->dato;
    nod = nod->sig;
    i++;
    
    v = aux;
  }

  *n = i;
  
  return v;
}


// Auxiliares

int intcmp(const void *a, const void *b) { 
  return *((const int *)a) - *((const int *)b);
}

bool es_par(void* a) {
  return (*((int *)a) % 2 == 0);
}

bool lista_imprimir(lista_t *l, void (*imprimir)(const void *a)) {
  struct nodo *n = l->prim;
  
  if (n == NULL)
    return false;
  
  while (n != NULL) {
    imprimir(n->dato);
    n = n->sig;
  }
  
  printf("NULL");
  
  return true;
}

void int_print(const void *a) {
  printf("%d -> ", *((const int *)a));
}


int main() {
  lista_t *l = lista_crear();
  
  if (l == NULL)     
    return EXIT_FAILURE;

  int v[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  for (int i = 0; i < 11; i++)
    lista_insertar_final(l, v + i);
  
  printf("La lista %sestá vacía\n", lista_es_vacia(l) ? "" : "no ");
  lista_imprimir(l, &int_print);
  lista_t *filtro = lista_filtrar(l, es_par);
  printf("\nFiltramos los pares\n");
  lista_imprimir(filtro, int_print);
  printf("\nExtraemos el último de la lista impar\n");
  lista_extraer_ultimo(l);
  lista_imprimir(l, int_print);
  printf("\nExtendemos la lista\n");
  lista_extender(l, filtro);
  lista_imprimir(l, int_print);
  
  size_t n = 0;
  int *v_final = (int *)lista_a_vector(l, &n);
  
  printf("\nLa pasamos a un vector\n");
  for (int i = 0; i < n; i++)
    printf("%d, ", v_final[i]);
  
  lista_destruir(l, NULL);
  
  return 0;
}



