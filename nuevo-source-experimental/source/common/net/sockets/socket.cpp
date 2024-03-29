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
#include<iostream>
/*
 * Client socket
 *
 *
 */
Socket::Socket(const std::string& destination, int port) throw(SocketConnectionException) {
    this->initialize();
    this->connect(destination, port);
}

void Socket::connect(const std::string& destination, int port) throw(SocketConnectionException) {
	if (!this->is_valid() ) {
		throw SocketConnectionException("connect sobre socket invalido\n");
	}
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
	returnValue = ::connect(this->socketDescriptor, (sockaddr*) &address, sizeof(address));

	// Valido que me pude conectar.
	if (returnValue == -1) {
		throw SocketConnectionException("no se pudo conectar\n");
	}
}


/*
 * Server socket
 *
 *
 */
Socket::Socket(int port, int client_wait) throw(SocketConnectionException){
	struct sockaddr_in server_address;

	this->initialize();

	memset((char*)&server_address,0,sizeof(server_address));
	server_address.sin_family= AF_INET;
	server_address.sin_port=htons(port);
	server_address.sin_addr.s_addr=INADDR_ANY;

	if (bind(this->socketDescriptor,(struct sockaddr *) & server_address, (socklen_t)sizeof(struct sockaddr)) < 0) {
		throw SocketConnectionException("error de bind, verifique que el puerto este libre o intente mas tarde");
	}

	listen(this->socketDescriptor,client_wait);
}

Socket::Socket(const int & socketDescriptor) throw(SocketConnectionException){
	this->socketDescriptor=socketDescriptor;
	
}

ReferenceCountPtr<Socket> Socket::accept() throw(SocketConnectionException) {
	if (!this->is_valid() ) {
		throw SocketConnectionException("accept sobre socket invalido");
	}

	unsigned int newsockfd, client_len;
	struct sockaddr_in client_address;
	
	client_len = (socklen_t)sizeof(client_address);
	newsockfd = ::accept(this->socketDescriptor, (struct sockaddr*)&client_address,&client_len);
	if (newsockfd <0) {
		throw SocketConnectionException("error de accept");
	}
	return new Socket(newsockfd);
}

/*
 * Comun
 *
 *
 */



void Socket::initialize() {
   this->socketDescriptor = ::socket(PF_INET, SOCK_STREAM, 0);
}

bool Socket::is_valid() {
    return (this->socketDescriptor != INVALID_SOCKET_DESCRIPTOR);
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
	if (length != returnValue) {
		throw SocketIOException("Socket::write incomplete write\n");
	}


        if (returnValue != -1) {
            return returnValue;
        }
    }
    throw SocketIOException("write sobre socket invalido\n");
}

int Socket::write(const std::string & data) throw(SocketIOException) {
	return this->write(data.c_str(), data.size());
}



std::string Socket::full_read(int length)
	throw(SocketIOException) {

    std::cerr << "A PUNTO DE CREAR BUFFER" << std::endl;
	char * buffer = new char[length];
    if (buffer != NULL) {
        std::cerr << "BUFFER CREADO" << std::endl;
    } else {
        std::cerr << "BUFFER NO CREADO" << std::endl;
    }
    std::cerr << "A PUNTO DE INVOCAR FULL READ INNER" << std::endl;
	full_read(buffer,length);
    std::cerr << "SE INVOCO FULL READ INNER" << std::endl;

	std::string result;
	result.append(buffer, length);

	delete[] buffer;
	return result;
}

void Socket::full_read(char* data, int length)
	throw(SocketIOException) {
    if (data == NULL) {
        std::cerr << "******** KERNEL PANIC.. DATA ERA NULL" << std::endl << std::endl;
    } else {
        std::cerr << "DATA NO ES NULL" << std::endl;
    }
	int read = 0;
	int index = 0;
	int toread = length;
    std::cerr << "***** A PUNTO DE LEER: " << length << " BYTES EN SOCKET::FULL_READ INTERNO" << std::endl;
	while (toread) {
        std::cerr << "**** ANTES *** TOREAD: " << toread << " READ: " << read << " INDEX: " << index << std::endl;
        if (this == NULL) {
            std::cerr << "KERNEL PANIC: THIS ES NULL" << std::endl;
        } else {
            std::cerr << "THIS NO ES NULL" << std::endl;
        }
		read   = this->read(data + index,toread);
		toread -= read;
		index  +=read;
        std::cerr << "**** DESPUES *** TOREAD: " << toread << " READ: " << read << " INDEX: " << index << std::endl;
        std::cerr << std::endl;
	}
    std::cerr << "***** SE LEYO: " << length << " BYTES EN SOCKET::FULL_READ INTERNO" << std::endl;
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




