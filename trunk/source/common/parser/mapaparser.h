#ifndef __MAPAPARSER_H__
#define __MAPAPARSER_H__

#include<string> // Para definiciòn de std::string.
#include<map> // Para definiciòn de std::map
#include<libxml/parser.h> // Para definiciòn de la libreria libxml parser.
#include<libxml/tree.h> // Para definiciòn de la libreria libxml tree.
#include<libxml/xpath.h> // Para definiciòn de la libreria libxml xpath.
#include<libxml/xpathInternals.h> // Para definiciòn de la libreria libxml
// xpath internals.
#include "../model/mapa.h" // Para definiciòn de Mapa.
#include "../model/pais.h" // Para definiciòn de Pais.
#include "../model/continente.h" // Para definiciòn de Continente.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es guardar el mapa en disco y leer un mapa del disco.
 * El mapa es persistido hacia y dese un archivo XML
 */
class MapaParser {
    /**
     * Atributos privados de la clase MapaParser.
     */
    private:
        /**
         * Almacena el documento XML sobre el cual se va a trabajar.
         */
        xmlDocPtr document;
        /**
         * Almacena los paises cargados hasta el momento.
         */
        std::map< std::string, ReferenceCountPtr<Pais> > paisesCargados;

    /**
     * Mètodos privados de la clase MapaParser.
     */
    private:
        /**
         * Constructor copia de la clase MapaParser.
         */
        MapaParser(const MapaParser& otherInstance);
        /**
         * Operador de asignaciòn de la clase MapaParser.
         */
        MapaParser& operator=(const MapaParser& otherInstance);
        /**
         * Persiste los paises del mapa.
         */
        void persistirPaises(xmlNodePtr& nodoMapa,
            ReferenceCountPtr<Mapa>& mapa);
        /**
         * Persiste los continentes del mapa.
         */
        void persistirContinentes(xmlNodePtr& nodoMapa,
            ReferenceCountPtr<Mapa>& mapa);
        /**
         * Persiste las reglas del mapa.
         */
        void persistirReglas(xmlNodePtr& nodoMapa,
            ReferenceCountPtr<Mapa>& mapa);
        /**
         * Carga los paises del mapa.
         */
        void cargarPaises(xmlNodePtr& nodoMapa,
            ReferenceCountPtr<Mapa>& mapa);
        /**
         * Carga los continentes del mapa.
         */
        void cargarContinentes(xmlNodePtr& nodoMapa,
            ReferenceCountPtr<Mapa>& mapa);
        /**
         * Carga las reglas del mapa.
         */
        void cargarReglas(xmlNodePtr& nodoMapa,
            ReferenceCountPtr<Mapa>& mapa);

    /**
     * Mètodos pùblicos de la clase MapaParser.
     */
    public:
        /**
         * Constructor de la clase MapaParser.
         */
        MapaParser();
        /**
         * Mètodo cuyo propòsito es guardar el mapa y persistirlo a un archivo
         * XML en disco.
         */
        void saveMap(const std::string& fileName,
            ReferenceCountPtr<Mapa>& mapa);
        /**
         * Mètodo cuyo propòsito es cargar el mapa desde un archivo XML en
         * disco.
         */
        ReferenceCountPtr<Mapa> loadMap(const std::string& fileName);
        /**
         * Destructor virtual de la clase MapaParser.
         */
        virtual ~MapaParser();
};

#endif /** __MAPAPARSER_H__ */

