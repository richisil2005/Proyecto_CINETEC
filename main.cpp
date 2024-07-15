#include <iostream>
#include <unordered_map>
#include <vector>
#include "peliculas.h"
#include "favoritos.h"

void mostrarOpciones() {
    std::cout << "------------------------CINETEC------------------------\n";
    std::cout << "Opciones disponibles:\n";
    std::cout << "1. Ver recomendaciones\n";
    std::cout << "2. Buscar peliculas por titulo\n";
    std::cout << "3. Buscar peliculas por etiquetas\n";
    std::cout << "4. Ver detalles de una pelicula\n";
    std::cout << "5. Agregar pelicula a favoritos\n";
    std::cout << "6. Agregar pelicula a Ver más tarde\n";
    std::cout << "7. Ver peliculas favoritas\n";
    std::cout << "8. Ver peliculas para ver más tarde\n";
    std::cout << "9. Salir\n";
}

int main() {
    std::unordered_map<std::string, Pelicula> peliculas = cargarPeliculas("CSV.csv");
    Favoritos favoritos;
    int opcion;

    do {
        mostrarOpciones();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::vector<Pelicula> recomendaciones = recomendarPeliculas(peliculas);
                mostrarPeliculas(recomendaciones, 0, 5);
                break;
            }
            case 2: {
                std::string termino;
                std::cout << "Ingrese el titulo o parte del titulo: ";
                std::cin.ignore();
                std::getline(std::cin, termino);
                std::vector<Pelicula> resultados = buscarPorTitulo(peliculas, termino);
                mostrarPeliculas(resultados, 0, 5);
                break;
            }
            case 3: {
                std::string tag;
                std::cout << "Ingrese la etiqueta: ";
                std::cin.ignore();
                std::getline(std::cin, tag);
                std::vector<Pelicula> resultados = buscarPorTag(peliculas, tag);
                mostrarPeliculas(resultados, 0, 5);
                break;
            }
            case 4: {
                std::string id;
                std::cout << "Ingrese el ID de la pelicula: ";
                std::cin.ignore();
                std::getline(std::cin, id);
                Pelicula pelicula = obtenerDetallesPelicula(peliculas, id);
                mostrarDetallePelicula(pelicula);
                std::cout << "1. Me gusta\n2. Ver más tarde\n3. Volver al menú\n";
                int opcion_detalle;
                std::cin >> opcion_detalle;
                if (opcion_detalle == 1) {
                    agregarAFavoritos(favoritos, peliculas, id);
                } else if (opcion_detalle == 2) {
                    agregarAVerMasTarde(favoritos, peliculas, id);
                }
                break;
            }
            case 5: {
                std::string id;
                std::cout << "Ingrese el ID de la pelicula a agregar a favoritos: ";
                std::cin.ignore();
                std::getline(std::cin, id);
                agregarAFavoritos(favoritos, peliculas, id);
                break;
            }
            case 6: {
                std::string id;
                std::cout << "Ingrese el ID de la pelicula a agregar a Ver más tarde: ";
                std::cin.ignore();
                std::getline(std::cin, id);
                agregarAVerMasTarde(favoritos, peliculas, id);
                break;
            }
            case 7: {
                favoritos.mostrarFavoritos(peliculas);
                break;
            }
            case 8: {
                favoritos.mostrarVerMasTarde(peliculas);
                break;
            }
            case 9:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 9);

    return 0;
}
