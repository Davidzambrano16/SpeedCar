#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Usuario.cpp"
#include "Vehiculo.cpp"

using namespace std;


void mostrarMenuPrincipal() {
    cout << "========== MENU PRINCIPAL ==========" << endl;
    cout << "1. Gestionar Usuarios" << endl;
    cout << "2. Gestionar Vehiculos" << endl;
    cout << "3. Gestionar Sectores" << endl;
    cout << "4. Servicio Diario" << endl;
    cout << "5. Salir" << endl;
    cout << "====================================" << endl;
}


void gestionarUsuarios(Usuario& usuario) {
    int opcion;
    do {
        cout << "===== GESTION DE USUARIOS =====" << endl;
        cout << "1. Agregar Usuario" << endl;
        cout << "2. Modificar Usuario" << endl;
        cout << "3. Consultar Usuario" << endl;
        cout << "4. Eliminar Usuarios" << endl;
        cout << "5. Volver al menú principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                usuario.agregarUsuario();
                break;
            case 2:
                usuario.modificarUsuario();
                break;
            case 3: 
                usuario.mostrarUsuarios();
                break;
            case 4:
                usuario.eliminarUsuario();
                break;
            case 5:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while(opcion != 3);
}

void gestionarVehiculos(Vehiculo& vehiculo) {
    int opcion;
    do {
        cout << "===== GESTION DE VEHICULOS =====" << endl;
        cout << "1. Agregar Vehiculo" << endl;
        cout << "2. Modificar Vehiculo" << endl;
        cout << "3. Consultar Vehiculo" << endl;
        cout << "4. Eliminar Vehiculo" << endl;
        cout << "5. Volver al menú principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

                switch(opcion) {
            case 1:
                vehiculo.agregarUsuario();
                break;
            case 2:
                vehiculo.modificarUsuario();
                break;
            case 3: 
                vehiculo.mostrarVehiculos();
                break;
            case 4:
                vehiculo.eliminarVehiculo();
                break;
            case 5:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while(opcion != 5);
}

int main() {
    int opcion;
    Usuario usuario;
    usuario.cargarUsuariosDeArchivo();
    Vehiculo vehiculo;

    do {
        mostrarMenuPrincipal();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                gestionarUsuarios(usuario);
                break;
            case 2:
                gestionarVehiculos(vehiculo);
                break;
            case 3:
                cout << "Gestionar Sectores (A implementar)" << endl;
                break;
            case 4:
                cout << "Servicio Diario (A implementar)" << endl;
                break;
            case 5:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while(opcion != 5);

    return 0;
}
