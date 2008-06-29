
#include "playerproxy.h"
#include "../common/model/player.h"
#include "../common/model/gamemanager.h"
#include<sstream>
#include <iostream>
void * PlayerProxy::run() {

	std::stringstream msg;
	unsigned int msgLen;
	std::string commandName;
	std::string commandXml;

	while (! isCanceled()) {
		std::cerr << "PlayerProxy leyendo encabezado " << std::endl;
		// deshardcodear este 32
		msg << socket->full_read(32);
		msg >> msgLen;
		msg >> commandName;

		std::cerr << "longitud " << msgLen << " nombre " << commandName << std::endl;
		commandXml = socket->full_read(msgLen);
		
		std::cerr << "serializacion " << commandXml << std::endl;
		// pasar *this para que los waiting·::joingame sepan
		gameManager->execute(commandName, commandXml);

	}
	return 0;
}

PlayerProxy::PlayerProxy(Socket * socket, ReferenceCountPtr< GameManager> & gameManager):Proxy(socket,gameManager){

}

PlayerProxy::~PlayerProxy(){

}

void PlayerProxy::setPlayer(ReferenceCountPtr<Player> & player){
	this->player = player;
}

ReferenceCountPtr<Player> & PlayerProxy::getPlayer(){
	return player;

}

