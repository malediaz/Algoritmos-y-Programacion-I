#include <stdio.h>

unsigned char Rojo(unsigned int rgb) {
  return (rgb >> 16) & 0xFF;
}
  
unsigned char Verde(unsigned int rgb) {
  return (rgb >> 8) & 0xFF;
}

unsigned char Azul(unsigned int rgb) {
  return rgb & 0xFF;
}

void componentesRGB(unsigned int rgb, unsigned char *r, unsigned char *g, unsigned char *b) {
  *r = Rojo(rgb);
  *g = Verde(rgb);
  *b = Azul(rgb);
}

int main() {
  unsigned int rgb = 0x30F4A7;
  unsigned char r = 0, g = 0, b = 0;
    
  componentesRGB(rgb, &r, &g, &b);
    
  printf("RGB: 0x%X\nRed: 0x%X\nGreen: 0x%X\nBlue: 0x%X", rgb,r, g, b);
    
  return 0;
}
