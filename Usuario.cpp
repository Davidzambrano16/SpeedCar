// #include <iostream>
// #include <string>
// #include <vector>


// using namespace std;


// class Usuario {
    
// public:
//     string nombre;
//     string cedula;
//     string direccion;
//     vector<Usuario> usuarios; 

//     Usuario() {}
//     Usuario(string nombre, string cedula, string direccion) : nombre(nombre), cedula(cedula), direccion(direccion) {}

//     void imprimir()
//     {
//         cout << "Nombre: " << nombre << ", Cédula: " << cedula << ", Dirección: " << direccion << endl;
//     }

//     void agregarUsuario()
//     {
//         string nombre, cedula, direccion;
//         cout << "Ingrese nombre: ";
//         cin >> nombre;
//         cout << "Ingrese cédula: ";
//         cin >> cedula;
//         cout << "Ingrese dirección: ";
//         cin >> direccion;

//         Usuario nuevoUsuario(nombre, cedula, direccion);
//         usuarios.push_back(nuevoUsuario);
//         cout << "Usuario agregado exitosamente." << endl;
//     }

//     void modificarUsuario()
//     {
//         string cedula;
//         cout << "Ingrese la cédula del usuario que desea modificar: ";
//         cin >> cedula;

//         bool encontrado = false;
//         for (auto &usuario : usuarios)
//         {
//             if (usuario.cedula == cedula)
//             {
//                 cout << "Usuario encontrado:" << endl;
//                 usuario.imprimir();

//                 cout << "Ingrese nuevo nombre: ";
//                 cin >> usuario.nombre;
//                 cout << "Ingrese nueva dirección: ";
//                 cin >> usuario.direccion;

//                 cout << "Usuario modificado exitosamente." << endl;
//                 encontrado = true;
//                 break;
//             }
//         }

//         if (!encontrado)
//         {
//             cout << "Usuario con cédula " << cedula << " no encontrado." << endl;
//         }
//     }

//     void eliminarUsuario()
//     {
//         string cedula;
//         cout << "Ingrese la cédula del usuario que desea eliminar: ";
//         cin >> cedula;

//         for (auto it = usuarios.begin(); it != usuarios.end(); ++it)
//         {
//             if (it->cedula == cedula)
//             {
//                 usuarios.erase(it);
//                 cout << "Usuario eliminado exitosamente." << endl;
//                 return;
//             }
//         }
//         cout << "Usuario con cédula " << cedula << " no encontrado." << endl;
//     }

//     void mostrarUsuarios()
//     {
//         cout << "===== LISTA DE USUARIOS =====" << endl;
//         for (size_t i = 0; i < usuarios.size(); ++i)
//         {
//             cout << i + 1 << ". ";
//             usuarios[i].imprimir();
//         }
//     }
// };

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Usuario {
public:
    char nombre[30];
    char cedula[20];
    char direccion[50];
    vector<Usuario> usuarios;  // Vector de usuarios

    Usuario() {}
    Usuario(const string& nombre, const string& cedula, const string& direccion) {
        strncpy(this->nombre, nombre.c_str(), sizeof(this->nombre) - 1);
        this->nombre[sizeof(this->nombre) - 1] = '\0';
        
        strncpy(this->cedula, cedula.c_str(), sizeof(this->cedula) - 1);
        this->cedula[sizeof(this->cedula) - 1] = '\0';
        
        strncpy(this->direccion, direccion.c_str(), sizeof(this->direccion) - 1);
        this->direccion[sizeof(this->direccion) - 1] = '\0';
    }

    void imprimir() const {
        cout << "Nombre: " << nombre << ", Cédula: " << cedula << ", Dirección: " << direccion << endl;
    }

    // Cargar usuarios desde archivo binario
    void cargarUsuariosDeArchivo() {
        ifstream archivo("usuarios.dat", ios::binary);
        if (!archivo) {
            cerr << "No se pudo abrir el archivo de usuarios." << endl;
            return;
        }

        usuarios.clear();  // Limpia el vector antes de cargar
        Usuario temp;
        while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
            usuarios.push_back(temp);
        }
        archivo.close();
        cout << "Usuarios cargados del archivo." << endl;
    }

    // Guardar usuarios en archivo binario
    void guardarUsuariosEnArchivo() const {
        ofstream archivo("usuarios.dat", ios::binary | ios::trunc);  // El modo trunc limpia el archivo antes de escribir
        if (!archivo) {
            cerr << "No se pudo abrir el archivo de usuarios para escribir." << endl;
            return;
        }

        for (const auto& usuario : usuarios) {
            archivo.write(reinterpret_cast<const char*>(&usuario), sizeof(usuario));
        }
        archivo.close();
        cout << "Usuarios guardados en el archivo." << endl;
    }

    // Agregar un nuevo usuario y guardar en archivo
    void agregarUsuario() {
        string nombre, cedula, direccion;
        cout << "Ingrese nombre: ";
        cin >> nombre;
        cout << "Ingrese cédula: ";
        cin >> cedula;
        cout << "Ingrese dirección: ";
        cin >> direccion;

        Usuario nuevoUsuario(nombre, cedula, direccion);
        usuarios.push_back(nuevoUsuario);
        guardarUsuariosEnArchivo();  // Guarda cambios en el archivo
        cout << "Usuario agregado exitosamente." << endl;
    }

    // Modificar usuario existente y guardar en archivo
    void modificarUsuario() {
        string cedula;
        cout << "Ingrese la cédula del usuario que desea modificar: ";
        cin >> cedula;

        bool encontrado = false;
        for (auto& usuario : usuarios) {
            if (strcmp(usuario.cedula, cedula.c_str()) == 0) {
                cout << "Usuario encontrado:" << endl;
                usuario.imprimir();

                cout << "Ingrese nuevo nombre: ";
                cin >> usuario.nombre;
                cout << "Ingrese nueva dirección: ";
                cin >> usuario.direccion;

                guardarUsuariosEnArchivo();  // Guarda cambios en el archivo
                cout << "Usuario modificado exitosamente." << endl;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Usuario con cédula " << cedula << " no encontrado." << endl;
        }
    }

    // Eliminar usuario y guardar cambios en el archivo
    void eliminarUsuario() {
        string cedula;
        cout << "Ingrese la cédula del usuario que desea eliminar: ";
        cin >> cedula;

        for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
            if (strcmp(it->cedula, cedula.c_str()) == 0) {
                usuarios.erase(it);
                guardarUsuariosEnArchivo();  // Guarda cambios en el archivo
                cout << "Usuario eliminado exitosamente." << endl;
                return;
            }
        }
        cout << "Usuario con cédula " << cedula << " no encontrado." << endl;
    }

    // Mostrar todos los usuarios
    void mostrarUsuarios() const {
        cout << "===== LISTA DE USUARIOS =====" << endl;
        for (size_t i = 0; i < usuarios.size(); ++i) {
            cout << i + 1 << ". ";
            usuarios[i].imprimir();
        }
    }
};
