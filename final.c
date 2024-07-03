#include <stdio.h>

#define MAX_GENEROS 5

typedef struct {
    int vinilos;
    int cds;
    int cassettes;
} Inventario;

extern const char* generos[MAX_GENEROS];

void cargarInventario(Inventario* inventario);
void mostrarInventario(Inventario* inventario);
void modificarInventario(Inventario* inventario);
void guardarInventario(Inventario* inventario);

int main() {
    Inventario inventario[MAX_GENEROS] = {0};
    char continuar;

    printf("Bienvenido al inventario.\n");

    // Cargar el inventario desde el archivo
    cargarInventario(inventario);

    do {
        mostrarInventario(inventario);
        printf("\n¿Quiere modificar la información de algún género? (s/n): ");
        scanf(" %c", &continuar);

        if (continuar == 's') {
            modificarInventario(inventario);
        }
    } while (continuar == 's');

    // Guardar el inventario en el archivo
    guardarInventario(inventario);

    printf("Gracias por ingresar los datos\n");
    return 0;
}
