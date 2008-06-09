#include "continentpage.h"

ContinentPage::ContinentPage(const ReferenceCountPtr<Editor>& editor):
    Gtk::Frame(),
    verticalBox(),
    addContinentFrame(editor),
    viewContinentsFrame(editor),
    viewContinentCountriesFrame(editor) {

    // Agrego el frame para agregar continentes al vertical box.
    verticalBox.add(addContinentFrame);
    // Agrego el frame para visualizar continentes al vertical box.
    verticalBox.add(viewContinentsFrame);
    // Agregp eñ frame para visualizar paises de continentes al vertical box.
    verticalBox.add(viewContinentCountriesFrame);
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

