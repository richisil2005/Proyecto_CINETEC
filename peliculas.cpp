#include "peliculas.h"
#include <fstream>
#include <sstream>
#include <algorithm>

namespace std {
    unordered_map<string, Pelicula> cargarPeliculas(const string& nombreArchivo) {
        unordered_map<string, Pelicula> peliculas;

        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo." << endl; 
            return peliculas;
        }

        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string titulo, sinopsis, tagsStr;
            getline(ss, titulo, ',');
            getline(ss, sinopsis, ',');
            getline(ss, tagsStr, ',');

            Pelicula pelicula;
            pelicula.titulo = titulo;
            pelicula.sinopsis = sinopsis;

            stringstream tagsSS(tagsStr);
            string tag;
            while (getline(tagsSS, tag, ';')) {
                pelicula.tags.push_back(tag);
            }

            peliculas[titulo] = pelicula;
        }

        archivo.close();
        return peliculas;
    }

    vector<Pelicula> buscarPeliculas(const unordered_map<string, Pelicula>& peliculas, const string& termino) {
        vector<Pelicula> resultados;
        for (const auto& par : peliculas) {
            const Pelicula& pelicula = par.second;
            if (pelicula.titulo.find(termino) != string::npos || pelicula.sinopsis.find(termino) != string::npos) {
                resultados.push_back(pelicula);
            }
        }
        return resultados;
    }

    vector<Pelicula> buscarPorTag(const unordered_map<string, Pelicula>& peliculas, const string& tag) {
        vector<Pelicula> resultados;
        for (const auto& par : peliculas) {
            const Pelicula& pelicula = par.second;
            if (find(pelicula.tags.begin(), pelicula.tags.end(), tag) != pelicula.tags.end()) {
                resultados.push_back(pelicula);
            }
        }
        return resultados;
    }
}
