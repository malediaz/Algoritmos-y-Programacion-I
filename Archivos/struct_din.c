#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAQUETE 20
#define MAX 50

typedef struct{
    char nombre[MAX];
    unsigned int dni;
    float altura;
}persona_t;

int main(int argc, char const *argv[]) {
    FILE *f;
    persona_t persona[4] = {
        {"manuel",4352523,343},
        {"pablo",3434554,452},
        {"chino",4352523,123},
        {"japa",3434554,452}
    };
    f = fopen("escritura","w");

    fwrite(persona,sizeof(persona_t),4,f);

    fclose(f);

    f = fopen("escritura","r");
    size_t n = 0;
    persona_t *persona2 = malloc(sizeof(persona_t) * PAQUETE);
    size_t leidos;

    while((leidos = fread(persona2 + n, sizeof(persona_t), PAQUETE, f)) == PAQUETE ){
        
        n += PAQUETE;
        persona_t * aux = realloc(persona2,sizeof(persona_t) * (n+PAQUETE));
        if (aux == NULL) {
            free(persona2);
            return EXIT_FAILURE;
        }
        persona2 = aux;
        
    }

    fclose(f);
    printf("%zd\n",leidos);
    n += leidos;

    for (size_t i = 0; i < n; i++) {
        fprintf(stdout, "%s;%d;%f\n",(persona2+i)->nombre,(persona2+i)->dni,(persona2+i)->altura);
    }
    free(persona2);

    return 0;
}
