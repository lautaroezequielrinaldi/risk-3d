#include "pais.h"

Pais::Pais(const std::string& nombre):
    nombre(nombre),
    paisesAdyacentes() {
    // No realiza ninguna acciòn.
}

std::string Pais::getNombre() {
    return this->nombre;
}

void Pais::setNombre(const std::stirng& nombre) {
    this->nombre = nombre;
}

void Pais::agregarAdyacente(const ReferenceCountPtr<Pais>& adyacente) {
    this->paisesAdyacentes.push_back(adyacente);
}

void Pais::removerAdyacente(const ReferenceCountPtr<Pais> adyacente) {
    this->paisesAdyacentes.remove(adyacente);
}

ReferenceCountPtr<Pais> Pais::obtenerAdyacente(const std::string& nombre) {
    // Itero por cada pais adyacente.
    for (int counter = 0; counter < this->paisesAdyacentes.size(); ++counter) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = this->paisesAdyacentes[counter];
        // SI el nombre del pais actual coincide, devuelvo pais.
        if (*actual.getNombre() == nombre) {
            return actual;
        }
    }
    // Si no encontre pais, devuelvo NULL.
    return NULL;
}

Pais::~Pais() {
    // No realiza ninguna acciòn.
}

