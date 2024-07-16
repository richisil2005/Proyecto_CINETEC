#include <iostream>
#include <unordered_map>
#include <vector>
#include "peliculas.h"
#include "adpeliculas.h"
#include "mapeo.h"
#include "navbar.h"
#include "recomendaciones.h"
#include "similarespe.h"
using namespace std;
typedef Pelicula<string> PeliculaEspecifica;

void mostrarMenu() {
    cout << "-----------------------CINETEC--------------------------------";
    cout << "\n1. Buscar pelicula\n";
    cout << "2. Buscar pelicula por genero\n";
    cout << "3. Lista de Ver mas tarde \n";
    cout << "4. Tus me gusta <3\n";
    cout << "5. Salir\n";
    cout << "Que quieres hacer hoy??: ";
}

int main() {
    vector<PeliculaEspecifica*> peliculas = leerArchivoCSV<string>("CSV.csv", 2);
    MapaTitulosPeliculas* mapaTitulos = MapaTitulosPeliculas::getInstance();
    PeliculasSimilaresPorEtiqueta<PeliculaEspecifica> estrategia;
    ExploradorPeliculas<PeliculaEspecifica> explorador(&estrategia, peliculas);
    unordered_map<string, vector<int>> mapaEtiquetas;
    auto& mapa = mapaTitulos->getMapa();

    for (int i = 0; i < peliculas.size(); ++i) {
        mapaTitulos->insertar(peliculas[i]->titulo, i);
        istringstream tagStream(peliculas[i]->etiquetas);
        string etiqueta;
        while (getline(tagStream, etiqueta, ',')) mapaEtiquetas[etiqueta].push_back(i);
    }
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1: buscarPorTitulo<PeliculaEspecifica>(mapa, peliculas);
                break;
            case 2: buscarPorEtiqueta<PeliculaEspecifica>(mapaEtiquetas, peliculas);
                break;
            case 3: mostrarVerMasTarde<PeliculaEspecifica>(peliculas);
                break;
            case 4: mostrarLikes<PeliculaEspecifica>(peliculas);
                break;
            case 5: cout << "Vuelva pronto CINETEC LO ESPERA!! \n";
                break;
            case 6: explorador.mostrarSimilaresALikes();
                break;
            default: cout << "Opcion no existente.\n";
        }
    } while (opcion != 5);
    for (auto pelicula : peliculas) delete pelicula;
    return 0;
}