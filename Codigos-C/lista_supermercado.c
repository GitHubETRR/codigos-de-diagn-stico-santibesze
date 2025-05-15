#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50

<<<<<<< HEAD
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
=======
typedef struct prducto
{
    char nombre[MAX_CHAR];
    struct producto* siguiente;
}producto_t;

producto_t* anotar_producto();
void ordenar_lista(product_t** cabeza, product_t* nuevo);
void mostrar_lista(producto_t* cabeza);
void eliminar_lista(producto_t** cabeza, producto_t* anterior);

int main(){
    
>>>>>>> 80cf2fbf7656d83c63be7ea4c872a2091fb02f62
}

producto_t* anotar_producto() {
    producto_t* nuevo = malloc(sizeof(producto_t));
<<<<<<< HEAD
    if (!nuevo) exit(1);
    printf("Nombre del producto: ");
    scanf("%s", nuevo->nombre);
=======
    if (!nuevo)
    {
        printf("Error al asignar memoria.");
    }
    printf("Nombre del producto: ");
    fgets(nuevo->nombre, MAX_CHAR, stdin);
    nuevo->nombre[strcspn(nuevo->nombre, "\n")] = '\0';
>>>>>>> 80cf2fbf7656d83c63be7ea4c872a2091fb02f62
    nuevo->siguiente = NULL;
    return nuevo;
}

<<<<<<< HEAD
void ordenar_lista(producto_t** cabeza, producto_t* nuevo) {
    if (*cabeza == NULL) 
    {
        *cabeza = nuevo;
    } else 
    {
        producto_t* temp = *cabeza;
        while (temp->siguiente != NULL)
            temp = temp->siguiente;
=======
void ordenar_lista(product_t** cabeza, product_t* nuevo){
    if (*cabeza=NULL)
    {
        *cabeza = nuevo;
    }
    else
    {
        producto_t* temp = *cabeza;
        while(temp->siguiente != NULL)
        temp = temp->siguiente; 
>>>>>>> 80cf2fbf7656d83c63be7ea4c872a2091fb02f62
        temp->siguiente = nuevo;
    }
}

<<<<<<< HEAD
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
=======
void mostrar_lista(producto_t* cabeza){
    producto_t* actual = cabeza;
    if (*cabeza=NULL)
    {
        printf("La lista estga completada , ya esta todo en el changuito.\n");
        printf("Podes ir a pagar."); 
    }
    printf("Productos que faltan:");
    while (actual != NULL)
    {
>>>>>>> 80cf2fbf7656d83c63be7ea4c872a2091fb02f62
        printf(".%s\n", actual->nombre);
        actual = actual->siguiente;
    }
}

<<<<<<< HEAD
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


=======
void eliminar_lista(producto_t** cabeza, constant char* nombre){
    producto_t* actual = *cabeza:
    producto_t* anterior = NULL;
    printf("Que producto queres eliminar?")
    if (condition)
    {
        /* code */
    }
    
}




>>>>>>> 80cf2fbf7656d83c63be7ea4c872a2091fb02f62
