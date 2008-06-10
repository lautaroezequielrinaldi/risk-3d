#include "countrypage.h"

CountryPage::CountryPage(const ReferenceCountPtr<Editor>& editor):
    Gtk::Frame(),
    verticalBox(),
    addCountryToContinentFrame(editor) {

    // Agrego el frame para agregar paises a continentes al vertical box.
    verticalBox.add(addCountryToContinentFrame);
    // Agrego el vertical box al frame.
    this->add(verticalBox);
}

void CountryPage::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->addCountryToContinentFrame.setEditor(editor);
}

CountryPage::~CountryPage() {
    // No realiza ninguna acciòn.
}

