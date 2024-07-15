#include "favoritos.h"
#include <iostream>

void Favoritos::agregarFavorito(const Pelicula& pelicula) {
    favoritos.insert(pelicula.id);
}

void Favoritos::agregarVerMasTarde(const Pelicula& pelicula) {
    verMasTarde.insert(pelicula.id);
}

void Favoritos::mostrarFavoritos(const std::unordered_map<std::string, Pelicula>& peliculas) const {
    std::cout << "Peliculas favoritas:\n";
    for (const auto& id : favoritos) {
        auto it = peliculas.find(id);
        if (it != peliculas.end()) {
            mostrarDetallePelicula(it->second);
        }
    }
}

void Favoritos::mostrarVerMasTarde(const std::unordered_map<std::string, Pelicula>& peliculas) const {
    std::cout << "Peliculas para ver mas tarde:\n";
    for (const auto& id : verMasTarde) {
        auto it = peliculas.find(id);
        if (it != peliculas.end()) {
            mostrarDetallePelicula(it->second);
        }
    }
}

void agregarAFavoritos(Favoritos& favoritos, const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& id) {
    auto it = peliculas.find(id);
    if (it != peliculas.end()) {
        favoritos.agregarFavorito(it->second);
        std::cout << "Pelicula agregada a favoritos.\n";
    } else {
        std::cout << "Pelicula no encontrada.\n";
    }
}

void agregarAVerMasTarde(Favoritos& favoritos, const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& id) {
    auto it = peliculas.find(id);
    if (it != peliculas.end()) {
        favoritos.agregarVerMasTarde(it->second);
        std::cout << "Pelicula agregada a Ver mas tarde.\n";
    } else {
        std::cout << "Pelicula no encontrada.\n";
    }
}
