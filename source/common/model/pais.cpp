#include "pais.h"

Pais::Pais(const std::string& nombre):
    nombre(nombre),
    adyacentes() {
    // No realiza ninguna acciòn.
}

std::string Pais::getNombre() {
    return this->nombre;
}

void Pais::setNombre(const std::stirng& nombre) {
    this->nombre = nombre;
}

void Pais::agregarAdyacente(const ReferenceCountPtr<Pais>& adyacente) {
    this->adyacentes.push_back(adyacente);
}

void Pais::removerAdyacente(const ReferenceCountPtr<Pais> adyacente) {
    this->adyacentes.remove(adyacente);
}

ReferenceCountPtr<Pais> Pais::obtenerAdyacente(const std::string& nombre) {
    // Itero por cada pais adyacente.
    for (int counter = 0; counter < this->adyacentes.size(); ++counter) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = this->adyacentes[counter];
        // SI el nombre del pais actual coincide, devuelvo pais.
        if (*actual.getNombre() == nombre) {
            return actual;
        }
    }
    // Si no encontre pais, devuelvo NULL.
    return NULL;
}

Iterador Pais::primerAdyacente() {
    return this->adyacentes.begin();
}

Iterador Pais::ultimoAdyacente() {
    return this->adyacentes.end();
}

Pais::~Pais() {
    // No realiza ninguna acciòn.
}

