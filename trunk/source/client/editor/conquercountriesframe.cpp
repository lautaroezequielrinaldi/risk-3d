#include "conquercountriesframe.h"

ConquerCountriesFrame::ConquerCountriesFrame(
	const ReferenceCountPtr<Editor>& editor):
	Observer(),
	GameCardFrame(editor),
	countryCountLabel(),
	countryCountSpinButton() {

	// Se agrega como observador del editor.
	if (this->editor != NULL) {
		this->editor->registerObserver(this);
	}

	// Establece el texto del label de cantidad de paises.
	this->countryCountLabel.set_text("Ingrese cantidad de paises:");

	// Agrego el label de cantidad de paises al vertical box.
	this->verticalBox.pack_start(this->countryCountLabel,
		Gtk::PACK_SHRINK);
	// Agrego el spin button de cantidad de paises al vertical box.
	this->verticalBox.pack_start(this->countryCountSpinButton,
		Gtk::PACK_SHRINK);

    // Popula el rango de cantidad de paises a elegir.
    this->populate();
}

void ConquerCountriesFrame::populate() {
	if (this->editor != NULL && this->editor->getMapa() != NULL) {
		// Establece el nuevo rango de cantidad de paises a elegir.
        this->countryCountSpinButton.set_range(0.00,
			this->editor->getMapa()->getCantidadPaises());
         // Establece los digitos de precisiòn del entry para elegir cantidad
         // de paises
         this->countryCountSpinButton.set_digits(0);
         // Establece el incremento del entry para elegir cantidad de paises.
         this->countryCountSpinButton.set_increments(1.0, 1.0);
	}
}

void ConquerCountriesFrame::onAddGameCardButtonClicked() {
	// Si el editor no es null y el mapa no es null
	if (this->editor != NULL && this->editor->getMapa() != NULL) {
		// Obtengo el mapa.
		ReferenceCountPtr<Mapa> map = this->editor->getMapa();

		// Obtengo nombre de carta de juego.
		std::string gameCardName = this->gameCardNameEntry.get_text();
		// Obtengo cantidad de paises.
		int countryCount = this->countryCountSpinButton.get_value_as_int();

		// Verifico que los datos sean validos.
		if (!gameCardName.empty() && countryCount > 0) {
			// Creo carta de juego.
			ReferenceCountPtr<GameCard> gameCard =
				new ConquerCountriesGameCard(gameCardName, countryCount);
			// Agrego carta de juego a mapa.
			map->agregarGameCard(gameCard);
			// Notifico del cambio en el editor.
			this->editor->notify();
		}
	}
}

void ConquerCountriesFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
	GameCardFrame::setEditor(editor);

	if (this->editor != NULL) {
		this->editor->registerObserver(this);
	}

	// Popula el rango de cantidad de paises a elegir.
	this->populate();
}

void ConquerCountriesFrame::update(Subject* subject) {
    // Popula el rango de cantidad de paises a elegir.
	this->populate();
}

ConquerCountriesFrame::~ConquerCountriesFrame() {
	// No realiza ninguna accion.
}

