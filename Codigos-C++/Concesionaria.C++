#include <iostream>
#include <fstream>
using namespace std;

#define AUTOS_DISPO 1
#define CAMIONETAS_DISPO 2
#define MOTOS_DISPO 3
#define SALIR 4

class Vehiculo
{
public:
    virtual void Mostrar(){
         cout << "Vehiculo generico" << endl;
    }
};

class Autos : public Vehiculo
{
    public: 
    void Mostrar(){
        cout << "Autos disponibles" << endl;
    }
};

class Motos : public Vehiculo
{
    public:
    void Mostrar(){
        cout << "Motos disponibles" << endl;
    }
};

class Camionetas : public Vehiculo
{
     public:
    void Mostrar(){
        cout << "Camionetas disponibles" << endl;
    }
}; 

//---------------- FUNCIONES PARA ARCHIVOS ----------------
void GuardarAutos() {
    ofstream archivo("autos.txt");
    archivo << "----- Toyota Yaris -----\n"
            << "Yaris XS 1.5 \nAño: 2021 \nMotor: 1.5L \n Kilometraje: 52.000 km \nTransmisión: Manual \nColor: Gris \nPrecio: USD$17.000\n"
            << "Yaris XLS 1.5 CVT \nAño: 2023 \nMotor: 1.5L Dual VVT-i \nKilometraje: 19.700 km \nTransmisión: Automática \nColor: Blanco \nPrecio: USD$24.000\n\n"
            << "----- Volkswagen Golf -----\n"
            << "Golf 1.4 TSI Highline \nAño: 2020 \nMotor: 1.4L \nKilometraje: 80.000 km \nTransmisión: Automática \nColor: Blanco \nPrecio: USD$28.777\n"
            << "Golf GTI 2.0 TSI \nAño: 2021 \nMotor: 2.0L \nKilometraje: 98.000 km \nTransmisión: Automática \nColor: Azul \nPrecio: USD$38.800\n\n"
            << "----- Honda Civic -----\n"
            << "Civic EX 2.0 \nAño: 2020 \nMotor: 2.0L \nKilometraje: 50.000 km \nTransmisión: Automática \nColor: Blanco \nPrecio: USD$24.900\n";
    archivo.close();
}

void GuardarCamionetas() {
    ofstream archivo("camionetas.txt");
    archivo << "----- Volkswagen Amarok V6 -----\n"
            << "Amarok V6 Comfortline \nAño: 2021 \nMotor: 3.0L V6 \nKilometraje: 96.000 km \nTransmisión: Automática \nColor: Gris \nPrecio: USD$34.000\n\n"
            << "----- Ford Ranger -----\n"
            << "Ranger XLT 3.2 \nAño: 2021 \nMotor: 3.2L \nKilometraje: 65.000 km \nTransmisión: Automática \nColor: Blanco \nPrecio: USD$42.500\n\n"
            << "----- Ford Ranger Raptor -----\n"
            << "Raptor 3.0 Bi-Turbo \nAño: 2023 \nMotor: 3.0L \nKilometraje: 45.000 km \nTransmisión: Automática \nColor: Azul \nPrecio: USD$82.000\n";
    archivo.close();
}

void GuardarMotos() {
    ofstream archivo("motos.txt");
    archivo << "----- BMW F900GS -----\n"
            << "F900GS Adventure \nAño: 2025 \nMotor: Bicilíndrico 895cc \nKilometraje: 0 km \nTransmisión: Manual \nColor: Amarillo Dakar \nPrecio: USD$25.900\n\n"
            << "----- Kawasaki Ninja -----\n"
            << "Ninja 400 \nAño: 2022 \nMotor: 400cc bicilíndrico \nKilometraje: 3.000 km \nTransmisión: Manual \nColor: Verde \nPrecio: USD$11.200\n";
    archivo.close();
}

//----------- FUNCIONES PARA LEER Y MOSTRAR LOS ARCHIVOS ------------
void MostrarArchivo(string nombreArchivo, string titulo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error: no se pudo abrir el archivo de " << titulo << endl;
        return;
    }
    cout << "\n---- " << titulo << " DISPONIBLES ----\n" << endl;
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

//--------------------- MAIN -------------------------
int main() {
    int opcion;

    // Guardamos los datos al inicio del programa
    GuardarAutos();
    GuardarCamionetas();
    GuardarMotos();

    do {
        cout << "\n------------ MENÚ ------------\n";
        cout << "1. Autos disponibles\n";
        cout << "2. Camionetas disponibles\n";
        cout << "3. Motos disponibles\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case AUTOS_DISPO:
                MostrarArchivo("autos.txt", "AUTOS");
                break;
            case CAMIONETAS_DISPO:
                MostrarArchivo("camionetas.txt", "CAMIONETAS");
                break;
            case MOTOS_DISPO:
                MostrarArchivo("motos.txt", "MOTOS");
                break;
            case SALIR:
                cout << "\nSaliendo de la concesionaria virtual..." << endl;
                break;
            default:
                cout << "\nOpción inválida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != SALIR);

    return 0;
}