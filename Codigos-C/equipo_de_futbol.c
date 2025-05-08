#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jugador 
{
    char nombre[30];
    int posicion;
    int numero;
} jugador_t;

typedef struct jugador_nodo 
{
    jugador_t jugador;
    struct jugador_nodo* siguiente;
} jugador_nodo_t;

jugador_nodo_t* ingresar_jugador();
void agregar_jugador(jugador_nodo_t** cabeza, jugador_nodo_t* nuevo);
void mostrar_jugadores(jugador_nodo_t* cabeza);

int main() {
    jugador_nodo_t* lista = NULL;
    int cantidad;
    printf("¿Cuántos jugadores querés ingresar?: ");
    scanf("%d", &cantidad);
    getchar();
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nJugador %d:\n", i + 1);
        jugador_nodo_t* nuevo = ingresar_jugador();
        agregar_jugador(&lista, nuevo);
    }
    printf("\nLista de jugadores ingresados:\n");
    mostrar_jugadores(lista);
    return 0;
}

jugador_nodo_t* ingresar_jugador() {
    int opcion;
    jugador_nodo_t* nuevo = malloc(sizeof(jugador_nodo_t));
    if (!nuevo)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    printf("Nombre del jugador:\n");
    getchar();
    fgets(nuevo->jugador.nombre, 30, stdin);
    nuevo->jugador.nombre[strcspn(nuevo->jugador.nombre, "\n")] = '\0'; 
    printf("Número de camiseta:\n");
    scanf("%d", &nuevo->jugador.numero);
    do {
        printf("Posición del jugador:\n");
        printf("(1) - ARQUERO\n(2) - DEFENSOR\n(3) - MEDICAMPISTA\n(4) - DELANTERO\n");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 4);
    nuevo->jugador.posicion = opcion;
    nuevo->siguiente = NULL;
    return nuevo;
}

void agregar_jugador(jugador_nodo_t** cabeza, jugador_nodo_t* nuevo) {
    if (*cabeza == NULL) 
    {
        *cabeza = nuevo;
    } else 
    {
        jugador_nodo_t* temp = *cabeza;
        while (temp->siguiente != NULL)
            temp = temp->siguiente;
        temp->siguiente = nuevo;
    }
}

void mostrar_jugadores(jugador_nodo_t* cabeza) {
    jugador_nodo_t* actual = cabeza;
    while (actual != NULL) {
        printf("Nombre: %s\n", actual->jugador.nombre);
        printf("Número: %d\n", actual->jugador.numero);
        switch (actual->jugador.posicion) 
        {
            case 1: printf("Posición: Arquero\n"); 
            break;
            case 2: printf("Posición: Defensor\n"); 
            break;
            case 3: printf("Posición: Mediocampista\n"); 
            break;
            case 4: printf("Posición: Delantero\n"); 
            break;
            default: printf("Posición: Desconocida\n"); 
            break;
        }
        printf("----------------------\n");
        actual = actual->siguiente;
    }
}






