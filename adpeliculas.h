#ifndef PROYECTO_CINETEC_ADPELICULAS_H
#define PROYECTO_CINETEC_ADPELICULAS_H
#include "peliculas.h"
#include "mapeo.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void mostrarDetallesPelicula(T* pelicula) {
    cout << "-------------------------------------------------------\n";
    cout << "Titulo: " << pelicula->titulo << "\n";
    cout << endl;
    string sinopsisPreview = pelicula->sinopsis;
    if (sinopsisPreview.length() > 700) {
        sinopsisPreview = sinopsisPreview.substr(0, 700) + "...";
    }
    cout << "Sinopsis: " << sinopsisPreview << "\n";
    cout << "Seleccionar:" << endl;
    cout << "1. Like" << endl;
    cout << "2. Ver mas tarde" << endl;
    cout << "3. Regresar al menu\n";
    cout << ":";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            pelicula->like = true;
            cout << "Te ha gustado la pelicula "".\n";
            break;
        case 2:
            pelicula->ver_mas_tarde = true;
            cout << "Ojala veas mas tarde la pelicula :)'.\n";
            break;
        default:
            break;
    }
}
template<typename T>
void mostrarResultados(const vector<int>& indices, const vector<T*>& peliculas) {
    int count = 0;
    cout << "-------------------------------------------------------\n";
    for (int index : indices) {
        cout << "ID: " << index << " - Titulo: " << peliculas[index]->titulo << "\n";
        if (++count >= 5) break;
    }
}
string capitalizar(string str) {
    bool capitalizeNext = true;
    for (char& c : str) {
        if (isspace(c)) capitalizeNext = true;
        else if (capitalizeNext) {
            c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
            capitalizeNext = false;
        }
        else c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }
    return str;
}
template<typename T>
void buscarPorTitulo(const unordered_map<string, vector<int>>& mapa, const vector<T*>& peliculas) {
    string inputTitulo;
    cout << "-------------------------------------------------------\n";
    cout << "Ingresa titulo de la pelicula: ";
    cin.ignore();
    getline(cin, inputTitulo);
    inputTitulo = capitalizar(inputTitulo);
    vector<int> resultados;
    for (const auto& par : mapa) {
        if (par.first.find(inputTitulo) != string::npos) {
            resultados.insert(resultados.end(), par.second.begin(), par.second.end());
        }
    }
    if (resultados.empty()) {
        cout << "Esa pelicula no existe :(.\n";
        return;
    }
    int currentIndex = 0;
    bool continuar = true;
    while (continuar && currentIndex < resultados.size()) {
        int nextIndex = min(currentIndex + 5, (int)resultados.size());
        vector<int> toDisplay(resultados.begin() + currentIndex, resultados.begin() + nextIndex);
        mostrarResultados<T>(toDisplay, peliculas);
        cout << "-------------------------------------------------------\n";
        cout << "Seleccionar" << endl;
        cout << "Ver mas detalles de la pelicula (Para ver mas detalles de la pelicula deberas insertar su ID: " << endl;
        cout << "1. Siguientes 5 peliculas" << endl;
        cout << "2. Regresar al menu" << endl;
        cout << "Eleccion: ";
        string decision;
        cin >> decision;
        if (decision == "1") currentIndex += 5;
        else if (decision == "2") continuar = false;
        else {
            try {
                int peliculaId = stoi(decision);
                if (peliculaId >= 0 && peliculaId < peliculas.size() && find(toDisplay.begin(), toDisplay.end(), peliculaId) != toDisplay.end()) {
                    mostrarDetallesPelicula<T>(peliculas[peliculaId]);
                    break;
                }
                else cout << "ID no existente\n";
            }
            catch (const exception& e) { cout << "Elija una de las opciones, CINETEC tratara de hacer mas opciones proximamente.\n"; }
        }
    }
}
template<typename T>
void buscarPorEtiqueta(unordered_map<string, vector<int>>& mapaEtiquetas, const vector<T*>& peliculas) {
    string etiqueta;
    cout << "-------------------------------------------------------\n";
    cout << "Ingrese etiqueta: ";
    cin.ignore();
    getline(cin, etiqueta);

    auto it = mapaEtiquetas.find(etiqueta);
    if (it == mapaEtiquetas.end()) {
        cout << "-------------------------------------------------------\n";
        cout << "No encontrado con esa etiqueta.\n";
        return;
    }
    vector<int>& resultados = it->second;
    int currentIndex = 0;
    bool continuar = true;
    while (continuar && currentIndex < resultados.size()) {
        vector<int> toDisplay(resultados.begin() + currentIndex, resultados.begin() + min(currentIndex + 5, (int)resultados.size()));
        mostrarResultados<T>(toDisplay, peliculas);
        cout << "-------------------------------------------------------\n";
        cout << "Seleccionar" << endl;
        cout << "Ver mas detalles de la pelicula (Para ver mas detalles de la pelicula deberas insertar su ID: " << endl;
        cout << "1. Siguientes 5 peliculas" << endl;
        cout << "2. Regresar al menu" << endl;
        cout << "Eleccion: ";
        string decision;
        cin >> decision;
        if (decision == "n") currentIndex += 5;
        else if (decision == "q") continuar = false;
        else {
            try {
                int peliculaId = stoi(decision);
                if (peliculaId >= 0 && peliculaId < peliculas.size() && find(toDisplay.begin(), toDisplay.end(), peliculaId) != toDisplay.end()) {
                    mostrarDetallesPelicula<T>(peliculas[peliculaId]);
                    break;
                }
                else cout << "ID no valido. Intente nuevamente.\n";
            }
            catch (const exception& e) { cout << "Entrada no valida. Intente nuevamente.\n"; }
        }
    }
}
template<typename T>
void mostrarVerMasTarde(const vector<T*>& peliculas) {
    cout << "-------------------------------------------------------";
    cout << "\nTe has decidido por ver estas peliculas? :\n";
    for (const auto& pelicula : peliculas) {
        if (pelicula->ver_mas_tarde) cout << pelicula->titulo << endl;
    }
}
template<typename T>
void mostrarLikes(const vector<T*>& peliculas) {
    cout << "-------------------------------------------------------";
    cout << "\nTe gustaron estas peliculas ':\n";
    for (const auto& pelicula : peliculas) {
        if (pelicula->like) cout << pelicula->titulo << endl;
    }
}
#endif
