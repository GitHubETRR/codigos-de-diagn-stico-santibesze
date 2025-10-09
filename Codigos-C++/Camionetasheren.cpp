#include <iostream>
using namespace std;

class Vehiculo
{
private:
    /* data */
public:
    virtual void MostrarInfo(){
        cout << "Vehiculo generico" << endl;
    }
};

class Camionetas::publc Vehiculo
{
    public: 
    void MostrarInfo(){
        cout << "Camioneta 4x4"<< endl;
    }
}

class AmarokV6: public Camionetas
{
    public:
    void MostrarInfo(){
        cout << "Amarok V6: \n.Motor 3.0 TDI V6. \n.Tracción 4x4. \n.100km/h en 7.8s." << endl;
    }
}

class FordRanger : public Camionetas
{
    public:
    void MostrarInfo(){
        cout << "Ford Ranger: 3.0L V6 Turbo Diésel. \n.Tracción 4x4. \n.100km/h en 7.99s" << endl;
    }
}

int main(){
    Vehiculo* Camioneta1 =  NuevaCamioneta();
    Vehiculo* Camioneta2 =  NuevaCamioneta();

    Camioneta1->  MostrarInfo();
    Camioneta2->  MostrarInfo();

    return 0;
}