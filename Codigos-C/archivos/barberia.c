#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50


typedef struct 
{
    char nombre[MAX_CHAR];
    char precio [MAX_CHAR];
    char duracion [MAX_CHAR];
}servicio_t;



void menu_principal();

void menu_duenio();
int gestion_password();
void agregar_servicio();
void eliminar_servicios();

void menu_cliente();
void mostrar_servicios();
void solicitar_turno();
void agenda();
void turnos_libres();
void todos_los_turnos();


int main(){
    agenda();
    menu_principal();
    return 0;
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
                menu_cliente();
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
        printf("3. Ver lista completa de turnos.\n")
        printf("4. Menu principal.\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);
        getchar();

        switch (opcion)
        {
            case 1:
                agregar_servicio();
                break;
            case 2:
                eliminar_servicios();
                break;
            case 3:
                todos_los_turnos();
                break;
            case 4:
                menu_principal();
                break;
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
    s.nombre[strcspn(s.nombre, "\n")] = 0;

    printf("Precio del servicio:\n");
    fgets(s.precio,MAX_CHAR,stdin);
    s.precio[strcspn(s.precio, "\n")]   = 0;

    printf("Duracion del servicio (en minutos):\n");
    fgets(s.duracion,MAX_CHAR,stdin);
    s.duracion[strcspn(s.duracion, "\n")] = 0;

    FILE *archivo =fopen("servicios.txt","a");
    if (!archivo)
    {
        printf("No se pudo abrir el archivo.");
        return;
    }

    fprintf(archivo,"%s|%s|%s\n",s.nombre,s.precio,s.duracion);
    fclose(archivo);

    printf("Se agrego el servicio.");
}


void eliminar_servicios(){
    servicio_t s;
    char buscador[MAX_CHAR];
    char linea1[MAX_CHAR];
    char linea2[MAX_CHAR];
    char linea3[MAX_CHAR];
    int eliminado = 0;
    int opcion;


    printf("Nombre del servicio: ");
    fgets(buscador,MAX_CHAR,stdin);

    FILE *original =fopen("servicios.txt","r");
    FILE *temporal =fopen("temp.txt","w");

    if (!original||!temporal)
    {
        printf("No se pudo abrir el archivo.");
        return;
    }

    while (fgets(linea1, sizeof(linea1), original)){
        fgets(linea2, sizeof(linea2), original);
        fgets(linea3, sizeof(linea3), original);
        
        strcpy(s.nombre, linea1);
        strcpy(s.precio, linea2);
        strcpy(s.duracion, linea3);
        
        if (strcmp(s.nombre, buscador) == 0)
        {
            eliminado = 1;

            printf("Servicio encontrado:");
            printf("%s | %s | %s",s.nombre, s.precio, s.duracion);
            printf("Eliminar(1) - Modificar(2) - Cancelar(3)");
            scanf("%d", &opcion);
            getchar();

            if (opcion==1)
            {
                printf("Se eliminó.");
                continue;
            }else if (opcion==2)
            {
                printf("Nuevo nombre: ");
                fgets(s.nombre, MAX_CHAR, stdin);

                printf("Nuevo precio: ");
                fgets(s.precio, MAX_CHAR, stdin);
                
                printf("Duración: ");
                fgets(s.duracion, MAX_CHAR, stdin);

                fprintf(temporal,"%s\n", s.nombre);
                fprintf(temporal,"%s\n", s.precio);
                fprintf(temporal,"%s\n", s.duracion);
                continue;
            }
        }
        fputs(linea1, temporal);
        fputs(linea2, temporal);
        fputs(linea3, temporal);
    } 
    fclose(original);
    fclose(temporal);

    remove("servicios.txt");
    rename("temp.txt", "servicios.txt");

    if (!eliminado)
    {
        printf("No se encontro un servicio con ese nombre");
        return;
    }
}


void menu_cliente(){
    int opcion;
    do
    {
        printf("\n-------MENU CLIENTE------\n");
        printf("1. Mostrar servicios.\n");
        printf("2. Solicitar turno.\n");
        printf("3. Ver turnos disponibles\n");
        printf("4. Volver al menú principal\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion)
        {
        case 1:
            mostrar_servicios();
            break;
        case 2:
            solicitar_turno();
            break;
        case 3:
            turnos_libres();
            break;
        case 4:
            printf("Volviendo al menú principal...");
            break;
        default :
            printf("No es valida esta opción.");
            break;
        }
    } while (opcion!=4);
    
}


void mostrar_servicios() {
    FILE *f = fopen("servicios.txt", "r");
    if (!f) { printf("No hay servicios cargados\n"); return; }

    char nombre[MAX_CHAR], precio[MAX_CHAR], duracion[MAX_CHAR];
    int nro = 1;

    printf("\n-------LISTA DE SERVICIOS-------\n");
    while (fgets(nombre, sizeof(nombre), f)) {
        fgets(precio,   sizeof(precio),   f);
        fgets(duracion, sizeof(duracion), f);

        nombre  [strcspn(nombre,  "\n")] = 0;
        precio  [strcspn(precio,  "\n")] = 0;
        duracion[strcspn(duracion,"\n")] = 0;

        printf("%2d) %-20s  |  %-10s  |  %s\n",
               nro++, nombre, precio, duracion);
    }
    fclose(f);
}

void agenda() {
    FILE *f = fopen("agenda.txt", "r");
    if (f) {
        fclose(f);  
        return;
    }

    f = fopen("agenda.txt", "w");
    if (!f) {
        printf("No se pudo crear agenda\n");
        return;
    }

    for (int hora = 10; hora <= 17; hora++) {
        fprintf(f, "%02d:00|Libre\n", hora);
        fprintf(f, "%02d:30|Libre\n", hora);
    }
    fprintf(f, "18:00|Libre\n");

    fclose(f);
}


void turnos_libres()
{

    FILE *f = fopen("agenda.txt", "r");
    if (!f) { puts("No se pudo abrir agenda.txt"); return; }

    char linea[30];
    int idx = 1;
    printf("\n--- TURNOS DISPONIBLES ---\n");
    while (fgets(linea, sizeof(linea), f)) {
        char hora[10], estado[10];
        sscanf(linea, "%[^|]|%s", hora, estado);
        if (strcmp(estado, "Libre") == 0)
            printf("%2d) %s\n", idx, hora);
        idx++;
    }
    fclose(f);
}


int marcar_turno_ocupado(int nro_turno) {
    FILE *f = fopen("agenda.txt", "r");
    FILE *temp = fopen("temp_agenda.txt", "w");
    if (!f || !temp) {
        printf("Error al abrir los archivos.\n");
        return 0;
    }

    char linea[30];
    int idx = 1, marcado = 0;

    while (fgets(linea, sizeof(linea), f)) {
        char hora[10], estado[10];
        sscanf(linea, "%[^|]|%s", hora, estado);

        if (idx == nro_turno && strcmp(estado, "Libre") == 0) {
            fprintf(temp, "%s|Ocupado\n", hora);
            marcado = 1;
        } else {
            fputs(linea, temp);
        }
        idx++;
    }

    fclose(f);
    fclose(temp);
    remove("agenda.txt");
    rename("temp_agenda.txt", "agenda.txt");

    return marcado;
}


void  todos_los_turnos()
{
    FILE *f = fopen("agenda.txt", "r");
    if (!f) { puts("No se pudo abrir agenda.txt"); return; }

    char linea[30];
    printf("\n--- TODOS LOS TURNOS ---\n");
    while (fgets(linea, sizeof(linea), f)) {
        char hora[10], estado[10];
        sscanf(linea, "%[^|]|%s", hora, estado);
        printf("%-10s  -->  %s\n", hora, estado);
    }
    fclose(f);
}

void solicitar_turno(){
    agenda();

    char cliente [MAX_CHAR];
    char servicio [MAX_CHAR];
    int elegido;

    printf("Nombre: ");
    fgets(cliente, MAX_CHAR, stdin);
    cliente[strcspn(cliente, "\n")] = 0;
    
    mostrar_servicios();
    printf("Nombre del servicio deseado: ");
    fgets(servicio, MAX_CHAR, stdin);
    servicio[strcspn(servicio, "\n")] = 0;

    turnos_libres();
    printf("Seleccioné el numero del turno: ");
    scanf("%d", &elegido);
    getchar();

    if (!marcar_turno_ocupado(elegido))
    {
        printf("Este turno esta ocupado o el numero de turno no es valido.");
        return;
    }
    
    FILE *t = fopen("turnos.txt", "a");

    if (!t)
    {
        printf("No se puedo abrir el archivo turnos.txt");
        return;
    }
    
    fprintf(t, "%s\n", cliente);
    fprintf(t, "%s\n", servicio);

    FILE *a = fopen("agenda.txt", "r");
    char linea[MAX_CHAR];
    int indice = 1;

    while (fgets(linea, sizeof(linea), a)) {
        if (indice++ == elegido) {
            char hora[10], estado[10];
            sscanf(linea, "%[^|]|%s", hora, estado);
            fprintf(t, "%s\n", hora);
            break;
        }
    }

    fclose(a);
    fclose(t);
    printf("¡Turno reservado!\n");
}