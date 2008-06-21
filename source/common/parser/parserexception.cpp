#include "parserexception.h"

ParserException::ParserException():
    std::exception(),
    message() {
    // Establece un mensaje por default.
    this->message = "Se ha producido una excepcion al parsear el archivo";
}

ParserException::ParserException(const std::string& message):
    std::exception(),
    message(message) {
    // No realiza ninguna acciòn.
}

const char* ParserException::what() const throw() {
    return this->message.c_str();
}

ParserException::~ParserException() throw() {
    // No realiza ninguna acciòn.
}

