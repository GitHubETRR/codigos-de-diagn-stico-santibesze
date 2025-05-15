#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50

typedef struct producto {
    char nombre[MAX_CHAR];
    struct producto* siguiente;
} producto_t;

producto_t* anotar_producto();
void ordenar_lista(producto_t** cabeza, producto_t* nuevo);
void mostrar_lista(producto_t* cabeza);
void eliminar_producto(producto_t** cabeza, char nombre[]);

int main() {
    producto_t* lista = NULL;
    int opcion;
    char nombre[MAX_CHAR];
    do {
        printf("------ MENU ------\n");
        printf("(1) - Anotar producto\n");
        printf("(2) - Mostrar lista\n");
        printf("(3) - Eliminar producto\n");
        printf("(0) - Salir\n");
        scanf("%d", &opcion);
        getchar();
        switch (opcion) {
            case 1:
                {
                producto_t* nuevo = anotar_producto();
                ordenar_lista(&lista, nuevo);
                }
                break;
            case 2:
                mostrar_lista(lista);
                break;
            case 3:
                printf("Nombre del producto que queres eliminar:\n");
                scanf("%s", nombre);
                eliminar_producto(&lista, nombre);
                break;
            case 0:
                printf("Chau...\n");
                break;
            default:
                printf("No es valido\n");
                break;
        }
    } while (opcion != 0);
    while (lista != NULL) {
        producto_t* temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
    return 0;
}

producto_t* anotar_producto() {
    producto_t* nuevo = malloc(sizeof(producto_t));
    if (!nuevo) exit(1);
    printf("Nombre del producto: ");
    scanf("%s", nuevo->nombre);
    nuevo->siguiente = NULL;
    return nuevo;
}

void ordenar_lista(producto_t** cabeza, producto_t* nuevo) {
    if (*cabeza == NULL) 
    {
        *cabeza = nuevo;
    } else 
    {
        producto_t* temp = *cabeza;
        while (temp->siguiente != NULL)
            temp = temp->siguiente;
        temp->siguiente = nuevo;
    }
}

void mostrar_lista(producto_t* cabeza) {
    if (cabeza == NULL) 
    {
        printf("La lista esta completada, ya esta todo en el changuito.\n");
        printf("Podes ir a pagar.\n");
        return;
    }
    printf("Productos que faltan:\n");
    producto_t* actual = cabeza;
    while (actual != NULL) {
        printf(".%s\n", actual->nombre);
        actual = actual->siguiente;
    }
}

void eliminar_producto(producto_t** cabeza, char nombre[]) {
    producto_t* actual = *cabeza;
    producto_t* anterior = NULL;
    while (actual != NULL && strcmp(actual->nombre, nombre) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL) 
    {
        printf("Producto '%s' no encontrado.\n", nombre);
        return;
    }
    if (anterior == NULL) 
    {
        *cabeza = actual->siguiente;
    } else 
    {
        anterior->siguiente = actual->siguiente;
    }
    free(actual);
    printf("Producto '%s' eliminado correctamente.\n", nombre);
}


