#ifndef PELICULAS_H
#define PELICULAS_H

#include <string>
#include <vector>
#include <unordered_map>

struct Pelicula {
    std::string titulo;
    std::string sinopsis;
    std::vector<std::string> tags;
};

std::unordered_map<std::string, Pelicula> cargarPeliculas(const std::string& nombreArchivo);
std::vector<Pelicula> buscarPeliculas(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& termino);
std::vector<Pelicula> buscarPorTag(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& tag);

#endif