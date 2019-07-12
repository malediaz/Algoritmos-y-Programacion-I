#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX 100
#define HELP "--help"


// (1)

// a)
struct polinomio {
  double *coeficientes;
  size_t grado;
};

typedef struct polinomio polinomio_t;


// b)
double polinomio_evaluar(const polinomio_t *p, double x) {
  double resultado = 0;
  
  for (size_t i = 0;i < p->grado; i++)
    resultado += (p->coeficientes[i] * pow(x, i));
  
  return resultado;
}


// c)
polinomio_t *polinomio_derivar(const polinomio_t *p) {
  polinomio_t *p_prima = malloc(sizeof(polinomio_t));
  
  if (p_prima == NULL)
    return NULL;
    
  p_prima->coeficientes = malloc(sizeof(double) * (p->grado - 1));
  
  if (p_prima->coeficientes == NULL) {
    free(p_prima);
    
    return NULL;
  }                                       // O uso el polinomio_crear()
  
  p_prima->grado = p->grado - 1;
  
  for (size_t i = 0; i < p_prima->grado; i++)
    p_prima->coeficientes[i] = p->coeficientes[i + 1] * (i + 1);
    
  return p_prima;
}
    

// (2) ----------------------------------------------------------------------------------------

// a)

typedef struct {
  char nombre[MAX];
  unsigned int dni;
  float altura;
} persona_t;


bool leer_persona(FILE *f, persona_t *p) {
  if (f == NULL || p == NULL)
    return false;
    
  if (fread(p, sizeof(persona_t), 1, f) != 1)
    return false;
    
  return true;
}

void escribir_persona(FILE *f, const persona_t *p) {
  fprintf(f, "%s;%d;%f\n", p->nombre, p->dni, p->altura);
}

bool leer_personas(const char *r, persona_t v[], size_t max, size_t *n) {
  FILE *binario = NULL;
  
  if ((binario = fopen(r, "rb")) == NULL)
    return false;
  
  int leidos;  
  leidos = fread(v, sizeof(persona_t), max, binario);
    
  *n = leidos;
  
  fclose(binario);
  
  return true;
}


// (3) -----------------------------------------------------------------------------------

int main (int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Ingreso incorrecto.\n");
    
    return EXIT_FAILURE;
  }
  
  if (strcmp(argv[1], HELP) == 0) {
    fprintf(stderr, "El formato de ingreso es <%s> <archivo binario>.\n", argv[0]);
    
    return 0;
  }
  
  /*FILE *binario = NULL;

  
  if ((binario = fopen(argv[1], "w+")) == NULL) {
    fprintf(stderr, "Hubo un problema al abrir el archivo <%s>.\n", argv[1]);
    
    return EXIT_FAILURE;
  }
  
  const persona_t p[MAX] = {
    {"Male", 41453171, 1.65},
    {"Pepe", 2345345, 2.0}
  };
  
  fwrite(p, sizeof(persona_t), 2, binario);
  fclose(binario);
  */
  
  persona_t ppl[MAX];
  size_t n = 0;
  
  if (!leer_personas(argv[1], ppl, MAX, &n)) {
    fprintf(stderr, "Hubo un error en la lectura del archivo <%s>.\n", argv[1]);
    
    return EXIT_FAILURE;
  }
  
  for (size_t i = 0; i < n; i++)
    escribir_persona(stdout, &ppl[i]);


  return 0;
}
  
    
    
    
    
  
  
