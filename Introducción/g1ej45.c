#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int c, nl = 0, ns = 0, nt = 0, nc = 0;
  
  printf("Ingrese un texto a elección:\n");
  
  while ((c = getchar()) != EOF) {
    if (c == '\t')
      nt++;
    if (c == ' ')
      ns++;
    if (c == '\n')
      nl++;
    if (c >= 91 && c <= 122)
      nc++;
    }
    
  printf("____\nLa cantidad de saltos de lineas que contiene el texto es de %d\n",nl);
  printf("La cantidad de tabulaciones que contiene el texto es de %d\n",nt);
  printf("La cantidad de espacios que contiene el texto es de %d\n",ns);
  printf("La cantidad de letras que contiene el texto es de %d\n",nc);

  return 0;
}
