#ifndef FAVORITOS_H
#define FAVORITOS_H

#include "peliculas.h"
#include <unordered_set>

class Favoritos {
public:
    void agregarFavorito(const Pelicula& pelicula);
    void agregarVerMasTarde(const Pelicula& pelicula);
    void mostrarFavoritos(const std::unordered_map<std::string, Pelicula>& peliculas) const;
    void mostrarVerMasTarde(const std::unordered_map<std::string, Pelicula>& peliculas) const;

private:
    std::unordered_set<std::string> favoritos;
    std::unordered_set<std::string> verMasTarde;
};

void agregarAFavoritos(Favoritos& favoritos, const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& id);
void agregarAVerMasTarde(Favoritos& favoritos, const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& id);

#endif
