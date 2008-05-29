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

Socket::Socket() {
    // Inicializa el socket.
    this->initialize_socket();
}

Socket::Socket(const char* destination, int port)
    throw(SocketConnectionException) {
    // Inicializa el socket.
    this->initialize_socket();

    // Conecta el socket.
    this->connect_socket(destination, port);
}

Socket::Socket(const std::string& destination, int port)
    throw(SocketConnectionException) {
    // Inicializa el socket.
    this->initialize_socket();

    // Conecta el socket.
    this->connect_socket(destination, port);
}

void Socket::initialize_socket() {
   this->socketDescriptor = socket(PF_INET, SOCK_STREAM, 0);
}

bool Socket::is_valid_socket() {
    return (this->socketDescriptor != INVALID_SOCKET_DESCRIPTOR);
}


Socket::Socket(int port, int client_wait)
     throw(SocketConnectionException){
}

Socket * Socket::accept(){
	return 0;


}
void Socket::connect_socket(const char* destination, int port)
    throw(SocketConnectionException) {
    if (this->is_valid_socket() ) {
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
        hostnameInformation = gethostbyname(destination);

        // Valido que puedo obtener informaciòn del hostname.
        if (hostnameInformation == NULL) {
            throw SocketConnectionException();
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
        returnValue = connect(this->socketDescriptor, (sockaddr*) &address,
            sizeof(address));

        // Valido que me pude conectar.
        if (returnValue == -1) {
            throw SocketConnectionException();
        }
    } else {
        throw SocketConnectionException();
    }
}

void Socket::connect_socket(const std::string& destination, int port)
    throw(SocketConnectionException) {
    // Conecta el socket.
    this->connect_socket(destination.c_str(), port);
}

void Socket::listen(int port, int client_wait){


}

/**
 *
 *
 */
Socket * Socket::accept(){


}



int Socket::write_to_socket(const char* data, int length)
    throw(SocketIOException) {
    // Valido que el socket es valido.
    if (this->is_valid_socket() ) {
        // Defino valor de retorno de la funcion send.
        int returnValue;

        // Envio mensaje al socket.
        returnValue = send(this->socketDescriptor, data, length, 0);

        // Verifico que se pudo enviar mensaje.
        if (returnValue != -1) {
            return returnValue;
        }
    }
    throw SocketIOException();
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
		read = read_from_socket(data + read,toread);
		toread = length - read;
	}
}

int Socket::read_from_socket(char* data, int length)
    throw(SocketIOException) {
    //Valido que el socket es valido.
    if (this->is_valid_socket() ) {
        // Defino valor de retorno de la funcion recv.
        int returnValue;

        // Recibo mensaje del socket.
        returnValue = recv(this->socketDescriptor, data, length, 0);

        // Verifico que se pudo recibir mensaje.
        if (returnValue != -1) {
            return returnValue;
        }
    }
    throw SocketIOException();
}

void Socket::close() {
    if (this->is_valid_socket() ) {
        close(this->socketDescriptor);
    }
}

Socket::~Socket() {
    if (this->is_valid_socket() ) {
        close();
    }
}

