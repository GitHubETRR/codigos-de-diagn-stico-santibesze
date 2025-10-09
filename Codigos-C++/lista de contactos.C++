#include <iostream>
#include <vector>
using namespace std;

#define AGREGAR_C 1
#define MOSTRAR_C 2
#define SALIR 3


class Contactos
{
private:
    string nombre;
    string relacion;
    int telefono;
public:    
    void get_datos(string& n2, int& t2, string& r2);

    void set_datos(string n1, int t1, string r1);

    void cargar();

    void mostrar();
};


void menu();


int main(){
    menu();

    return 0;
}

void Contactos :: get_datos(string& n2, int& t2, string& r2){
    n2 = nombre ;
    t2 = telefono ; 
    r2 = relacion;
}

void Contactos :: set_datos(string n1, int t1, string r1){
    nombre = n1;
    telefono = t1; 
    relacion = r1;
}

void Contactos :: cargar(){
    string n_in, r_in;
    int t_in;

    cout << "Nombre del contacto: ";
    getline(cin, n_in); 

    cout << "Numero del contacto: ";
    cin >> t_in;
    cin.ignore(); 

    cout << "Relacion que tiene: ";
    getline(cin, r_in);

    set_datos(n_in, t_in, r_in); 
}

void Contactos :: mostrar(){
    string n_out, r_out;
    int t_out;

    get_datos(n_out, t_out, r_out );

    cout << "Nombre: " << n_out << endl;
    cout << "Numero de telefono: (+54) " << t_out << endl;
    cout << "Relacion: " << r_out << endl;    
}

void menu(){
    Contactos c1;
    int opcion;
    vector<Contactos>lista;
    do
    {
        cout << "------MENU-----\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Mostrar contactos\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
            switch (opcion)
    {
        case AGREGAR_C:
            cin.ignore();
            c1.cargar();
            lista.push_back(c1);
            break;
        case MOSTRAR_C:
            for (int i = 0; i < lista.size(); i++)
            {
                lista[i].mostrar();
            }
                break;
        case SALIR:
            cout << "Saliendo...";
            break;
        default :
            cout << "Esta opcion no es valida";         
            break;
    }
    } while (opcion != SALIR);
}