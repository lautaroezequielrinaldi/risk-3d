#include "gamecardpage.h"

GameCardPage::GameCardPage(const ReferenceCountPtr<Editor>& editor):
	Gtk::Frame(),
	conquerContinentFrame(editor),
	conquerPlayerFrame(editor),
	conquerCountriesFrame(editor),
	viewGameCardsFrame(editor) {

	// Agrega el frame para agregar cartas de juego para conquistar
	// continentes al vertical box.
	this->verticalBox.pack_start(this->conquerContinentFrame,
		Gtk::PACK_SHRINK);
	// Agrego el frame para agregar cartas de juego para conquistar
	// jugadores al vertical box.
	this->verticalBox.pack_start(this->conquerPlayerFrame,
		Gtk::PACK_SHRINK);
	// Agrego el frame para agregar cartas de juego para conquistar N
	// paises al verical box.
	this->verticalBox.pack_start(this->conquerCountriesFrame,
		Gtk::PACK_SHRINK);
	// Agrega el frame para listar cartas de juego al vertical box.
	this->verticalBox.pack_start(this->viewGameCardsFrame,
		Gtk::PACK_SHRINK);

	// Agrega el vertical box al frame.
	this->add(this->verticalBox);
}

void GameCardPage::setEditor(const ReferenceCountPtr<Editor>& editor) {
	this->conquerContinentFrame.setEditor(editor);
	this->conquerPlayerFrame.setEditor(editor);
	this->conquerCountriesFrame.setEditor(editor);
	this->viewGameCardsFrame.setEditor(editor);
}

GameCardPage::~GameCardPage() {
	// No realiza ninguna accion.
}

