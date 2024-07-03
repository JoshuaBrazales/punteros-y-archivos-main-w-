#include <stdio.h>

#define MAX_GENEROS 5

typedef struct {
    int vinilos;
    int cds;
    int cassettes;
} Inventario;

extern const char* generos[MAX_GENEROS];

void ingresarInventario(Inventario* inventario);
void guardarInventario(Inventario* inventario);

int main() {
    Inventario inventario[MAX_GENEROS] = {0};

    printf("Bienvenido al inventario. A continuación, agregue los datos de cada género.\n");

    ingresarInventario(inventario);

    guardarInventario(inventario);

    return 0;
}

