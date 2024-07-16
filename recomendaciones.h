#ifndef PROYECTO_CINETEC_RECOMENDACIONES_H
#define PROYECTO_CINETEC_RECOMENDACIONES_H
#include "similarespe.h"
using namespace std;
template<typename T>
class PeliculasSimilaresPorEtiqueta : public EstrategiaPeliculasSimilares<T> {
public:
    vector<T*> encontrarSimilares(const vector<T*>& todasLasPeliculas, const T* peliculaBase) const override {
        vector<T*> peliculasSimilares;
        vector<string> etiquetasBase;
        string etiqueta;
        stringstream ss(peliculaBase->etiquetas);
        while (getline(ss, etiqueta, ',')) etiquetasBase.push_back(etiqueta);
        for (const auto& pelicula : todasLasPeliculas) {
            for (const auto& etiquetaBase : etiquetasBase) {
                if (pelicula->etiquetas.find(etiquetaBase) != string::npos && pelicula != peliculaBase) {
                    peliculasSimilares.push_back(pelicula);
                    break;
                }
            }
        }
        return peliculasSimilares;
    }
};
#endif
