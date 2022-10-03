#include <iostream> 
using namespace std; 

class Vehiculo { 
    public: 
        virtual void printVehicle() = 0;
}; 
class DosRuedas : public Vehiculo { 
    public: 
        void printVehicle() { 
            cout << "2 ruedas " << endl; 
            } 
}; 
class CuatroRuedas : public Vehiculo {
    public: 
        void printVehicle() { 
            cout << "4 ruedas" << endl; 
            } 
}; 
class Cliente { 
    public: 
        Cliente(int type) { 
            if (type == 1) 
                pVehicle = new DosRuedas(); 
            else if (type == 2) 
                pVehicle = new CuatroRuedas(); 
            else 
                pVehicle = NULL; 
        } 
    ~Cliente() { 
        if (pVehicle) { 
            delete[] pVehicle; 
            pVehicle = NULL; 
        } 
    }
    Vehiculo* getVehicle() { 
        return pVehicle; 
    } 
    private: 
        Vehiculo *pVehicle; 
}; 
int main() { 
    Cliente *pClient = new Cliente(2); 
    Vehiculo * pVehicle = pClient->getVehicle(); 
    pVehicle->printVehicle(); 
    return 0; 
}