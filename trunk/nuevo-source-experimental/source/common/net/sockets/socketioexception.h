/**
 * Taller de Programacion I (75.42)
 * Facultad de Ingenieria -- Universidad de Buenos Aires.
 * Autor: Pablo Martìn Viva.
 * Archivo: socketioexception.h
 * Descripcion: Definiciòn de la clase SocketIOException que representa
 * errores en la lectura / ecritura de sockets.
 */

#ifndef __SOCKETIOEXCEPTION_H__
#define __SOCKETIOEXCEPTION_H__

/**
 * Standard C++ Library Includes.
 */
#include<string> // Para definiciòn de std::string
#include<exception> // Para definiciòn de std::exception

/**
 * Definiciòn de la clase SocketIOException que representa errores
 * en la lectura / escritura de sockets.
 */
class SocketIOException : public std::exception {
    /**
     * Atributos privados de la clase SocketIOException.
     */
    private:
        /**
         * Objeto de tipo std::string representando el mensaje del
         * SocketIOException.
         */
        std::string message;

    /**
     * Mètodos pùblicos de la clase SocketIOException.
     */
    public:
        /**
         * Constructor de la clase SocketIOException.
         */
        SocketIOException();

        /**
         * Constructor de la clase SocketIOException.
         */
        SocketIOException(const char* message);

        /**
         * Constructor de la clase SocketIOException.
         */
        SocketIOException(const std::string& message);

        /**
         * Devuelve el mensaje de error del SocketIOException.
         */
        virtual const char* what() throw();

        /**
         * Destructor virtual de la clase SocketIOException.
         */
        ~SocketIOException() throw();
};

#endif /** __SOCKETIOEXCEPTION_H__ */

