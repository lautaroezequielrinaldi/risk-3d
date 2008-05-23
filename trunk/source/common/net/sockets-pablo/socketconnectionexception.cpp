/**
 * Taller de Programacion I (75.42)
 * Facultad de Ingenieria -- Universidad de Buenos Aires.
 * Autor: Pablo Martìn Viva.
 * Archivo: socketconnectionexception.cpp
 * Descripcion: Implementaciòn de la clase SocketConnectionException que
 * representa errores en la conexiòn de sockets.
 */

/**
 * Project Includes.
 */
#include "socketconnectionexception.h"

SocketConnectionException::SocketConnectionException():
    std::exception() {
    // Establece un mensaje predeterminado.
    this->message = "Error al conectarse al host";
}

SocketConnectionException::SocketConnectionException(const char* message):
    std::exception(),
    message(message) {
    // No realiza ninguna acciòn.
}

SocketConnectionException::SocketConnectionException(
    const std::string& message):
    std::exception(),
    message(message) {
    // No realiza ninguna acciòn.
}

const char* SocketConnectionException::what() throw(){
    return this->message.c_str();
}

SocketConnectionException::~SocketConnectionException() throw(){
    // No realiza ninguna acciòn.
}

