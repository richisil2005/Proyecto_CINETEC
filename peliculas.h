#ifndef PELICULAS_H
#define PELICULAS_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
struct Pelicula {
    std::string id;
    std::string titulo;
    std::vector<std::string> etiquetas;
    std::string detalles;
};
std::unordered_map<std::string, Pelicula> cargarPeliculas(const std::string& nombreArchivo);
std::vector<Pelicula> recomendarPeliculas(const std::unordered_map<std::string, Pelicula>& peliculas);
std::vector<Pelicula> buscarPorTitulo(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& termino);
std::vector<Pelicula> buscarPorTag(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& tag);
Pelicula obtenerDetallesPelicula(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& id);
void mostrarPeliculas(const std::vector<Pelicula>& peliculas, int offset, int cantidad);
void mostrarDetallePelicula(const Pelicula& pelicula);
#endif
