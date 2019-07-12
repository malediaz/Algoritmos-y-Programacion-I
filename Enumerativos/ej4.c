#include <stdio.h>

typedef enum meses {
  ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE,
  OCTUBRE, NOVIEMBRE, DICIEMBRE
} meses_t;

const char *mes_nombre[] = {
  [ENERO] = "Enero",
  [FEBRERO] = "Fabrero",
  [MARZO] = "Marzo",
  [ABRIL] = "Abril",
  [MAYO] = "Mayo",
  [JUNIO] = "Junio",
  [JULIO] = "Julio",
  [AGOSTO] = "Agosto",
  [SEPTIEMBRE] = "Septiembre",
  [OCTUBRE] = "Octubre",
  [NOVIEMBRE] = "Noviembre",
  [DICIEMBRE] = "Diciembre",
};

int main(void) {
  meses_t mes = MARZO;
  printf("%s", mes_nombre[mes]);
  
  return 0;
}


  
  
