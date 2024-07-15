#include "peliculas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

std::unordered_map<std::string, Pelicula> cargarPeliculas(const std::string& nombreArchivo) {
    std::unordered_map<std::string, Pelicula> peliculas;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    while (std::getline(archivo, linea)) {
        std::istringstream stream(linea);
        std::string id, titulo, etiquetas_str, detalles;
        std::getline(stream, id, ',');
        std::getline(stream, titulo, ',');
        std::getline(stream, etiquetas_str, ',');
        std::getline(stream, detalles);

        std::vector<std::string> etiquetas;
        std::istringstream etiquetas_stream(etiquetas_str);
        std::string etiqueta;
        while (std::getline(etiquetas_stream, etiqueta, '|')) {
            etiquetas.push_back(etiqueta);
        }

        Pelicula pelicula = { id, titulo, etiquetas, detalles };
        peliculas[id] = pelicula;
    }

    return peliculas;
}

std::vector<Pelicula> recomendarPeliculas(const std::unordered_map<std::string, Pelicula>& peliculas) {
    std::vector<Pelicula> recomendaciones;
    for (const auto& [id, pelicula] : peliculas) {
        recomendaciones.push_back(pelicula);
        if (recomendaciones.size() == 5) break;
    }
    return recomendaciones;
}

std::vector<Pelicula> buscarPorTitulo(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& termino) {
    std::vector<Pelicula> resultados;
    for (const auto& [id, pelicula] : peliculas) {
        if (pelicula.titulo.find(termino) != std::string::npos) {
            resultados.push_back(pelicula);
        }
    }
    return resultados;
}

std::vector<Pelicula> buscarPorTag(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& tag) {
    std::vector<Pelicula> resultados;
    for (const auto& [id, pelicula] : peliculas) {
        if (std::find(pelicula.etiquetas.begin(), pelicula.etiquetas.end(), tag) != pelicula.etiquetas.end()) {
            resultados.push_back(pelicula);
        }
    }
    return resultados;
}

Pelicula obtenerDetallesPelicula(const std::unordered_map<std::string, Pelicula>& peliculas, const std::string& id) {
    return peliculas.at(id);
}

void mostrarPeliculas(const std::vector<Pelicula>& peliculas, int offset, int cantidad) {
    int limite = std::min(offset + cantidad, static_cast<int>(peliculas.size()));
    for (int i = offset; i < limite; ++i) {
        const auto& pelicula = peliculas[i];
        std::cout << "ID: " << pelicula.id << "\n";
        std::cout << "Titulo: " << pelicula.titulo << "\n";
        std::cout << "Etiquetas: ";
        for (const auto& etiqueta : pelicula.etiquetas) {
            std::cout << etiqueta << " ";
        }
        std::cout << "\nDetalles: " << pelicula.detalles << "\n\n";
    }
}

void mostrarDetallePelicula(const Pelicula& pelicula) {
    std::cout << "ID: " << pelicula.id << "\n";
    std::cout << "Titulo: " << pelicula.titulo << "\n";
    std::cout << "Etiquetas: ";
    for (const auto& etiqueta : pelicula.etiquetas) {
        std::cout << etiqueta << " ";
    }
    std::cout << "\nDetalles: " << pelicula.detalles << "\n";
}
