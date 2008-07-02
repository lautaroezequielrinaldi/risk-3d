#include "moveclientcommand.h"

MoveClientCommand::MoveClientCommand(ReferenceCountPtr<Game>& game): ClientCommand(game) {
	/// No realiza ninguna accion.
}

void MoveClientCommand::execute() {
	// No realiza ninguna accion.
}

std::string MoveClientCommand::getType() {
	return "MOVE";
}

ClientCommand* MoveClientCommand::clone() {
	return new MoveClientCommand(getGame());
}

MoveClientCommand::~MoveClientCommand() {
	// No realiza ninguna accion.
}

