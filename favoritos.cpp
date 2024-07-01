#include "favoritos.h"
#include <iostream>
#include <algorithm>

namespace std {
    vector<Pelicula> verMasTarde;
    unordered_map<string, int> likes;

    void agregarVerMasTarde(const Pelicula& pelicula) {
        verMasTarde.push_back(pelicula);
    }

    void agregarLike(const Pelicula& pelicula) {
        likes[pelicula.titulo]++;
    }

    vector<Pelicula> recomendarPeliculas(const unordered_map<string, Pelicula>& peliculas) {
        vector<Pelicula> recomendaciones;
        for (const auto& like : likes) {
            for (const auto& par : peliculas) {
                if (par.second.titulo != like.first && 
                    find_if(recomendaciones.begin(), recomendaciones.end(), 
                            [&par](const Pelicula& p) { return p.titulo == par.second.titulo; }) == recomendaciones.end()) {
                    recomendaciones.push_back(par.second);
                }
            }
        }
        return recomendaciones;
    }

    void mostrarPeliculas(const vector<Pelicula>& peliculas, int pagina) {
        int inicio = pagina * 5;
        int fin = min(inicio + 5, (int)peliculas.size());

        for (int i = inicio; i < fin; ++i) {
            cout << (i + 1) << ". " << peliculas[i].titulo << endl;
        }
        if (fin < peliculas.size()) {
            cout << "Siguiente pagina: " << pagina + 1 << endl;
        }
    }

    void verPelicula(const Pelicula& pelicula) {
        cout << "Titulo: " << pelicula.titulo << endl;
        cout << "Sinopsis: " << pelicula.sinopsis << endl;
        cout << "1. Like" << endl;
        cout << "2. Ver más tarde" << endl;
        cout << "3. Regresar" << endl;
    }
}