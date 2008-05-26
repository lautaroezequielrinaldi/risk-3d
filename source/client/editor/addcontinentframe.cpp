#include "addcontinentframe.h"

AddContinentFrame::AddContinentFrame():
    Gtk::Frame(),
    editor(),
    verticalBox(),
    continentNameBox(),
    continentBonusBox(),
    continentButtonBox(),
    continentNameLabel(),
    continentNameEntry(),
    continentBonusLabel(),
    continentBonusEntry(),
    addContinentButton(),
    resetContinentButton() {

    // Establece el texto del label para indicarle al usuario que ingrese
    // el nombre del continente.
    this->continentNameLabel.set_text("Nombre de Continente:");

    // Establece el texto del label para indicarle al usuario que ingrese
    // el bonus del continente.
    this->continentBonusLabel.set_text("Bonus de Continente:");

    // Establece el rango de valores del entry para ignresar el bono del
    // continente.
    this->continentBonusEntry.set_range(0.00, 100.00);
    // Establece los digitos de precisiòn del entry para ingresar el bono
    // del continente.
    this->continentBonusEntry.set_digits(0);
    // Establece el incremento del entry para ingresar el bono del continente.
    this->continentBonusEntry.set_increments(1.0, 1.0);
    // Establece el valor inicial del entry para ingrsar el bono del continente.
    this->continentBonusEntry.set_value(0.00);

    // Establece el label del boton agregar continente.
    this->addContinentButton.set_label("Add");
    // Establece el label del boton reset continente.
    this->resetContinentButton.set_label("Reset");

    // Agrego el label del nombre del continente.
    this->continentNameBox.add(this->continentNameLabel);
    // Agrego el entry para ingresar el nombre del continente a su box
    // horizontal.
    this->continentNameBox.add(this->continentNameEntry);

    // Agrego el label del bonus del continente.
    this->continentBonusBox.add(this->continentBonusLabel);
    // Agrego el entry para ingresar el bonus del continente en su box.
    this->continentBonusBox.add(this->continentBonusEntry);

    // Agrego el boton para agregar al continente a su box.
    this->continentButtonBox.add(addContinentButton);

    // Agrego el boton para resetear el continente a su box.
    this->continentButtonBox.add(resetContinentButton);

    // Agrego el box para el nombre del continente al vertical box.
    this->verticalBox.add(this->continentNameBox);

    // Agrego el box para el bonus del continente al vertical box.
    this->verticalBox.add(this->continentBonusBox);

    // Agrego el box para los botones de accion al vertical box.
    this->verticalBox.add(this->continentButtonBox);

    // Agrego el vertical box al frame.
    this->add(this->verticalBox);
}

void AddContinentFrame::onAddContinentButtonClicked() {
    // No realiza ninguna acciòn.
}

void AddContinentFrame::onResetContinentButtonClicked() {
    // No realiza ninguna acciòn.
}

void AddContinentFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;
}

ReferenceCountPtr<Editor> AddContinentFrame::getEditor() {
    return this->editor;
}

AddContinentFrame::~AddContinentFrame() {
    // No realiza ninguna acciòn-
}
