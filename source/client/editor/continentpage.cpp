#include "continentpage.h"

ContinentPage::ContinentPage(const ReferenceCountPtr<Editor>& editor):
    Gtk::Frame(),
    verticalBox(),
    addContinentFrame(editor),
    viewContinentsFrame(editor),
    viewContinentCountriesFrame(editor) {

    // Agrego el frame para agregar continentes al vertical box.
    verticalBox.pack_start(addContinentFrame,
        Gtk::PACK_SHRINK);
    // Agrego el frame para visualizar continentes al vertical box.
    verticalBox.pack_start(viewContinentsFrame,
        Gtk::PACK_SHRINK);
    // Agregp eñ frame para visualizar paises de continentes al vertical box.
    verticalBox.pack_start(viewContinentCountriesFrame,
        Gtk::PACK_SHRINK);
    // Agrego el vertical box al frame.
    this->add(verticalBox);
}

void ContinentPage::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->addContinentFrame.setEditor(editor);
    this->viewContinentsFrame.setEditor(editor);
    this->viewContinentCountriesFrame.setEditor(editor);
}

ContinentPage::~ContinentPage() {
    // No realiza ninguna acciòn.
}

