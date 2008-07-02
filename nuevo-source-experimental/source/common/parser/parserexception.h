#ifndef __PARSEREXCEPTION_H__
#define __PARSEREXCEPTION_H__

#include<exception> // Para definicion de std::exception.
#include<string> // Para definicion de std::string.

class ParserException: public std::exception {
    /**
     * Atributos privados de la clase ParserException.
     */
    private:
        /**
         * Almacena el mensaje de la excepcion.
         */
        std::string message;
    
    /**
     * Mètodos publicos de la clase ParserException.
     */
    public:
        /**
         * Constructor de la clase ParserException.
         */
        ParserException();
        /**
         * Constructor de la clase ParserException.
         */
        ParserException(const std::string& message);
        /**
         * Obtiene el mensaje de la excepcion.
         */
        virtual const char* what() const throw();
        /**
         * Destructor virtual de la clase ParserException.
         */
        ~ParserException() throw();
};

#endif /** __PARSEREXCEPTION_H__ */

