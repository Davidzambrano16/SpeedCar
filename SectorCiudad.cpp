#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SectorCiudad {
    public:
        string sector;
        int id;
        vector<SectorCiudad> sectoresCiudad;

        SectorCiudad() {}
        SectorCiudad(string sector, int id) : sector(sector), id(id) {}
        void imprimir() {
            cout << "Sector: " << sector << ", ID: " << id << endl;
        }
};