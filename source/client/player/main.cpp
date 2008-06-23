#include "../../common/net/sockets/socket.h"
#include "../../common/commands/joingame.h"
#include <iostream>

#include<sstream>
int main(int argc, char** argv) {
	// Aca iria el codigo del cliente
	/*
	modo 2d
	ofrece cambiar ip, puerto y conectar

	ServerProxy es el hilo que escucha comandos del servidor
	el loop de GTKmm es el hilo que genera los comandos locales

	si es el primero (el server enviara un ChooseMap con una lista)
		aparecera un menu de seleccion de mapas y un choose

	boton de Ready
	area de chat
	
	*/

	Socket * socket = new Socket("localhost", 2000);

	JoinGame * joinGame = new JoinGame();
	std::string cmd = joinGame->serialize();
	std::cerr << cmd << std::endl;
	std::cerr << cmd.size() << std::endl;

	std::stringstream header;
	header << cmd.size();
	header << " joingame ";

	std::string msg = header.str();
	

	while (msg.size() < 30) {
		msg.append(".");
	}

	msg.append("\r\n");
	msg.append(cmd);

	socket->write(msg);
	std::cerr << msg << std::endl;

	//ServerProxy


}
