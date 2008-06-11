#include "gamecardpage.h"

GameCardPage::GameCardPage(const ReferenceCountPtr<Editor>& editor):
	Gtk::Frame(),
	viewGameCardsFrame(editor) {

	// Agrega el frame para listar cartas de juego al vertical box.
	this->verticalBox.pack_start(this->viewGameCardsFrame,
		Gtk::PACK_SHRINK);

	// Agrega el vertical box al frame.
	this->add(this->verticalBox);
}

void GameCardPage::setEditor(const ReferenceCountPtr<Editor>& editor) {
	this->viewGameCardsFrame.setEditor(editor);
}

GameCardPage::~GameCardPage() {
	// No realiza ninguna accion.
}

