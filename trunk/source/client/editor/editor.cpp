#include "editor.h"

Editor::Editor():
    mapa() {
    // Inicializa el mapa que va a usar el editor.
    this->mapa = new Mapa();
}

void Editor::setMapa(const ReferenceCountPtr<Mapa>& mapa) {
    this->mapa = mapa;
}

ReferenceCountPtr<Mapa> Editor::getMapa() {
    return this->mapa;
}

Editor::~Editor() {
    // No realiza ninguna acciòn.
}

