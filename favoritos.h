#ifndef FAVORITOS_H
#define FAVORITOS_H

#include "peliculas.h"
#include <vector>
#include <unordered_map>

namespace std {
    extern vector<Pelicula> verMasTarde;
    extern unordered_map<string, int> likes;

    void agregarVerMasTarde(const Pelicula& pelicula);
    void agregarLike(const Pelicula& pelicula);
    vector<Pelicula> recomendarPeliculas(const unordered_map<string, Pelicula>& peliculas);
    void mostrarPeliculas(const vector<Pelicula>& peliculas, int pagina);
    void verPelicula(const Pelicula& pelicula);
}

#endif 

