
#include "serverproxy.h"
#include "../common/model/gamemanager.h"
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
		msg << socket->full_read(32);
		msg >> msgLen;
		msg >> commandName;

		std::cerr << "longitud " << msgLen << " nombre " << commandName << std::endl;
		commandXml = socket->full_read(msgLen);
		
		std::cerr << "serializacion " << commandXml << std::endl;
		gameManager->execute(commandName, commandXml);

	}
	return 0;
}


ServerProxy::ServerProxy(Socket * socket,  ReferenceCountPtr< GameManager> & gameManager):Proxy(socket,gameManager){
	
}

ServerProxy::~ServerProxy(){

}

