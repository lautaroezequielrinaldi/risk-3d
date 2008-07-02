#include "populateclientcommand.h"

PopulateClientCommand::PopulateClientCommand(ReferenceCountPtr<Game>& game): ClientCommand(game) {
	/// No realiza ninguna accion.
}

void PopulateClientCommand::execute() {
    ReferenceCountPtr<Mapa> map = this->game->getMapa();
    ReferenceCountptr<Pais> pais = map->obtenerPais(this->paisDestino);
    pais->addArmies(getArmyCount());
}

std::string PopulateClientCommand::getType() {
	return "POPULATE";
}

ClientCommand* PopulateClientCommand::clone() {
	return new PopulateClientCommand(getGame());
}

PopulateClientCommand::~PopulateClientCommand() {
	// No realiza ninguna accion.
}

