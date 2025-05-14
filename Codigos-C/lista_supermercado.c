#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50

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
    
}

producto_t* anotar_producto() {
    producto_t* nuevo = malloc(sizeof(producto_t));
    if (!nuevo)
    {
        printf("Error al asignar memoria.");
    }
    printf("Nombre del producto: ");
    fgets(nuevo->nombre, MAX_CHAR, stdin);
    nuevo->nombre[strcspn(nuevo->nombre, "\n")] = '\0';
    nuevo->siguiente = NULL;
    return nuevo;
}

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
        temp->siguiente = nuevo;
    }
}

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
        printf(".%s\n", actual->nombre);
        actual = actual->siguiente;
    }
}

void eliminar_lista(producto_t** cabeza, constant char* nombre){
    producto_t* actual = *cabeza:
    producto_t* anterior = NULL;
    printf("Que producto queres eliminar?")
    if (condition)
    {
        /* code */
    }
    
}




