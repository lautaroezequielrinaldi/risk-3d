#include "uicommand.h"
#include "commandobserver.h"

UICommand::UICommand(std::vector<std::string> &parameterList): Command() {
	// No realiza ninguna accion.
}
 
UICommand::UICommand(): Command() {
	// No realiza ninguna accion.
}

void UICommand::accept(CommandObserver* observer) {
	// No realiza ninguna accion para los comandos de UI.
}

UICommand::~UICommand() {
	// No realiza ninguna accion.
}

