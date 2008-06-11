#include "countrypage.h"

CountryPage::CountryPage(const ReferenceCountPtr<Editor>& editor):
    Gtk::Frame(),
    verticalBox(),
    addCountryToContinentFrame(editor),
    addCountryRelationFrame(editor) {

    // Agrego el frame para agregar paises a continentes al vertical box.
    verticalBox.pack_start(addCountryToContinentFrame,
        Gtk::PACK_SHRINK);
    // Agrego el frame para agregar relaciones entre paises al vertical box.
    verticalBox.pack_start(addCountryRelationFrame,
        Gtk::PACK_SHRINK);

    // Agrego el vertical box al frame.
    this->add(verticalBox);
}

void CountryPage::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->addCountryToContinentFrame.setEditor(editor);
    this->addCountryRelationFrame.setEditor(editor);
}

CountryPage::~CountryPage() {
    // No realiza ninguna acciòn.
}

