/**
 * Taller de Programacion I (75.42)
 * Facultad de Ingenieria -- Universidad de Buenos Aires.
 * Autor: Pablo Martìn Viva.
 * Archivo: socketioexception.cpp
 * Descripcion: Implementaciòn de la clase SocketIOException que
 * representa errores en la conexiòn de sockets.
 */

/**
 * Project Includes.
 */
#include "socketioexception.h"

SocketIOException::SocketIOException():
    std::exception() {
    // Establece un mensaje predeterminado.
    this->message = "Error al leer / escribir del socket";
}

SocketIOException::SocketIOException(const char* message):
    std::exception(),
    message(message) {
    // No realiza ninguna acciòn.
}

SocketIOException::SocketIOException(
    const std::string& message):
    std::exception(),
    message(message) {
    // No realiza ninguna acciòn.
}

const char* SocketIOException::what() throw(){
    return this->message.c_str();
}

SocketIOException::~SocketIOException() throw(){
    // No realiza ninguna acciòn.
}

