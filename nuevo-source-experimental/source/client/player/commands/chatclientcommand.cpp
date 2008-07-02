#include "chatclientcommand.h"

/*ChatClientCommand::ChatClientCommand() {
	/// No realiza ninguna accion.
}*/

void ChatClientCommand::execute() {
	// No realiza ninguna accion.
}

std::string ChatClientCommand::getType() {
	return "CHAT";
}

ClientCommand* ChatClientCommand::clone() {
	return new ChatClientCommand();
}

ChatClientCommand::~ChatClientCommand() {
	// No realiza ninguna accion.
}

