#ifndef _LISTAS_H_
#define _LISTAS_H_

typedef struct lista lista_t;

lista_t *lista_crear();
void lista_destruir(lista_t *l, void (*destruir_dato)(void *d));
bool lista_es_vacia(const lista_t *l);
bool lista_insertar_comienzo(lista_t *l, void *d);
bool lista_insertar_final(lista_t *l, void *d);
void *lista_extraer_primero(lista_t *l);
void *lista_extraer_ultimo(lista_t *l);
void *lista_buscar(const lista_t *l, const void *dato, int (*cmp)(const void *a, const void *b));
void *lista_borrar(lista_t *l, const void *dato, int (*cmp)(const void *a, const void *b));
void lista_recorrer(const lista_t *l, bool (*visitar)(const void *dato, void *extra), void *extra);
void lista_mapear(lista_t *l, void *(*f)(void *dato));
lista_t *lista_filtrar(lista_t *l, bool (*f)(void *dato));
bool lista_extender(lista_t *a, const lista_t *b);
void **lista_a_vector(const lista_t *l, size_t *n);

#endif //_LISTAS_H_
