#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehiculo {
public:
    string placa;
    string modelo;
    string marca;
    int ano;
    string chofer;
    vector<Vehiculo> vehiculos; 


    Vehiculo() { }
    Vehiculo(string placa, string modelo, string marca, int ano, string chofer)
        : placa(placa), modelo(modelo), marca(marca), ano(ano), chofer(chofer) {}

    void imprimir() {
        cout << "Placa: " << placa << ", Modelo: " << modelo << ", Marca: " << marca << ", Año: " << ano << ", Chofer: " << chofer << endl;
    }

    void agregarUsuario()
    {
        int ano;
        string placa, modelo, marca, chofer;
        cout << "Ingrese la placa del vehiculo: ";
        cin >> placa;        
        cout << "Ingrese el ano del vehiculo: ";
        cin >> ano;
        cout << "Ingrese el modelo del vehiculo: ";
        cin >> modelo;
        cout << "Ingrese la marca: ";
        cin >> marca;
        cout << "Ingrese el nombre del chofer: ";
        cin >> chofer;


        Vehiculo nuevoVehiculo(placa, modelo, marca, ano, chofer);
        vehiculos.push_back(nuevoVehiculo);
        cout << "Vehiculo agregado exitosamente." << endl;
    }

    void modificarUsuario()
    {
        string placa;
        cout << "Ingrese la placa del vehiculo que desea modificar: ";
        cin >> placa;

        bool encontrado = false;
        for (auto &vehiculo : vehiculos)
        {
            if (vehiculo.placa == placa)
            {
                cout << "Vehiculo encontrado:" << endl;
                vehiculo.imprimir();

                cout << "Ingrese nueva placa: ";
                cin >> vehiculo.placa;
                cout << "Ingrese nuevo ano: ";
                cin >> vehiculo.ano;
                cout << "Ingrese nuevo modelo: ";
                cin >> vehiculo.modelo;
                cout << "Ingrese nueva marca: ";
                cin >> vehiculo.marca;
                cout << "Ingrese nuevo nombre del chofer: ";
                cin >> vehiculo.chofer;
                
                cout << "Vehiculo modificado exitosamente." << endl;
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            cout << "Vehiculo con la placa:  " << placa << " no encontrado." << endl;
        }
    }

    void eliminarVehiculo()
    {
        string placa;
        cout << "Ingrese la placa del vehiculo que desea eliminar: ";
        cin >> placa;

        for (auto it = vehiculos.begin(); it != vehiculos.end(); ++it)
        {
            if (it->placa == placa)
            {
                vehiculos.erase(it);
                cout << "Vehiculo eliminado exitosamente." << endl;
                return;
            }
        }
        cout << "Vehiculo con la placa : " << placa << " no encontrado." << endl;
    }

    void mostrarVehiculos()
    {
        cout << "===== LISTA DE USUARIOS =====" << endl;
        for (size_t i = 0; i < vehiculos.size(); ++i)
        {
            cout << i + 1 << ". ";
            vehiculos[i].imprimir();
        }
    }
};