#include <stdio.h>

#define MAX 100

int main(void) {
  char str[] = "Winter is coming";
  puts(str);
  
  char str1[17] = {'W', 'i', 'n', 't', 'e', 'r', ' ', 'i', 's', ' ', 'c', 'o', 'm', 'i', 'n', 'g', '\0'};
  puts(str1);
  
  char *str2[] = {"Winter ", "is ", "coming\0"};
  for (int i = 0; i < 3; i++)
    puts(*(str2 + i));

  printf("%ld\n", sizeof(str));
  
  printf("Inserte una cadena de caracteres: ");
  
  char cadena[MAX];
  fgets(cadena, MAX, stdin);
  
  for (int i = 0; i < MAX; i++) {
    if (cadena[i] == '\0')
      return 0;
    
    printf("%c", cadena[i]);
  }
  
  return 0;
}
