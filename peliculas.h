#ifndef PELICULAS_H
#define PELICULAS_H

#include <string>
#include <vector>
#include <unordered_map>

namespace std {
    struct Pelicula {
        string titulo;
        string sinopsis;
        vector<string> tags;
    };

    unordered_map<string, Pelicula> cargarPeliculas(const string& nombreArchivo);
    vector<Pelicula> buscarPeliculas(const unordered_map<string, Pelicula>& peliculas, const string& termino);
    vector<Pelicula> buscarPorTag(const unordered_map<string, Pelicula>& peliculas, const string& tag);
}

#endif // PELICULAS_H






