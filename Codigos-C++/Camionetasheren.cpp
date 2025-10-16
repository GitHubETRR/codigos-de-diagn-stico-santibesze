#include <iostream>
using namespace std;

class Vehiculo
{
public:
    virtual void MostrarInfo(){
        cout << "Vehiculo generico" << endl;
    }
};

class Camionetas : public Vehiculo
{
    public: 
    void MostrarInfo(){
        cout << "Camioneta 4x4"<< endl;
    }
};

class AmarokV6 : public Camionetas
{
    public:
    void MostrarInfo(){
        cout << "Amarok V6: \n.Motor 3.0 TDI V6. \n.Tracción 4x4. \n.100km/h en 7.8s." << endl;
    }
};

class FordRanger : public Camionetas
{
    public:
    void MostrarInfo(){
        cout << "Ford Ranger: \n.3.0L V6 Turbo Diésel. \n.Tracción 4x4. \n.100km/h en 7.99s" << endl;
    }
};

int main(){
    Vehiculo* Camioneta1 =  new AmarokV6();
    Vehiculo* Camioneta2 =  new FordRanger();


    Camioneta1->  MostrarInfo();
    Camioneta2->  MostrarInfo();

    return 0;
}