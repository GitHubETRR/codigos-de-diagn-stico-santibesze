    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_CHAR 30


    typedef struct 
    {
        char nombre[MAX_CHAR];
        char precio[MAX_CHAR];
        char duracion[MAX_CHAR];
    }servicio_t;


    void menu_principal();
    void menu_duenio();
    int gestion_password();
    void agregar_servicio();
    void eliminar_servicios();

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
                    eliminar_servicios();
                    break;
                case 3:
                    printf("Volviendo al menú principal...\n");
                    break;
                default:
                    printf("Esta opcion no es valida.\n");
                    break;
            }
        } while (opcion!=3);
    }

    void agregar_servicio(){
        servicio_t s;
        printf("Nombre del servicio: ");
        fgets(s.nombre,MAX_CHAR,stdin);


        printf("Precio: ");
        fgets(s.precio,MAX_CHAR,stdin);

        printf("Duración (en minutos): ");
        fgets(s.duracion,MAX_CHAR,stdin);

        FILE *archivo =fopen("servicios.txt","a");
        if (!archivo)
        {
            printf("No se pudo abrir el archivo.");
            return;
        }

        fprintf(archivo, "%s", s.nombre);
        fprintf(archivo,"%s", s.precio);
        fprintf(archivo,"%s", s.duracion);
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



