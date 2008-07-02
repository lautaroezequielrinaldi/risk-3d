/**
 * Taller de Programacion I (75.42)
 * Facultad de Ingenieria -- Universidad de Buenos Aires.
 * Autor: Pablo Martìn Viva.
 * Archivo: socket.h
 * Descripcion: Definiciòn de la clase Socket que encapsularà un socket stream
 * sobre el protocolo TCP / IP.
 */

#ifndef __SOCKET_H__
#define __SOCKET_H__

/**
 * Standard C Library Includes.
 */
#include <sys/socket.h> // Para definiciòn de hostent
#include <netinet/in.h> // Para definiciòn de struct sockaddr_in
#include <arpa/inet.h> // Para definiciòn de inet_aton
#include <netdb.h> // Para definiciòn de hostent

/**
 * Standard C++ Library Includes.
 */
#include <string> // Para definiciòn de std::string

/**
 * Project Includes.
 */
#include "socketconnectionexception.h" // Para definiciòn de
//SocketConnectionException.
#include "socketioexception.h" // Para definiciòn de SocketIOException.
#include "../../smartpointer/referencecountptr.h"

/**
 * Definiciòn de la clase Socket que encapsularà un socket stream sobre el
 * protocolo TCP / IP.
 */
class Socket {
    /**
     * Atributos privados de la clase Socket.
     */
    private:
        /**
         * Constante numèrica que representa un descriptor de socket invàlido.
         */
        static const int INVALID_SOCKET_DESCRIPTOR = -1;

        /**
         * Atributo de tipo int representando el descriptor del socket que se va
         * a encapsular.
         */
        int socketDescriptor;

    /**
     * Mètodos privados de la clase Socket.
     */
    private:
        /**
         * Constructor copia de la clase Socket.
         */
        Socket(const Socket& otherInstance);

        /**
         * Operador de asignaciòn de la clase Socket.
         */
        Socket& operator=(const Socket& otherInstance);

        /**
         * Mètodo cuyo propòsito es inicializar el socket. Esta funciòn es de
         * uso comùn entre todos los constructores de la clase Socket. Se usa
         * para no repetir codigo entre constructores.
         */
        void initialize();

        /**
         * Mètodo cuyto propòsito es verificar si el socket es vàlido.
         */
        bool is_valid();

    /**
     * Mètodos pùblicos de la clase Socket.
     */
    public:
        /**
         * Constructor de la clase Socket, cliente. Lanza excepciòn
         * SocketConnectionException cuando destination no es un hsot valido
         * o cuando no se pudo conectar a dicho host en dicho puerto.
         */
        Socket(const std::string& destination, int port)
            throw(SocketConnectionException);

        /**
         * Constructor de la clase Socket, server.
         *
         */
        Socket(int port, int client_wait)
             throw(SocketConnectionException);


        /**
         * 
         *
         */
        ReferenceCountPtr<Socket> accept()
             throw(SocketConnectionException);

    private:
        /**
         * Crea un socket conectado al descriptor provisto
         *
         */
        Socket(const int & socketDescriptor)
            throw(SocketConnectionException);



        /**
         * Mètodo cuyo propòsito es conectar el socket a una direcciòn destino
         * y a un puerto determinado. Lanza excepciòn SocketConnectionException
         * cuando destination no es un host valido o cuando no se pudo conectar
         * a dicho host en dicho puerto.
         */
        void connect(const std::string& destination, int port)
            throw(SocketConnectionException);

   public:
        /**
         * Mètodo cuyo propòsito es escribir en el stream del socket una cadena
         * de bytes contigua. Lanza excepciòn SocketIOException cuando no pudo
         * escribir datos al socket, es decir cuando la funcion send retorna
         * -1.
         */
        int write(const char* data, int length)
            throw(SocketIOException);

	int write(const std::string & data)
		throw(SocketIOException);

        /**
         * Mètodo cuyo propòsito es leer del stream del socket una cadena
         * de bytes contigua. Lanza excepciòn SocketIOExeption cuando no pudo
         * leer datos del socket, es decir cuando la funciòn recv retorna -1.
         */
        int read(char* data, int length)
            throw(SocketIOException);

        /**
         * Método cuyo propósito es leer del stram del socket una cadena
         * de bytes continua. A diferencia de read(), del cual
         * se sirve, lee hasta completar length
         */
        void full_read(char* data, int length)
        	throw(SocketIOException);


        std::string full_read(int length)
        	throw(SocketIOException);

    	std::string readLine()
              throw(SocketIOException);

        /**
         * Mètodo cuyo propòsito es cerrar la conexiòn del socket.
         */
        void close();

        /**
         * Destructor virtual de la clase Socket.
         */
        ~Socket();
};

#endif /** __SOCKET_H__ */

