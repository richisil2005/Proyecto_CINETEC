#ifndef FAVORITOS_H
#define FAVORITOS_H
#include "peliculas.h"
#include <vector>
#include <unordered_map>

namespace std {
    extern std::vector<Pelicula> verMasTarde;
    extern std::unordered_map<std::string, int> likes;

    void agregarVerMasTarde(const Pelicula& pelicula);
    void agregarLike(const Pelicula& pelicula);
    std::vector<Pelicula> recomendarPeliculas(const std::unordered_map<std::string, Pelicula>& peliculas);
    void mostrarPeliculas(const std::vector<Pelicula>& peliculas, int pagina);
    void verPelicula(const Pelicula& pelicula);
}

#endif