#ifndef __URLPARSER_H__
#define __URLPARSER_H__

/**
 * Standard C++ Library Includes.
 */
#include<string> // Para definiciòn de std::string

/**
 * Definiciòn de la clase UrlParser que es una clase utilitaria para trabajar 
 * con url en string.
 */
class UrlParser {
    /**
     * Atributos privados de la clase UrlParser.
     */
    private:
        /**
         * Objeto de tipo std::string que representa el protocolo parseado
         * de la url.
         */
        std::string protocol;
        /**
         * Objeto de tipo std::string que representa el domain parseado de
         * la url.
         */
        std::string domain;
        /**
         * Objeto de tipo std::string que representa el resource parseado de
         * la url.
         */
        std::string resource;

    /**
     * Mètodos privados de la clase UrlParser.
     */
    private:
        /**
         * Constructor copia de la clase UrlParser.
         */
        UrlParser(const UrlParser& otherInstance);

        /**
         * Operador de asignaciòn de la clase UrlParser.
         */
        UrlParser& operator=(const UrlParser& otherInstance);

        /**
         * Parsea la url provista en protocolo, domain y resource.
         */
        void parseUrl(const std::string& url);

    /**
     * Mètodos pùblicos de la clase UrlParser.
     */
    public:
        /**
         * Constructor de la clase UrlParser.
         */
        UrlParser(const char* url);

        /**
         * Constructor de la clase UrlParser.
         */
        UrlParser(const std::string& url);

        /**
         * Mètodo cuyo propòsito es devolver el protocolo parseado de la url.
         * Devuelve un string vacìo si no tiene protocolo la url.
         */
        std::string getProtocol();

        /**
         * Mètodo cuyo propòsito es devolver el domain parseado de la url.
         * Devuelve un string vacìo si no tiene domain la url.
         */
        std::string getDomain();

        /**
         * Mètodo cuyo propòsito es devolver el resource parseado de la url.
         * Devuelve un string vacìo si no tiene resource la url.
         */
        std::string getResource();

        /**
         * Destructor virtual de la clase UrlParser.
         */
        ~UrlParser();
};

#endif /** __URLPARSER_H__ */

