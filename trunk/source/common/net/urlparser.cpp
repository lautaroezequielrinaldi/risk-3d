/**
 * Project Includes.
 */
#include "urlparser.h"

UrlParser::UrlParser(const char* url) {
    // Genra un string std a partir de la url provista.
    std::string stringUrl(url);

    // Parsea la url.
    this->parse_url(stringUrl);
}

UrlParser::UrlParser(const std::string& url) {
    // Parsea la url.
    this->parse_url(url);
}

void UrlParser::parse_url(const std::string& url) {
    // Defino posicion del separador de protocolo.
    int protocolSeparatorIndex;
    // Defino posiciòn del separador de resource.
    int resourceSeparatorIndex;
    // Defino posicion inicial de dominio.
    int domainInitialIndex;

    // Busco separador de protocolo, siempre es un colon o dos puntos.
    // Como en http://www.example.com/index.html
    protocolSeparatorIndex = url.find_first_of(":");

    // Verifico que se encontró y si se encontro obtengo protocolo.
    // Puede que una url no tenga especificado protocolo, como en
    // www.example.com
    if (protocolSeparatorIndex != std::string::npos) {
        this->protocol = url.substr(0, protocolSeparatorIndex);
    } else {
        // Si no encuentra el separador asigno -1 asi al buscar
        // posicion inicial de domain y sumar uno a posicion inicial de
        // separador de protocolo comienza a buscar a partir del caracter 0
        protocolSeparatorIndex = -1;
    }
    
    // Busco posicion inicial de dominio.
    // Comienza a buscar a partir de protocolSeparatorIndex y como apunta a la
    // misma posicion donde aparece el separador, encontraria como primer
    // caracter antes de / al separador mismo, comenzando a partir de la
    // posicion siguiente obligamos a procesarlo en la busqueda.
    domainInitialIndex = url.find_first_not_of("/",
        protocolSeparatorIndex + 1);

    // Verifico que se encontrò  y si se encontrò procedo a buscar el resource.
    if (domainInitialIndex != std::string::npos) {
        // Busco el separador de resource, siempre es /
        // Como en http://www.example.com/index.html
        resourceSeparatorIndex = url.find_first_of("/", domainInitialIndex);
        
        // Verifico que se encontrò, si se encontro obtengo resource y admeàs
        // obtengo el domain.
        if (resourceSeparatorIndex != std::string::npos) {
            this->resource = "/" + url.substr(resourceSeparatorIndex);

            this->domain = url.substr(domainInitialIndex,
                resourceSeparatorIndex - domainInitialIndex);
        } else {
            this->resource += "/";
            this->domain = url.substr(domainInitialIndex);
        }
    }
}

std::string UrlParser::get_protocol() {
    return this->protocol;
}

std::string UrlParser::get_domain() {
    return this->domain;
}

std::string UrlParser::get_resource() {
    return this->resource;
}

UrlParser::~UrlParser() {
    // No realiza ninguna acciòn.
}

