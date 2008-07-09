#include "commandobservable.h"
#include "command.h"
#include "commandobserver.h"
#include<iostream>
CommandObservable::CommandObservable() {
	// No realiza ninguna accion.
}

void CommandObservable::notifyCommandExecuted(Command& command) {
	
	std::list<CommandObserver*>::iterator iter;
	
	for (iter = commandObserverList.begin(); iter != commandObserverList.end();
		++iter) {
		CommandObserver* commandObserver = *iter;
        std::cerr << "A punto de notificar comando en CommandObservable" << std::endl;
		command.accept(commandObserver);
        std::cerr << "Se notifico comando en CommandObservable" << std::endl;
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

