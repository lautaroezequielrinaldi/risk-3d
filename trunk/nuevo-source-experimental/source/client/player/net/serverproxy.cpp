#include "serverproxy.h"
#include "../../../common/model/game.h"
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
		
		std::cerr<<"LLEGO A HACER FULL READ"<<std::endl;
		
		msg >> msgLen;
		msg >> commandName;

		std::cerr << "longitud " << msgLen << " nombre " << commandName << std::endl;
		commandXml = getSocket()->full_read(msgLen);
		
		std::cerr << "serializacion: " << commandXml << std::endl;
		
        if (commandHydrator.isClientCommand(commandName)) {
            std::cerr << "Invocando ClientCommandHydrator::createCommand(" << commandName << ", " << commandXml << ");" << std::endl;
            ReferenceCountPtr<ClientCommand> command = commandHydrator.createCommand(commandName, commandXml);
            std::cerr << "Ejecutando comando..." << std::endl;
            if (command != NULL) {
                command->execute();
            }
            std::cerr << "Se pudo ejecutar comando..." << std::endl;
           
           
            notifyCommandExecuted(*command);
            
        } else {
            ReferenceCountPtr<Command> command = messageHydrator.createCommand(commandName, commandXml);
            
            if ( command == NULL )
            	std::cerr<<"el comando devuelto por messageHydrator es NULL....."<<std::endl;
            else
            	std::cerr << "Se pudo crear comando con messageHydrator" << std::endl;
            
            notifyCommandExecuted(*command);
            
            if ( command->getName() == "mapList" )  
            	dispatcherMapList.emit();
        }
	}
	return 0;
}


ServerProxy::ServerProxy(const ReferenceCountPtr<Socket>& socket,  const ReferenceCountPtr< Game> & game):
Proxy(socket), 
game(game),
commandHydrator(game),
messageHydrator() 
{
		
}

Dispatcher& ServerProxy::getDispatcherMapList(){	
	return this->dispatcherMapList;
}


ServerProxy::~ServerProxy(){

}

