
#include "serverproxy.h"
#include<sstream>
#include <iostream>
void * ServerProxy::run() {
	

	std::stringstream msg;
	unsigned int msgLen;
	std::string commandName;
	std::string commandXml;

	while (true) {
		std::cerr << "ServerProxy leyendo encabezado " << std::endl;
		// deshardcodear este 32
		msg << socket.full_read(32);
		msg >> msgLen;
		msg >> commandName;

		std::cerr << "longitud " << msgLen << " nombre " << commandName << std::endl;
		commandXml = socket.full_read(msgLen);
		
		std::cerr << "serializacion " << commandXml << std::endl;
		gameManager->execute(commandName, commandXml);

	}
	return 0;
}

void ServerProxy::notify(const std::string & msg) {
	socket.write(msg);
}

ServerProxy::ServerProxy(Socket & socket,  ReferenceCountPtr< GameManager> & gameManager):socket(socket){
	this->gameManager= gameManager;
}

ServerProxy::~ServerProxy(){
	//delete(socket);
}

