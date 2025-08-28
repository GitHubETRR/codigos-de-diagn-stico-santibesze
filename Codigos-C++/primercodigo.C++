#include <iostream>
using namespace std;

class Auto
{
private:
    string marca;
    int anio;
public:
    Auto(){
        cout << "Ingrese la marca del auto:";
        cin >> marca;
        cout << "Ingrese el año del auto";
        cin >> anio;
    }
    void mostrar(){
        cout << "Marca del auto:" << marca << endl;
        cout << "Año del auto:" << anio << endl;
    }
};

int main()
{
    Auto a1;
    a1.mostrar();

    return 0;
}