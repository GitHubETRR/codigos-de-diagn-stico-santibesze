#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_CORTES 10

void elegir_corte(char** corte_elegido, char* cortes[], int cantidad);


int main() {
    srand(time(NULL));
    char* cortes[CANT_CORTES] = {
        "Skin fade",
        "Buzz cut",
        "Taper fade",
        "Corte clásico",
        "Mullet"
    };
    char* corte = NULL;
    elegir_corte(&corte, cortes);
    printf("¡El corte elegido es: %s!\n", corte);
    return 0;
}

void elegir_corte(char** corte_elegido, char* cortes[], int cantidad) {
    int indice = rand() % cantidad;
    *corte_elegido = cortes[indice];
}