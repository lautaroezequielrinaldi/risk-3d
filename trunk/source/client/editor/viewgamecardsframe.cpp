#include "viewgamecardsframe.h"

ViewGameCardsFrame::ViewGameCardsFrame(const ReferenceCountPtr<Editor>& editor):	Observer(),
	Gtk::Frame(),
	editor(editor) {

}

void ViewGameCardsFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
	this->editor = editor;

	if (this->editor != NULL) {
		this->editor->registerObserver(this);
	}
}

ReferenceCountPtr<Editor>& ViewGameCardsFrame::getEditor() {
	return this->editor;
}

void ViewGameCardsFrame::update(Subject* subject) {
}

ViewGameCardsFrame::~ViewGameCardsFrame() {
	// No realiza ninguna accion.
}

