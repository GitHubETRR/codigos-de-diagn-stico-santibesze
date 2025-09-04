#include <iostream>
using namespace std;

class Contactos
{
private:
    string nombre;
    string telefono;
    string relacion;
public:    
    void get_datos(string n2, string t2, string r2);

    void set_datos(string n1, string t1, string r1);

    void cargar();

    void mostrar();
};

void Contactos :: get_datos(string& n2, string& t2, string& r2){
    nombre = n2;
    telefono = t2; 
    relacion = r2;
}

void Contactos :: set_datos(string n1, string t1, string r1){
    nombre = n1;
    telefono = t1; 
    relacion = r1;
}

void Contactos :: cargar(){
    string n, t, r;

    cout << "Nombre del contacto: ";
    getline(cin, n); 

    cout << "Numero del contacto: ";
    cin >> t;
    cin.ignore(); 

    cout << "Relacion que tiene: ";
    getline(cin, r);

    set_datos(n, t, r); /
}



