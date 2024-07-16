#ifndef PELICULAS_H
#define PELICULAS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <thread>
#include <mutex>
using namespace std;

template<typename T>
class Pelicula {
public:
    T imdb_id, titulo, sinopsis, etiquetas, division, fuente_sinopsis;
    bool like, ver_mas_tarde;
};

typedef Pelicula<std::string> PeliculaEspecifica;

template<typename T>
class FabricaPeliculas {
public:
    static Pelicula<T>* crearPelicula(const std::vector<std::string>& campos) {
        if (campos.size() != 6) return nullptr;
        auto* p = new Pelicula<T>();
        p->imdb_id = campos[0];
        p->titulo = campos[1];
        p->sinopsis = campos[2];
        p->etiquetas = campos[3];
        p->division = campos[4];
        p->fuente_sinopsis = campos[5];
        p->like = false;
        p->ver_mas_tarde = false;
        return p;
    }
};
std::vector<std::string> separarCamposCSV(std::ifstream& archivo, std::string& linea) {
    std::vector<std::string> campos;
    std::string campo;
    bool inQuotes = false;

    for (char c : linea) {
        if (c == '"') inQuotes = !inQuotes;
        else if (c == ',' && !inQuotes) {
            campos.push_back(campo);
            campo.clear();
        }
        else campo += c;
    }

    while (inQuotes && getline(archivo, linea)) {
        campo += ' ';
        for (char c : linea) {
            if (c == '"') inQuotes = !inQuotes;
            else if (c == ',' && !inQuotes) {
                campos.push_back(campo);
                campo.clear();
            }
            else campo += c;
        }
    }
    campos.push_back(campo);
    return campos;
}
template<typename T>
void leerPorcionCSV(const std::string& nombreArchivo, int inicio, int fin, std::vector<Pelicula<T>*>& peliculas, std::mutex& mtx) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    archivo.seekg(inicio);

    std::string linea;
    getline(archivo, linea);

    while (archivo.tellg() < fin && getline(archivo, linea)) {
        std::vector<std::string> campos = separarCamposCSV(archivo, linea);
        Pelicula<T>* pelicula = FabricaPeliculas<T>::crearPelicula(campos);
        if (pelicula) {
            std::lock_guard<std::mutex> guard(mtx);
            peliculas.push_back(pelicula);
        }
        else std::cerr << "Error procesando línea: " << linea << std::endl;
    }

    archivo.close();
}

template<typename T>
std::vector<Pelicula<T>*> leerArchivoCSV(const std::string& nombreArchivo, int numThreads) {
    std::vector<Pelicula<T>*> peliculas;
    std::ifstream archivo(nombreArchivo, std::ios::ate);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return peliculas;
    }
    int fileSize = archivo.tellg();
    archivo.close();
    int chunkSize = fileSize / numThreads;
    std::vector<std::thread> threads;
    std::mutex mtx;

    for (int i = 0; i < numThreads; ++i) {
        int inicio = i * chunkSize;
        int fin = (i == numThreads - 1) ? fileSize : (i + 1) * chunkSize;

        threads.emplace_back(leerPorcionCSV<T>, nombreArchivo, inicio, fin, std::ref(peliculas), std::ref(mtx));
    }
    for (auto& t : threads) t.join();
    return peliculas;
}
#endif
