#include <iostream>
using namespace std;

class Auto
{
private:
    string marca;
    string modelo;
    int anio;
public:
    Auto(string m, string mo, int a){
        marca = m;
        modelo = mo;
        anio = a;
    }
    void mostrar(){
        cout << "Marca del auto" << marca << endl;
        cout << "Modelo del auto" << modelo << endl;
        cout << "Año del auto" << anio << endl;
    }
};

int main(){
    Auto a1 ("BMW, M2," 2014);
    a1.mostrar();

    Auto a2 ("Volkswagen, Scirocco," 2020);
    a2.mostrar();
}