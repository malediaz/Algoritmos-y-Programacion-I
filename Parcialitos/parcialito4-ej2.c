#include <stdlib.h>

typedef struct {
  struct nodo *prim;
} lista_t;

struct nodo {
  struct nodo *sig; 
  int dato;
};

void lista_enteros_borrar(lista_t *l, int dato) {  
  while (l->prim != NULL && l->prim->dato == dato) {
    struct nodo *sig = l->prim->sig;
    free(l->prim);
    l->prim = sig;
  }
  
  if (l->prim == NULL)
    return;
  
  struct nodo *act = l->prim->sig;
  struct nodo *ant = l->prim;
  
  while (act != NULL) {
    if (act->dato == dato) {
      ant->sig = act->sig;
      free(act);
      act = ant->sig;
    }
  }
}

  
