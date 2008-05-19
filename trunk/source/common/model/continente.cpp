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
    // Itero por todos los paises.
    for (int counter = 0; counter < this.paises.size(); ++counter) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = this.paises[counter];
        // Si los nombres coinciden.
        if (*actual.getNombre() == nombre) {
            // Devuelvo pais actual.
            return actual;
        }
    }
    // Si no encuentro al pais, devuelvo NULL.
    return NULL;
}

Iterador Pais::primerPais() {
    return this->paises.begin();
}

Iterador Pais::ultimoPais() {
    return this->paises.end();
}

Continente::~Continente() {
    // No realiza ninguna acciòn.
}

