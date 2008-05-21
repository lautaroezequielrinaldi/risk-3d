#include<string>
#include<iostream>
#include "referencecountptr.h"
#include "mapa.h"
#include "pais.h"
#include "continente.h"
#include "mapaparser.h"

int main(int argc, char** argv) {
    ReferenceCountPtr<Mapa> mapa(new Mapa());

    ReferenceCountPtr<Continente> america(new Continente("AMERICA"));
    ReferenceCountPtr<Continente> asia(new Continente("ASIA"));
    ReferenceCountPtr<Continente> europa(new Continente("EUROPA"));

    ReferenceCountPtr<Pais> argentina(new Pais("ARGENTINA"));
    ReferenceCountPtr<Pais> bolivia(new Pais("BOLIVIA"));

    
    argentina->agregarAdyacente(bolivia);
    
    america->agregarPais(argentina);

    mapa->agregarPais(argentina);
    mapa->agregarPais(bolivia);

    mapa->agregarContinente(america);
    mapa->agregarContinente(asia);
    mapa->agregarContinente(europa);

    MapaParser parser;

    parser.saveMap("mapa.xml", mapa);

    ReferenceCountPtr<Pais> pais = mapa->obtenerPais("ARGENTINA");
    ReferenceCountPtr<Continente> continente =
        mapa->obtenerContinente("EUROPA");
    if (pais != NULL) {
        std::cout << "Contiene Argentina" << std::endl;
    }
    if (continente != NULL) {
        std::cout << "Contiene Europa" << std::endl;
    }

    ReferenceCountPtr<Mapa> otroMapa = parser.loadMap("mapa.xml");

    Mapa::IteradorPais iterPais;

    for (iterPais = otroMapa->primerPais(); iterPais != otroMapa->ultimoPais();
        ++iterPais) {
        ReferenceCountPtr<Pais> actual = *iterPais;
        std::cout << actual->getNombre() << std::endl;
    }

    return 0;
}

