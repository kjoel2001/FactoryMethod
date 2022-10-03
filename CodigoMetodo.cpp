#include <iostream> 
using namespace std; 
enum VehicleType { VT_DosRuedas, VT_TresRuedas, VT_CuatroRuedas }; 
class Vehiculo { 
    public: 
    virtual void printVehicle() = 0; 
    static Vehiculo* Create(VehicleType type); 
}; 
class DosRuedas : public Vehiculo { 
    public: 
    void printVehicle() { 
        cout << "Se ingreso un vehiculo de 2 ruedas" << endl; 
    } 
}; 
class TresRuedas : public Vehiculo { 
    public: 
    void printVehicle() { 
        cout << "Se ingreso un vehiculo de 3 ruedas" << endl; 
    } 
}; 
class CuatroRuedas : public Vehiculo { 
    public: 
    void printVehicle() { 
        cout << "Se ingreso un vehiculo de 4 ruedas" << endl; 
    } 
}; 
Vehiculo* Vehiculo::Create(VehicleType type) { 
    if (type == VT_DosRuedas) 
        return new DosRuedas(); 
    else if (type == VT_TresRuedas) 
        return new TresRuedas(); 
    else if (type == VT_CuatroRuedas) 
        return new CuatroRuedas(); 
    else return NULL;
} 
class Cliente { 
    public: 
    Cliente() { 
        VehicleType type = VT_CuatroRuedas; 
        pVehicle = Vehiculo::Create(type); } 
    ~Cliente() {
        if (pVehicle) { 
            delete[] pVehicle; 
            pVehicle = NULL; 
        } 
    } 
    Vehiculo* getVehicle() { 
        return pVehicle; 
    } 
    private: Vehiculo *pVehicle; 
}; 
int main() { 
    Cliente *pClient = new Cliente(); 
    Vehiculo * pVehicle = pClient->getVehicle();
    pVehicle->printVehicle();
    return 0; 
}