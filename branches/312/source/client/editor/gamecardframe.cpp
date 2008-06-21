#include "gamecardframe.h"

GameCardFrame::GameCardFrame(const ReferenceCountPtr<Editor>& editor):
	Gtk::Frame(),
	editor(editor),
	verticalBox(),
	gameCardNameLabel(),
	gameCardNameEntry(),
	addGameCardButton() {

	// Establece el texto del label para nombre de carta de juego.
	this->gameCardNameLabel.set_text("Nombre de carta de juego:");

	// Establece el texto del boton para agregar carta de juego.
	this->addGameCardButton.set_label("Agregar carta de juego");

	// Agrega el label de nombre de carta de juego al vertical box.
	this->verticalBox.pack_start(this->gameCardNameLabel,
		Gtk::PACK_SHRINK);

	// Agrega el entry de nombre de carta de juego al vertical box.
	this->verticalBox.pack_start(this->gameCardNameEntry,
		Gtk::PACK_SHRINK);

	// Agrega el boton para agregar carta de juego al vertical box.
	this->verticalBox.pack_end(this->addGameCardButton,
		Gtk::PACK_SHRINK);

	// Agrega el vertical box al frame.
	this->add(this->verticalBox);

	// Asocia la senal signal_clicked del boton addGameCardButton al
	// manejador correspondiente.
	this->addGameCardButton.signal_clicked().connect(sigc::mem_fun(*this,
		&GameCardFrame::onAddGameCardButtonClicked));
}

void GameCardFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
	this->editor = editor;
}

ReferenceCountPtr<Editor>& GameCardFrame::getEditor() {
	return this->editor;
}

GameCardFrame::~GameCardFrame() {
	// No realiza niguna accion.
}

