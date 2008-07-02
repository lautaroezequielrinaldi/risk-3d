#include "attackclientcommand.h"

/*AttackClientCommand::AttackClientCommand() {
	/// No realiza ninguna accion.
}*/

void AttackClientCommand::execute() {
	// No realiza ninguna accion.
}

std::string AttackClientCommand::getType() {
	return "ATTACK";
}

ClientCommand* AttackClientCommand::clone() {
	return new AttackClientCommand();
}

AttackClientCommand::~AttackClientCommand() {
	// No realiza ninguna accion.
}

