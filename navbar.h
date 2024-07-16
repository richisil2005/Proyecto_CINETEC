#ifndef PROYECTO_CINETEC_NAVBAR_H
#define PROYECTO_CINETEC_NAVBAR_H
#include "similarespe.h"
#include "recomendaciones.h"
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <iostream>
template<typename T>
class ExploradorPeliculas {
private:
    const EstrategiaPeliculasSimilares<T>* estrategia;
    vector<T*> peliculas;
public:
    ExploradorPeliculas(const EstrategiaPeliculasSimilares<T>* estrategia, const vector<T*>& peliculas)
            : estrategia(estrategia), peliculas(peliculas) {}
    vector<T*> encontrarPeliculasSimilares(const T* pelicula) const {
        return estrategia->encontrarSimilares(peliculas, pelicula);
    }
    void mostrarSimilaresALikes() const {
        unordered_set<string> todasEtiquetas;
        vector<T*> peliculasSimilares;
        for (const auto& pelicula : peliculas) {
            if (pelicula->like) {
                istringstream tagStream(pelicula->etiquetas);
                string etiqueta;
                while (getline(tagStream, etiqueta, ',')) todasEtiquetas.insert(etiqueta);
            }
        }
        for (const auto& pelicula : peliculas) {
            for (const auto& etiqueta : todasEtiquetas) {
                if (pelicula->etiquetas.find(etiqueta) != string::npos && find(peliculasSimilares.begin(), peliculasSimilares.end(), pelicula) == peliculasSimilares.end()) {
                    vector<T*> encontradasSimilares = encontrarPeliculasSimilares(pelicula);
                    peliculasSimilares.insert(peliculasSimilares.end(), encontradasSimilares.begin(), encontradasSimilares.end());
                    break;
                }
            }
        }
        int currentIndex = 0;
        bool continuar = true;
        while (continuar && currentIndex < peliculasSimilares.size()) {
            int nextIndex = min(currentIndex + 5, int(peliculasSimilares.size()));
            cout << "-------------------------------------------------------\n";
            cout << "Peliculas similares basadas en 'Likes' totales:\n";
            for (int i = currentIndex; i < nextIndex; ++i)
                cout << i+1 << ") " << peliculasSimilares[i]->titulo << "\n";
            currentIndex += 5;
            if (currentIndex < peliculasSimilares.size()) {
                cout << "-------------------------------------------------------\n";
                cout << "-Seleccionar-" << endl;
                cout << "[s] Siguientes 5 peliculas" << endl;
                cout << "[n] Regresar al menu" << endl;
                cout << "Eleccion:";
                char decision;
                cin >> decision;
                if (decision != 's' && decision != 'S') continuar = false;
            }
            else continuar = false;
        }
    }
};
#endif
