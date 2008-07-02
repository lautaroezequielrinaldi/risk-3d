#include "populateclientcommand.h"

PopulateClientCommand::PopulateClientCommand(ReferenceCountPtr<Game>& game): ClientCommand(game) {
	/// No realiza ninguna accion.
}

void PopulateClientCommand::execute() {
	// No realiza ninguna accion.
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

