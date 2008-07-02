#include "moveclientcommand.h"

MoveClientCommand::MoveClientCommand(ReferenceCountPtr<Game>& game): Move(), ClientCommand(game) {
	/// No realiza ninguna accion.
}

void MoveClientCommand::execute() {
    ReferenceCountPtr<Mapa> map = getGame()->getMapa();
    ReferenceCountPtr<Pais> paisOrig = map->obtenerPais(getCountryOrigin());
    ReferenceCountPtr<Pais> paisDest = map->obtenerPais(getCountryDestination());

    paisOrig->removeArmies(getArmyCount());
    paisDest->addArmies(getArmyCount());
}

ClientCommand* MoveClientCommand::clone() {
	return new MoveClientCommand(getGame());
}

MoveClientCommand::~MoveClientCommand() {
	// No realiza ninguna accion.
}

