#include <stdio.h>
#include <string.h>

#define FILENAME "inventario.txt"
#define MAX_GENEROS 5

typedef struct {
    int vinilos;
    int cds;
    int cassettes;
} Inventario;

const char* generos[MAX_GENEROS] = {"Jazz", "Funk", "Pop", "Reguetón", "Clásico"};

void mostrarInventario(Inventario* inventario) {
    printf("\nEste es el inventario actual:\n");
    for (int i = 0; i < MAX_GENEROS; i++) {
        printf("%s\n", generos[i]);
        printf("Vinilos: %d\n", inventario[i].vinilos);
        printf("CDs: %d\n", inventario[i].cds);
        printf("Cassettes: %d\n", inventario[i].cassettes);
    }
}

void ingresarInventario(Inventario* inventario) {
    for (int i = 0; i < MAX_GENEROS; i++) {
        printf("\nIngrese los datos de %s:\n", generos[i]);
        
        do {
            printf("Cantidad de vinilos: ");
            scanf("%d", &inventario[i].vinilos);
            if (inventario[i].vinilos < 0) {
                printf("No se debe ingresar números negativos. Intente nuevamente.\n");
            }
        } while (inventario[i].vinilos < 0);

        do {
            printf("Cantidad de CDs: ");
            scanf("%d", &inventario[i].cds);
            if (inventario[i].cds < 0) {
                printf("No se debe ingresar números negativos. Intente nuevamente.\n");
            }
        } while (inventario[i].cds < 0);

        do {
            printf("Cantidad de cassettes: ");
            scanf("%d", &inventario[i].cassettes);
            if (inventario[i].cassettes < 0) {
                printf("No se debe ingresar números negativos. Intente nuevamente.\n");
            }
        } while (inventario[i].cassettes < 0);
    }
}

void modificarInventario(Inventario* inventario) {
    char genero[50];
    int generoIndex = -1;

    printf("\nIngrese el nombre del género que quiere editar: ");
    scanf(" %49[^\n]", genero);

    for (int i = 0; i < MAX_GENEROS; i++) {
        if (strcmp(genero, generos[i]) == 0) {
            generoIndex = i;
            break;
        }
    }

    if (generoIndex != -1) {
        do {
            printf("\nAhora estás modificando datos para el género %s:\n", generos[generoIndex]);
            printf("Cantidad de vinilos (actual: %d): ", inventario[generoIndex].vinilos);
            scanf("%d", &inventario[generoIndex].vinilos);
            if (inventario[generoIndex].vinilos < 0) {
                printf("No se debe ingresar números negativos. Intente nuevamente.\n");
            }
        } while (inventario[generoIndex].vinilos < 0);

        do {
            printf("Cantidad de CDs (actual: %d): ", inventario[generoIndex].cds);
            scanf("%d", &inventario[generoIndex].cds);
            if (inventario[generoIndex].cds < 0) {
                printf("No se debe ingresar números negativos. Intente nuevamente.\n");
            }
        } while (inventario[generoIndex].cds < 0);

        do {
            printf("Cantidad de cassettes (actual: %d): ", inventario[generoIndex].cassettes);
            scanf("%d", &inventario[generoIndex].cassettes);
            if (inventario[generoIndex].cassettes < 0) {
                printf("No se debe ingresar números negativos. Intente nuevamente.\n");
            }
        } while (inventario[generoIndex].cassettes < 0);
    } else {
        printf("Género no válido.\n");
    }
}

void guardarInventario(Inventario* inventario) {
    FILE* archivo = fopen(FILENAME, "w"); // Cambiado a "w" para sobrescribir el archivo
    if (archivo == NULL) {
        perror("Error al abrir el archivo para guardar");
        return;
    }

    for (int i = 0; i < MAX_GENEROS; i++) {
        fprintf(archivo, "%d %d %d\n", inventario[i].vinilos, inventario[i].cds, inventario[i].cassettes);
    }

    fclose(archivo);
}

void cargarInventario(Inventario* inventario) {
    FILE* archivo = fopen(FILENAME, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para cargar");
        return;
    }

    for (int i = 0; i < MAX_GENEROS; i++) {
        if (fscanf(archivo, "%d %d %d", &inventario[i].vinilos, &inventario[i].cds, &inventario[i].cassettes) != 3) {
            perror("Error al leer los datos del archivo");
            break;
        }
    }

    fclose(archivo);
}
