#include <stdio.h>
#include <stlib.h>
#include <string.h>

#define MAX_CHAR 30
#define 

typedef struct 
{
    char nombre[MAX_CHAR];
    float precios;
    int duración;
}servicios_t;

void menu_principal();
void menu_duenio();
void agregar_servicio();

int main{

}

void menu_principal{
    int opcion;
    do
    {
        printf("-------MENU------");
        printf("1. Gestion.");
        printf("2. Menu para clientes.");
        printf("3. Salir.");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);
        switch (opcion)
        {
            case 9:
                menu_duenio();
                break;
            case 2:
                // aca va a estra el menu del cliente
                break;
            case 3:
                printf("Saliendo...");
                break;
        default:
                printf("Esta opcion no es valida.");
                break;
        }
    } while (opcion!=3);
}

void menu_duenio(){
    int opcion;
    do
    {
        printf("--------MENU------");
        printf("1. Agregar servicios");
        printf("2. Eliminar/Modificar servicio");
        printf("3.  Menu principal.");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);
        switch (opcion)
        {
            case:
                agregar_servicio();
                break;
            case 2:
                //Eliminar/Modificar servicios
                break;
            case 3:
                menu_principal();
            default:
                printf("Esta opcion no es valida.");
                break;
        }
    } while (opcion!=2);
}

agregar_servicio(){

}
