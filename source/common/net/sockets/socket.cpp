/**
 * Taller de Programacion I (75.42)
 * Facultad de Ingenieria -- Universidad de Buenos Aires.
 * Autor: Pablo Martìn Viva.
 * Archivo: socket.cpp
 * Descripcion: Implementaciòn de la clase Socket que encapsularà un socket
 * stream sobre el protocolo TCP / IP.
 */

/**
 * Project Includes.
 */
#include "socket.h"



// pasar a su propio archivo  >>>>>>>>>>>>>>

#ifndef __PROXYPLAYER_H__
#define __PROXYPLAYER_H__
#include "../../../common/thread/threaded.h"


/**
 *
 * @todo usar & en lugar de *
 */
class PlayerProxy:public Threaded {
	private:
	Socket * socket;
	// State & state;
	// GameController & gamecontroller;

	protected:
	void * run();

	public:
	PlayerProxy(Socket * socket);

	~PlayerProxy();

};
#endif /** __PROXYPLAYER_H__ */

//#include "proxyplayer.h"
void * PlayerProxy::run() {
	// while jugando {
	//   se bloquea leyendo el socket
	//   cuando llega el mensaje,
	//   se obtiene un lock sobre el estado.
	//   dependiendo del estado, al cual todos los jugadores acceden
	//   se toma alguna accion, que puede involucrar escribir en todos los demas jugadores
	//   devuelve el lock
	// }

	return 0;
}

PlayerProxy::PlayerProxy(Socket * socket){
	this->socket = socket;
}

PlayerProxy::~PlayerProxy(){
	delete(socket);
}


// pasar a su propio archivo  <<<<<<<<<<<<<<<<


/**
 * Client socket
 *
 *
 */
Socket::Socket(const std::string& destination, int port)
    throw(SocketConnectionException) {
    // Inicializa el socket.
    this->initialize();

    // Conecta el socket.
    this->connect(destination, port);
}


void Socket::initialize() {
   this->socketDescriptor = ::socket(PF_INET, SOCK_STREAM, 0);
}

bool Socket::is_valid() {
    return (this->socketDescriptor != INVALID_SOCKET_DESCRIPTOR);
}

/**
 * Server socket
 *
 *
 */
Socket::Socket(int port, int client_wait)
     throw(SocketConnectionException){
}

Socket::Socket(const int & socketDescriptor)
     throw(SocketConnectionException){
     this->socketDescriptor=socketDescriptor;

}

Socket * Socket::accept()
     throw(SocketConnectionException){
     return 0;


}

void Socket::connect(const std::string& destination, int port)
    throw(SocketConnectionException) {

    if (this->is_valid() ) {
        // Defino entidad del host al cual se va a conectar el socket.
        hostent* hostnameInformation;
        // Defino la direcciòn TCP / IP del host al cual se va a conectar el
        // socket.
        in_addr* hostnameInetAddress;
        // Defino la direcciòn TCP / IP del host al cual se va a conectar el
        // socket como cadena de caracteres.
        char* hostnameAddress;
        // Defino la direccion TCP / IP destino a la cual se va a conectar el
        // socket.
        sockaddr_in address;
        // Defino valor de retorno de la funcion connect.
        int returnValue;

        // Obtengo informaciòn del host al cual se va a conectar el socket.
        hostnameInformation = gethostbyname(destination.c_str());

        // Valido que puedo obtener informaciòn del hostname.
        if (hostnameInformation == NULL) {
            throw SocketConnectionException("no se pudo obtener hostname\n");
        }

        // Obtengo la direcciòn TCP / IP del host al cual se va a conectar el
        // socket.
        hostnameInetAddress = (in_addr*) hostnameInformation->h_addr;

        // Obtengo la direcciòn TCP / IP del host al cual se va a conectar el
        // socket como cadena de caracteres.
        hostnameAddress = inet_ntoa(*hostnameInetAddress);

        // Inicializo la direccion TCP / IP.
        memset(&address, 0, sizeof(address));

        // Establezco valores de direccion TCP / IP.
        address.sin_family = AF_INET;
        address.sin_port = htons(port);
        inet_aton(hostnameAddress, &address.sin_addr);

        // Conecto el socket a la direcciòn TCP / IP.
        returnValue = ::connect(this->socketDescriptor, (sockaddr*) &address,
            sizeof(address));

        // Valido que me pude conectar.
        if (returnValue == -1) {
            throw SocketConnectionException("no se pudo conectar\n");
        }
    } else {
        throw SocketConnectionException("connect sobre socket invalido\n");
    }
}


void Socket::listen(int port, int client_wait)
     throw(SocketConnectionException){


}


int Socket::write(const char* data, int length)
    throw(SocketIOException) {
    // Valido que el socket es valido.
    if (this->is_valid() ) {
        // Defino valor de retorno de la funcion send.
        int returnValue;

        // Envio mensaje al socket.
        returnValue = send(this->socketDescriptor, data, length, 0);

        // Verifico que se pudo enviar mensaje.
        if (returnValue != -1) {
            return returnValue;
        }
    }
    throw SocketIOException("write sobre socket invalido\n");
}

std::string Socket::full_read(int length)
	throw(SocketIOException) {

	char * buffer = new char[length];
	full_read(buffer,length);

	std::string result;
	result.append(buffer, length);

	delete[] buffer;
	return result;
}

void Socket::full_read(char* data, int length)
	throw(SocketIOException) {

	int read = 0;
	int toread = length;

	while (toread) {
		read = this->read(data + read,toread);
		toread = length - read;
	}
}

int Socket::read(char* data, int length)
    throw(SocketIOException) {
    //Valido que el socket es valido.
    if (this->is_valid() ) {
        // Defino valor de retorno de la funcion recv.
        int returnValue;

        // Recibo mensaje del socket.
        returnValue = ::recv(this->socketDescriptor, data, length, 0);

        // Verifico que se pudo recibir mensaje.
        if (returnValue != -1) {
            return returnValue;
        }
    }
    throw SocketIOException("read sobre socket invalido\n");
}

/**
 *
 * @todo evaluar si tiene sentido tener Socket::close() fuera de ~Socket()
 */
void Socket::close() {
    if (this->is_valid() ) {
        ::close(this->socketDescriptor);
    }
}

Socket::~Socket() {
    if (this->is_valid() ) {
        this->close();
    }
}

/**
 *
 * @todo pasar el error a la excepcion
 */
std::string Socket::readLine() throw(SocketIOException) {
        int error = 0;
        char oneChar;
        std::string s;
        while(error != -1) {
                error = read(&oneChar,1);
                if (oneChar == 0x0d) {
                        read(&oneChar,1);
                        if (oneChar == 0x0a) {
                                return s;
                        }
                        throw SocketIOException("error de protocolo");
                }
                s.push_back(oneChar);
        }
        throw SocketIOException("indefinido");
}



/**
 *
 *
 * Esto se parece mucho al principal de server.cpp
 *
 */


#include <iostream>
#include <vector>

int main (int argc, char** argv) {
/*
	std::cerr<< "x1x";
	Socket socket("localhost",25);
	std::cerr<< "x2x";
	socket.write("quit\n",6);
	std::cerr<< "x3x";
	socket.close();
	std::cerr<< "x4x";
*/
	std::vector<PlayerProxy *> players;
	Socket socket(2000,4);
	
	// mientras 
	// juego no iniciado
	// juego no lleno 
	// aceptar nuevos jugadores
	for (int i=0; i<4; i++) {
		PlayerProxy * playerProxy = new PlayerProxy(socket.accept());
		//echoserver->start();
		players.push_back(playerProxy);
	}


	// bloquearse esperando a que el juego termine

        std::vector<PlayerProxy *>::iterator players_iterator;
        players_iterator = players.begin();
        while( players_iterator != players.end() ) {
		PlayerProxy * playerProxy =  *players_iterator;
		playerProxy->join();
		++players_iterator;
		delete(playerProxy);
	}
	return 0;
}
