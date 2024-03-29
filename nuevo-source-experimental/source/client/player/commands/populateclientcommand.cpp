#include "populateclientcommand.h"

PopulateClientCommand::PopulateClientCommand(ReferenceCountPtr<Game>& game): Populate(), ClientCommand(game) {
	/// No realiza ninguna accion.
}

void PopulateClientCommand::execute() {
    ReferenceCountPtr<Mapa> map = this->getGame()->getMapa();
    ReferenceCountPtr<Pais> pais = map->obtenerPais(this->getCountryDestination());
    pais->addArmies(getArmyCount());
}

ClientCommand* PopulateClientCommand::clone() {
	return new PopulateClientCommand(getGame());
}

PopulateClientCommand::~PopulateClientCommand() {
	// No realiza ninguna accion.
}

