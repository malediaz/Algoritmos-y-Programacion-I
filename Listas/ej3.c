#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "listas.h"

typedef lista_t lista_iterador_t;

lista_iterador_t *lista_iterador_crear(lista_t *l) {
  return lista_crear(l);
}
