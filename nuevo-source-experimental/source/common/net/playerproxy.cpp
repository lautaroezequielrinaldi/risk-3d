
#include "playerproxy.h"
#include "../../common/model/player.h"
#include "../../common/model/gamemanager.h"
#include<sstream>
#include <iostream>



void * PlayerProxy::run() {
	
	
	while (! isCanceled()) {
	
		std::stringstream msg;
		unsigned int msgLen;
		std::string commandName;
		std::string commandXml;
		
		std::cerr << std::endl << "################################"<< std::endl<< "PlayerProxy leyendo encabezado " << std::endl;
		
		// deshardcodear este 32
		std::cerr << "********** A PUNTO DE INVOCAR A SOCKET::FULL_READ(32)" << std::endl << std::endl;
        if (getSocket() != NULL) {
            std::cerr << "********* SOCKET ERA NULL" << std::endl;
        } else {
            std::cerr << "********* SOCKET NOOOO ES NULL" << std::endl;
        }
		msg << getSocket()->full_read(32);
        std::cerr << "********** SE INVOCO CORRECTAMENTE A SOCKET::FULL_READ(32)" << std::endl << std::endl;
		msg >> msgLen;
		msg >> commandName;

		std::cerr << "longitud " << msgLen << " nombre " << commandName << std::endl;
		commandXml = getSocket()->full_read(msgLen);
		
		//std::cerr << "serializacion " << commandXml << std::endl;
		// pasar *this para que los waiting·::joingame sepan
		
		gameManager->execute(commandName, commandXml);

	}
	return 0;
}

PlayerProxy::PlayerProxy(const ReferenceCountPtr<Socket>& socket, const ReferenceCountPtr< GameManager> & gameManager):
Proxy(socket), 
gameManager(gameManager) {

	this->readyToPlay=false;

}

PlayerProxy::~PlayerProxy(){

}

void PlayerProxy::setPlayer(ReferenceCountPtr<Player> & player){
	this->player = player;
}

ReferenceCountPtr<Player> & PlayerProxy::getPlayer(){
	return player;

}

void PlayerProxy::setReadyToPlay(bool state){
	this->readyToPlay=state;
}
bool PlayerProxy::isReadyToPlay(){
	return this->readyToPlay;
}





