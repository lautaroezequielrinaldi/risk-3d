#include "mapa.h"

Mapa::Mapa():
    paises(),
    continentes() {
    // No realiza ninguna acciòn.
}

void Mapa::agregarPais(const ReferenceCountPtr<Pais>& pais) {
    this->paises.push_back(pais);
}

void Mapa::removerPais(const ReferenceCountPtr<Pais>& pais) {
    this->paises.remove(pais);
}

ReferenceCountPtr<Pais> Mapa::obtenerPais(const std::string& nombre) {
    // Defino contador.
    IteradorPais iter;

    // Itero por cada pais adyacente.
    for (iter = this->primerPais(); iter != this->ultimoPais(); ++iter) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = *iter;
        // SI el nombre del pais actual coincide.
        if (actual->getNombre() == nombre) {
            // Retorno actual.
            return actual;
        }
    }
    // Si no encontre pais, devuelvo NULL.
    return NULL;
}
                                                                     
void Mapa::agregarContinente(const ReferenceCountPtr<Continente>& continente) {
    this->continentes.push_back(continente);
}

void Mapa::removerContinente(const ReferenceCountPtr<Continente>& continente) {
    this->continentes.remove(continente);
}

ReferenceCountPtr<Continente> Mapa::obtenerContinente(
    const std::string& nombre) {
    // Defino contador.
   IteradorContinente iter;

    // Itero por cada pais adyacente.
    for (iter = this->primerContinente(); iter != this->ultimoContinente();
        ++iter) {
        // Obtengo continente actual.
        ReferenceCountPtr<Continente> actual = *iter;
        // SI el nombre del continente actual coincide.
        if (actual->getNombre() == nombre) {
            // Retorno actual.
            return actual;
        }
    }
    // Si no encontre pais, devuelvo NULL.
    return NULL;
}

Mapa::IteradorPais Mapa::primerPais() {
    return this->paises.begin();
}

Mapa::IteradorPais Mapa::ultimoPais() {
    return this->paises.end();
}

Mapa::IteradorContinente Mapa::primerContinente() {
    return this->continentes.begin();
}

Mapa::IteradorContinente Mapa::ultimoContinente() {
    return this->continentes.end();
}

Mapa::~Mapa() {
    // No realiza ninguna acciòn.
}

