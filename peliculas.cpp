#include "peliculas.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

std::unordered_map<std::string, Pelicula> cargarPeliculas(const std::string& nombreArchivo) {
    std::unordered_map<std::string, Pelicula> peliculas;

    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return peliculas;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string titulo, sinopsis, tagsStr;
        std::getline(ss, titulo, ',');
        std::getline(ss, sinopsis, ',');
        std::getline(ss, tagsStr, ',');

        Pelicula pelicula;
        pelicula.titulo = titulo;
        pelicula.sinopsis = sinopsis;

        std::stringstream tagsSS(tagsStr);
        std::string tag;
        while (std::getline(tagsSS, tag, ';')) {
            pelicula.tags.push_back(tag);
        }

        peliculas[titulo] = pelicula;
    }

    archivo.close();
    return peliculas;
}

std::vector<Pelicula> buscarPeliculas(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& termino) {
    std::vector<Pelicula> resultados;
    for (const auto& par : peliculas) {
        const Pelicula& pelicula = par.second;
        if (pelicula.titulo.find(termino) != std::string::npos || pelicula.sinopsis.find(termino) != std::string::npos) {
            resultados.push_back(pelicula);
        }
    }
    return resultados;
}

std::vector<Pelicula> buscarPorTag(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& tag) {
    std::vector<Pelicula> resultados;
    for (const auto& par : peliculas) {
        const Pelicula& pelicula = par.second;
        if (std::find(pelicula.tags.begin(), pelicula.tags.end(), tag) != pelicula.tags.end()) {
            resultados.push_back(pelicula);
        }
    }
    return resultados;
}
