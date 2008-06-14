#include "editor.h"

Editor::Editor(const std::string& imageFileName):
    mapa(),
	imageFileName(imageFileName) {
    // Inicializa el mapa que va a usar el editor.
    this->mapa = new Mapa();
}

void Editor::setMapa(const ReferenceCountPtr<Mapa>& mapa) {
    this->mapa = mapa;
}

ReferenceCountPtr<Mapa>& Editor::getMapa() {
    return this->mapa;
}

void Editor::setImageFileName(const std::string& imageFileName) {
	this->imageFileName = imageFileName;
}

std::string& Editor::getImageFileName() {
	return this->imageFileName;
}

Editor::~Editor() {
    // No realiza ninguna acciòn.
}

