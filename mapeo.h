#ifndef MAPEO_H
#define MAPEO_H
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;

class MapaTitulosPeliculas {
private:
    static unique_ptr<MapaTitulosPeliculas> instancia;
    unordered_map<string, vector<int>> mapaTitulos;
    MapaTitulosPeliculas() {}

public:
    static MapaTitulosPeliculas* getInstance() {
        if (instancia == nullptr) instancia = unique_ptr<MapaTitulosPeliculas>(new MapaTitulosPeliculas());
        return instancia.get();
    }
    MapaTitulosPeliculas(const MapaTitulosPeliculas&) = delete;
    MapaTitulosPeliculas& operator=(const MapaTitulosPeliculas&) = delete;
    void insertar(const string& titulo, int index) {mapaTitulos[titulo].push_back(index);}

    vector<int> buscar(const string& titulo) {
        auto it = mapaTitulos.find(titulo);
        if (it != mapaTitulos.end()) return it->second;
        return {};
    }
    const unordered_map<string, vector<int>>& getMapa() const {return mapaTitulos;}
};
unique_ptr<MapaTitulosPeliculas> MapaTitulosPeliculas::instancia = nullptr;
#endif
