#include "continente.h"

Continente::Continente(const std::string& nombre):
    nombre(nombre),
    paises() {
    // No realiza ninguna acciòn.
}

std::string Continente::getNombre() {
    return this->nombre;
}

void Continente::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Continente::agregarPais(const ReferenceCountPtr<Pais>& pais) {
    this->paises.push_back(pais);
}

void Continente::removerPais(const ReferenceCountPtr<Pais>& pais) {
    this->paises.remove(pais);
}

ReferenceCountPtr<Pais> Continente::obtenerPais(const std::string& nombre) {
    // Defino contador.
    Iterador iter;

    // Itero por cada pais.
    for (iter = this->primerPais(); iter != this->ultimoPais(); ++iter) {
        // Obtengo elemento actual.
        ReferenceCountPtr<Pais> actual = *iter;
        // Verifico que el nombre del pais coincida.
        if (actual->getNombre() == nombre) {
            // Retorno actual.
            return actual;
        }
    }
    // Si no encuentro al pais, devuelvo NULL.
    return NULL;
}

Continente::Iterador Continente::primerPais() {
    return this->paises.begin();
}

Continente::Iterador Continente::ultimoPais() {
    return this->paises.end();
}

Continente::~Continente() {
    // No realiza ninguna acciòn.
}

