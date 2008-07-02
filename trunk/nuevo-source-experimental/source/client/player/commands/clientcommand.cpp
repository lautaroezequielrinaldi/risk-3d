#include "clientcommand.h"

ClientCommand::ClientCommand(ReferenceCountPtr<Game>& game): game(game) {
	// No realiza ninguna accion.
}

ReferenceCountPtr<Game>& ClientCommand::getGame() {
    return this->game;
}

ClientCommand::~ClientCommand() {
	// No realiza ninguna accion.
}

