#include <iostream>
#include <unordered_map>
#include <vector>
#include "peliculas.h"
#include "favoritos.h"

int main() {
    std::unordered_map<std::string, Pelicula> peliculas = cargarPeliculas("CSV.csv");

    int opcion;
    do {
        std::cout << "-----------------------CINETEC-----------------------\n";
        std::cout << "Opciones disponibles:\n";
        std::cout << "1. Ver recomendaciones\n";
        std::cout << "2. Buscar peliculas por titulo\n";
        std::cout << "3. Buscar peliculas por etiquetas\n";
        std::cout << "4. Ver detalles de una pelicula\n";
        std::cout << "5. Agregar pelicula a favoritos\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                // Lógica para ver recomendaciones
                break;
            case 2: {
                std::string titulo;
                std::cout << "Ingrese el titulo de la pelicula: ";
                std::cin.ignore();
                std::getline(std::cin, titulo);
                std::vector<Pelicula> resultados = buscarPeliculas(peliculas, titulo);
                // Mostrar resultados
                break;
            }
            case 3: {
                std::string tag;
                std::cout << "Ingrese la etiqueta de la pelicula: ";
                std::cin.ignore();
                std::getline(std::cin, tag);
                std::vector<Pelicula> resultados = buscarPorTag(peliculas, tag);
                // Mostrar resultados
                break;
            }
            case 4:
                // Lógica para ver detalles de una pelicula
                break;
            case 5:
                // Lógica para agregar pelicula a favoritos
                break;
            case 6:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 6);

    return 0;
}
