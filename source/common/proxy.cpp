
#include "proxy.h"
#include <sstream>
#include <iostream>
#include "../common/model/gamemanager.h"
#include "../common/commands/command.h"

void Proxy::notify(Command * command) {
	std::string cmd = command->serialize();
	std::cerr << "Proxy::notify(" << command->getName() << ") "<<cmd.size() <<" serializado: " << cmd << std::endl;

	std::stringstream header;
	header << cmd.size() << " " << command->getName() << " ";

	std::string msg = header.str();
	
	// deshardcodear este 30
	while (msg.size() < 30) {
		msg.append(".");
	}

	msg.append("\r\n");
	msg.append(cmd);

	std::cerr << "Proxy::notify socket->write("<< std::endl << msg << std::endl << ")" << std::endl << std::endl;

	socket->write(msg);
}

Proxy::Proxy(Socket * socket,  ReferenceCountPtr< GameManager> & gameManager){
	this->gameManager= gameManager;
	this->socket = socket;
}

Proxy::~Proxy(){
	delete(socket);
}




