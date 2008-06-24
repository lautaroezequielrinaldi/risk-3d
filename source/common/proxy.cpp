
#include "proxy.h"
#include <sstream>
#include <iostream>
#include "../common/model/gamemanager.h"

void Proxy::notify(const std::string & msg) {
	socket->write(msg);
}

Proxy::Proxy(Socket * socket,  ReferenceCountPtr< GameManager> & gameManager){
	this->gameManager= gameManager;
	this->socket = socket;
}

Proxy::~Proxy(){
	delete(socket);
}




