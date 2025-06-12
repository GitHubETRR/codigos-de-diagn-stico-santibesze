#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 30

typedef struct jugador
{
    char nombre[MAX_NOMBRE];
    int posicion;
    int numero;
    struct jugador *siguiente;
} jugador_t;

jugador_t *ingresar_jugador();
void agregar_jugador(jugador_t **cabeza, jugador_t *nuevo);
void mostrar_jugadores(jugador_t *cabeza);

int main()
{
    jugador_t *lista = NULL; // Se agregan jugadores a una lista vacía
    int cantidad;
    printf("¿Cuántos jugadores querés ingresar?: ");
    scanf("%d", &cantidad);
    getchar();
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nJugador %d:\n", i + 1);
        jugador_t *nuevo = ingresar_jugador(); // Llama a la funcion, pide los datos del jugador y vuelve a cargarlos
        agregar_jugador(&lista, nuevo);
    }
    printf("\nLista de jugadores ingresados:\n");
    mostrar_jugadores(lista);
    while (lista != NULL)
    {
        jugador_t *temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
    return 0;
}

jugador_t *ingresar_jugador()
{
    int opcion;
    jugador_t *nuevo = malloc(sizeof(jugador_t)); // Memoria dinamica que guardaa un espacio en memoria, crea un puntero del tamaño de "jugador_nodo_t" que indica al nodo donde esta ese espacio
    if (!nuevo)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    printf("Nombre del jugador:\n");
    fgets(nuevo->nombre, MAX_NOMBRE, stdin);
    nuevo->nombre[strcspn(nuevo->nombre, "\n")] = '\0';
    printf("Número de camiseta:\n");
    scanf("%d", &nuevo->numero);
    do
    {
        printf("Posición del jugador:\n");
        printf("(1) - ARQUERO\n(2) - DEFENSOR\n(3) - MEDIOCAMPISTA\n(4) - DELANTERO\n");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 4);
    nuevo->posicion = opcion;
    nuevo->siguiente = NULL;
    getchar();
    return nuevo;
}

void agregar_jugador(jugador_t **cabeza, jugador_t *nuevo)
{
    if (*cabeza == NULL)
    {
        *cabeza = nuevo;
    }
    else
    {
        jugador_t *temp = *cabeza;
        while (temp->siguiente != NULL) // Recorre la lista y se agrega el nuevo al final de la lista
            temp = temp->siguiente;
        temp->siguiente = nuevo;
    }
}

void mostrar_jugadores(jugador_t *cabeza)
{
    jugador_t *actual = cabeza; // El puntero actual empeiza desde "cabeza" (primero nodo) y recorre la lsta
    if (actual == NULL)
    {
        printf("No hay jugadores ingresados.\n");
        return;
    }
    while (actual != NULL)
    {
        printf("Nombre: %s\n", actual->nombre);
        printf("Número: %d\n", actual->numero);
        switch (actual->posicion)
        {
        case 1:
            printf("Posición: Arquero\n");
            break;
        case 2:
            printf("Posición: Defensor\n");
            break;
        case 3:
            printf("Posición: Mediocampista\n");
            break;
        case 4:
            printf("Posición: Delantero\n");
            break;
        default:
            printf("Posición: Desconocida\n");
            break;
        }
        printf("----------------------\n");
        actual = actual->siguiente; // Una vez termina, pasa al siguiente jugador
    }
}