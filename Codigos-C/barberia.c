#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 30


typedef struct 
{
    char nombre[MAX_CHAR];
    float precio;
    int duracion;
}servicio_t;


void menu_principal();
void menu_duenio();
int gestion_password();
void agregar_servicio();

int main(){
    menu_principal();
}

void menu_principal(){
    int opcion;

    do
    {
        printf("\n-------MENU------\n");
        printf("1. Gestion.\n");
        printf("2. Menu para clientes.\n");
        printf("3. Salir.\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);
        getchar();

        switch (opcion)
        {
            case 9:
                if (gestion_password())
                {
                    menu_duenio();
                }else
                {
                    printf("Contraseña incorrecta.");
                }
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


int gestion_password(void) {
    char password[MAX_CHAR];
    const char clave_valida[] = "Ellimiteeselcielo";  

    printf("Ingrese contraseña de administrador: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    return strcmp(password, clave_valida) == 0;
}


void menu_duenio(){
    int opcion;

    do
    {
        printf("\n--------MENU------\n");
        printf("1. Agregar servicios.\n");
        printf("2. Eliminar/Modificar servicio.\n");
        printf("3.  Menu principal.\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);
        getchar();

        switch (opcion)
        {
            case 1:
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
    } while (opcion!=4);
}

void agregar_servicio(){
    servicio_t s;
    printf("Nombre del servicio:\n");
    fgets(s.nombre,MAX_CHAR,stdin);
    getchar();

    printf("Precio del servicio:\n");
    scanf("%f",&s.precio);
    getchar();

    printf("Duracion del servicio (en minutos):\n");
    scanf("%d",&s.duracion);
    getchar();

    FILE *archivo =fopen("servicios.txt","a");
    if (!archivo)
    {
        printf("No se pudo abrir el archivo.");
        return;
    }

    fprintf(archivo,"%s|%.2f|%d",s.nombre,s.precio,s.duracion);
    fclose(archivo);

    printf("Se agrego el servicio.");
}

