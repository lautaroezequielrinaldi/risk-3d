/**
 * Taller de Programacion I (75.42)
 * Facultad de Ingenieria -- Universidad de Buenos Aires.
 * Autor: Pablo Martìn Viva.
 * Archivo: socketconnectionexception.h
 * Descripcion: Definiciòn de la clase SocketConnectionException que representa
 * errores en la conexiòn de sockets.
 */

#ifndef __SOCKETCONNECTIONEXCEPTION_H__
#define __SOCKETCONNECTIONEXCEPTION_H__

/**
 * Standard C++ Library Includes.
 */
#include<string> // Para definiciòn de std::string
#include<exception> // Para definiciòn de std::exception

/**
 * Definiciòn de la clase SocketConnectionException que representa errores
 * en la conexiòn de sockets.
 */
class SocketConnectionException : public std::exception {
    /**
     * Atributos privados de la clase SocketConnectionException.
     */
    private:
        /**
         * Objeto de tipo std::string representando el mensaje del
         * SocketConnectionException.
         */
        std::string message;

    /**
     * Mètodos pùblicos de la clase SocketConnectionException.
     */
    public:
        /**
         * Constructor de la clase SocketConnectionException.
         */
        SocketConnectionException();

        /**
         * Constructor de la clase SocketConnectionException.
         */
        SocketConnectionException(const char* message);

        /**
         * Constructor de la clase SocketConnectionException.
         */
        SocketConnectionException(const std::string& message);

        /**
         * Devuelve el mensaje de error del SocketConnectionException.
         */
        virtual const char* what() throw();

        /**
         * Destructor virtual de la clase SocketConnectionException.
         */
        ~SocketConnectionException() throw();
};

#endif /** __SOCKETCONNECTIONEXCEPTION_H__ */

