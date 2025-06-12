#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 50

void menu();
void guardar_productos();
void mostrar_productos();

int main(){
    menu();
    return 0;
}


void menu(){
    int opcion;
    do
    {
        printf("\n------MENU------\n");
        printf("(1) - Anotar productos\n");
        printf("(2) - Ver lista\n");
        printf("(3) - Salir\n");
        scanf("%d",&opcion);
        getchar();
        switch (opcion)
        {
            case 1:
                guardar_productos();
                break;
            case 2:
                mostrar_productos();
                break;
            case 3:
                printf("Chau...");
                break;
            default:
                printf("No esxiste esta opción.");
                break;
        }
    } while (opcion!=3);
}

void guardar_productos(){
    char producto[MAX_CHAR];
    FILE* archivo = fopen("lista.txt","a");
    if (archivo==NULL)
    {
        printf("No se pudo abrir el archivo");
        return;
    }
    printf("Nombre del producto: ");
    fgets(producto, MAX_CHAR, stdin);
    fputs(producto, archivo);
    fclose(archivo);
    printf("Producto guardado.");
}

void mostrar_productos(){
    FILE* archivo = fopen("lista.txt", "r"); 
    if (!archivo) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    char linea[MAX_CHAR];
    printf("Productos guardados:\n");
    while (fgets(linea, MAX_CHAR, archivo)) {
        printf("- %s", linea);
    }
    fclose(archivo);
}