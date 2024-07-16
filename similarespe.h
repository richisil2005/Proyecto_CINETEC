#ifndef PROYECTO_CINETEC_SIMILARESPE_H
#define PROYECTO_CINETEC_SIMILARESPE_H
#include "peliculas.h"
using namespace std;
template<typename T>
class EstrategiaPeliculasSimilares {
public:
    virtual vector<T*> encontrarSimilares(const vector<T*>& todasLasPeliculas, const T* peliculaBase) const = 0;
    virtual ~EstrategiaPeliculasSimilares() = default;
};
#endif
