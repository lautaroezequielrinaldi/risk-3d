
#include "serverproxy.h"
#include "../../common/model/game.h"

#include<sstream>
#include <iostream>
void * ServerProxy::run() {
	



	while (! isCanceled()) {
		std::stringstream msg;
		unsigned int msgLen;
		std::string commandName;
		std::string commandXml;

		std::cerr<< std::endl << "################################"<< std::endl<<"ServerProxy leyendo encabezado " << std::endl;
		// deshardcodear este 32
		msg << getSocket()->full_read(32);
		msg >> msgLen;
		msg >> commandName;

		std::cerr << "longitud " << msgLen << " nombre " << commandName << std::endl;
		commandXml = getSocket()->full_read(msgLen);
		
		std::cerr << "serializacion " << commandXml << std::endl;
        if (commandHydrator.isClientCommand(commandName)) {
            ReferenceCountPtr<ClientCommand> command = commandHydrator.createCommand(commandName, commandXml);
            command->execute();
            notifyCommandExecuted(*command);
        } else {
            ReferenceCountPtr<Command> command = messageHydrator.createCommand(commandName, commandXml);
            notifyCommandExecuted(*command);
        }
	}
	return 0;
}


ServerProxy::ServerProxy(const ReferenceCountPtr<Socket>& socket,  const ReferenceCountPtr< Game> & game):Proxy(socket), game(game),commandHydrator(game), messageHydrator() {
	
}

ServerProxy::~ServerProxy(){

}

