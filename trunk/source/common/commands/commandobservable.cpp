#include "commandobservable.h"
#include "command.h"
#include "commandobserver.h"

CommandObservable::CommandObservable() {
	// No realiza ninguna accion.
}

void CommandObservable::notifyCommandExecuted(Command* command) {
	std::list<CommandObserver*>::iterator iter;
	for (iter = commandObserverList.begin(); iter != commandObserverList.end();
		++iter) {
		CommandObserver* commandObserver = *iter;
		command->accept(commandObserver);
	}
}

void CommandObservable::registerCommandObserver(CommandObserver* observer) {
	commandObserverList.push_back(observer);
}

void CommandObservable::unregisterCommandObserver(CommandObserver* observer)  {
	commandObserverList.remove(observer);
}

CommandObservable::~CommandObservable() {
	// No realiza ninguna accion.
}

