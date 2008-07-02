#include "moveclientcommand.h"

/*MoveClientCommand::PopulateClientCommand() {
	/// No realiza ninguna accion.
}*/

void MoveClientCommand::execute() {
	// No realiza ninguna accion.
}

std::string MoveClientCommand::getType() {
	return "MOVE";
}

ClientCommand* MoveClientCommand::clone() {
	return new MoveClientCommand();
}

MoveClientCommand::~MoveClientCommand() {
	// No realiza ninguna accion.
}

