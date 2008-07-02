#include "nomoreclientcommand.h"

/*NoMoreClientCommand::PopulateClientCommand() {
	/// No realiza ninguna accion.
}*/

void NoMoreClientCommand::execute() {
	// No realiza ninguna accion.
}

std::string NoMoreClientCommand::getType() {
	return "NOMORE";
}

ClientCommand* NoMoreClientCommand::clone() {
	return new NoMoreClientCommand();
}

NoMoreClientCommand::~NoMoreClientCommand() {
	// No realiza ninguna accion.
}

