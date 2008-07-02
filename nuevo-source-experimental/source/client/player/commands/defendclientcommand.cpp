#include "defendclientcommand.h"

/*DefendClientCommand::DefendClientCommand() {
	/// No realiza ninguna accion.
}*/

void DefendClientCommand::execute() {
	// No realiza ninguna accion.
}

std::string DefendClientCommand::getType() {
	return "DEFEND";
}

ClientCommand* DefendClientCommand::clone() {
	return new DefendClientCommand();
}

DefendClientCommand::~DefendClientCommand() {
	// No realiza ninguna accion.
}

