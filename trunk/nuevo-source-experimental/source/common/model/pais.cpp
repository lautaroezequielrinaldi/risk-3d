#include "pais.h"

Pais::Pais(const std::string& nombre, const MapPosition& position):
    nombre(nombre),
    adyacentes(),
    position(position),
    cantidadEjercitos(0) {
    // No realiza ninguna acciòn.
}

std::string Pais::getNombre() {
    return this->nombre;
}

void Pais::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Pais::agregarAdyacente(const ReferenceCountPtr<Pais>& adyacente) {
    this->adyacentes.push_back(adyacente);
}

void Pais::removerAdyacente(const ReferenceCountPtr<Pais>& adyacente) {
    this->adyacentes.remove(adyacente);
}

ReferenceCountPtr<Pais> Pais::obtenerAdyacente(const std::string& nombre) {
    // Defino contador
    Iterador iter;

    // Itero por cada pais adyacente.
    for (iter = this->primerAdyacente(); iter != this->ultimoAdyacente();
        ++iter) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = *iter;
        // Verifico que el nombre del pais adyacente coincida.
        if (actual->getNombre() == nombre) {
            // Retorno actual.
            return actual;
        }
    }
    // Si no encontre pais, devuelvo NULL.
    return NULL;
}

bool Pais::esAdyacente(const std::string& nombre){
	
 // Defino contador
    Iterador iter;

    // Itero por cada pais adyacente.
    for (iter = this->primerAdyacente(); iter != this->ultimoAdyacente();
        ++iter) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = *iter;
        // Verifico que el nombre del pais adyacente coincida.
        if (actual->getNombre() == nombre) {
            // Retorno true.
            return true;
        }
    }
    // Si no encontre pais, devuelvo false.
    return false;
	
}

Pais::Iterador Pais::primerAdyacente() {
    return this->adyacentes.begin();
}

Pais::Iterador Pais::ultimoAdyacente() {
    return this->adyacentes.end();
}

void Pais::setPosition(const MapPosition& position) {
    this->position = position;
}

MapPosition& Pais::getPosition() {
    return this->position;
}

int Pais::getArmyCount(){
	return this->cantidadEjercitos;

}

void Pais::addArmies( int armyCount ){
	
	this->cantidadEjercitos += armyCount; 
}	

void Pais::removeArmies ( int armyCount ){
	
	this->cantidadEjercitos -= armyCount;
}

Pais::~Pais() {
    // No realiza ninguna acciòn.
    
}

