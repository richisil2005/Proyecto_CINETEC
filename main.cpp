#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "peliculas.h"
#include "favoritos.h"

using namespace std;

int main() {
    unordered_map<string, Pelicula> peliculas = cargarPeliculas("CSV.csv");

    cout << "-----------------------CINETEC-----------------------" << endl;

    while (true) {
        cout << "\nOpciones disponibles:" << endl;
        cout << "1. Ver recomendaciones" << endl;
        cout << "2. Buscar películas por título" << endl;
        cout << "3. Buscar películas por etiquetas" << endl;
        cout << "4. Ver detalles de una película" << endl;
        cout << "5. Agregar película a favoritos" << endl;
        cout << "6. Salir" << endl;

        cout << "\nSeleccione una opción: ";
        int opcion;
        cin >> opcion;
        cout << endl;

        if (opcion == 1) {
            cout << "Recomendaciones:" << endl;
            vector<Pelicula> recomendaciones = recomendarPeliculas(peliculas);

            if (recomendaciones.empty()) {
                cout << "No hay recomendaciones disponibles en este momento." << endl;
            } else {
                cout << "Las siguientes películas te pueden interesar:" << endl;
                for (const Pelicula& pelicula : recomendaciones) {
                    cout << "- " << pelicula.titulo << endl;
                }
            }
        } else if (opcion == 2) {
            cout << "Ingrese el título de la película a buscar: ";
            string termino;
            cin.ignore();
            getline(cin, termino);

            vector<Pelicula> resultados = buscarPeliculas(peliculas, termino);
            cout << "Resultados de la búsqueda:" << endl;
            for (const Pelicula& pelicula : resultados) {
                cout << "- " << pelicula.titulo << endl;
            }
        } else if (opcion == 3) {
            cout << "Ingrese la etiqueta a buscar: ";
            string etiqueta;
            cin >> etiqueta;

            vector<Pelicula> resultados = buscarPorTag(peliculas, etiqueta);
            cout << "Resultados de la búsqueda:" << endl;
            for (const Pelicula& pelicula : resultados) {
                cout << "- " << pelicula.titulo << endl;
            }
        } else if (opcion == 4) {
            cout << "Ingrese el título de la película a ver detalles: ";
            string titulo;
            cin.ignore();
            getline(cin, titulo);

            if (peliculas.find(titulo) != peliculas.end()) {
                verPelicula(peliculas[titulo]);
            } else {
                cout << "Película no encontrada." << endl;
            }
        } else if (opcion == 5) {
            cout << "Función agregar película a favoritos aún no implementada." << endl;
                    }
        
        } else if (opcion == 5) {
            cout << "Ingrese el título de la película a agregar a favoritos: ";
            string titulo;
            cin.ignore();
            getline(cin, titulo);

            if (peliculas.find(titulo) != peliculas.end()) {
                agregarVerMasTarde(peliculas[titulo]);
                cout << "Película agregada a favoritos." << endl;
            } else {
                cout << "Película no encontrada." << endl;
            }

            
        } else if (opcion == 6) {
            cout << "¡Hasta luego!" << endl;
            break;
        } else {
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }
    }

    return 0;
}


