#include "mapa.h"

Mapa::Mapa():
    paises(),
    continentes(), {
    // No realiza ninguna acciòn.
}

void Mapa::agregarPais(const ReferenceCountPtr<Pais>& pais) {
    this->paises.push_back(pais);
}

void Mapa::removerPais(const ReferenceCountPtr<Pais>& pais) {
    this->paises.remove(pais);
}

ReferenceCountPtr<Pais> Pais::obtenerPais(const std::string& nombre) {
    // Itero por cada pais adyacente.
    for (int counter = 0; counter < this->paises.size(); ++counter) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = this->paises[counter];
        // SI el nombre del pais actual coincide, devuelvo pais.
        if (*actual.getNombre() == nombre) {
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

ReferenceCountPtr<Pais> Pais::obtenerContinente(const std::string& nombre) {
    // Itero por cada pais adyacente.
    for (int counter = 0; counter < this->continentes.size(); ++counter) {
        // Obtengo continente actual.
        ReferenceCountPtr<Continente> actual = this->paisesAdyacentes[counter];
        // SI el nombre del continente actual coincide, devuelvo continente.
        if (*actual.getNombre() == nombre) {
            return actual;
        }
    }
    // Si no encontre pais, devuelvo NULL.
    return NULL;
}

IteradorPais Mapa::primerPais() {
    return this->paises.begin();
}

IteradorPais Mapa::ultimoPais() {
    return this->paises.end();
}

IteradorContinente Mapa::primerContinente() {
    return this->continentes.begin();
}

IteradorContinente Mapa::ultimoContinente() {
    return this->continentes.end();
}

Mapa::~Mapa() {
    // No realiza ninguna acciòn.
}

