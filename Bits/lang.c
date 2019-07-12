#include <stdio.h>

#define LANG_MASK 0xC
#define SHIFT_LANG 2

typedef enum lang {ESP, ENG, FRE, GER} lang_t;
char *idioma[] = {"español","ingles","frances","aleman"};

lang_t obtener_lang(unsigned char *reg);

int main(int argc, char const *argv[]) {
  unsigned char reg = 0x8;
  fprintf(stdout, "%s\n", idioma[obtener_lang(&reg)]);
  
  return 0;
}

lang_t obtener_lang(unsigned char *reg){
  return (*reg & LANG_MASK) >> SHIFT_LANG;
}
