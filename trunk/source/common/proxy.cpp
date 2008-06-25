
#include "proxy.h"
#include <sstream>
#include <iostream>
#include "../common/model/gamemanager.h"
#include "../common/commands/command.h"

void Proxy::notify(Command * command) {
	std::string cmd = command->serialize();
	std::cerr << cmd << std::endl;
	std::cerr << cmd.size() << std::endl;

	std::stringstream header;
	header << cmd.size() << " " << command->getName() << " ";

	std::string msg = header.str();

	while (msg.size() < 30) {
		msg.append(".");
	}

	msg.append("\r\n");
	msg.append(cmd);

	std::cerr << "Escribiendo..." << std::endl;

	socket->write(msg);
}

Proxy::Proxy(Socket * socket,  ReferenceCountPtr< GameManager> & gameManager){
	this->gameManager= gameManager;
	this->socket = socket;
}

Proxy::~Proxy(){
	delete(socket);
}




