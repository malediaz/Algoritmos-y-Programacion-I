#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct inventario {
  char descrpcion[30];
  long inventario_num;
  float precio;
  size_t stock;
  int almacenamiento_lugar;
} inventario_t;

typedef struct direcciones {
  char pais[40];
  char provincia[30];
  char ciudad[20];
  char direccion[30];
  int codigo_postal;
} direcciones_t;

typedef struct persona {
  char nombre[30];
  char apellido[30];
  direcciones_t domicilio;
} persona_t;

typedef struct registro {
  long kilometros;
  float pombustible_precio;
  float combustible_compra;
  time_t fecha;
  bool esta_lleno;
  char comentario[50];
} registro_t;
