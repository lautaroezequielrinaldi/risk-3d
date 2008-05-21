#include "mapaparser.h"

MapaParser::MapaParser():
    document(NULL) {
    // No realiza ninguna acciòn.
}

void MapaParser::persistirPaises(xmlNodePtr& nodoMapa,
    ReferenceCountPtr<Mapa>& mapa) {
    // Define el nodo del pais a persistir.
    xmlNodePtr nodoPais;
    // Define el nodo del pais adyacente a persistir.
    xmlNodePtr nodoAdyacente;
    // Defino el contador de pais.
    Mapa::IteradorPais iterPais;
    // Defino el contador de adyacente.
    Pais::Iterador iterAdyacente;

    // Itero por cada pais.
    for (iterPais = mapa->primerPais(); iterPais != mapa->ultimoPais();
        ++iterPais) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = *iterPais;
        // Creo el nodo del pais a persistir.
        nodoPais = xmlNewChild(nodoMapa, NULL, BAD_CAST "pais", NULL);
        // Agrego el atributo nombre del pais a persistir.
        xmlNewProp(nodoPais, BAD_CAST "nombre",
            BAD_CAST (const xmlChar*) actual->getNombre().c_str());
        // Itero por cada pais adyacente.
        for (iterAdyacente = actual->primerAdyacente(); 
            iterAdyacente != actual->ultimoAdyacente(); ++iterAdyacente) {
            // Obtengo pais adyacente actual.
            ReferenceCountPtr<Pais> adyacenteActual = *iterAdyacente;
            // Creo el nodo del pais adyacente a persistir.
            nodoAdyacente = xmlNewChild(nodoPais, NULL, BAD_CAST "adyacente",
                BAD_CAST (const xmlChar*) adyacenteActual->getNombre().c_str());
        }
    }
}

void MapaParser::persistirContinentes(xmlNodePtr& nodoMapa,
    ReferenceCountPtr<Mapa>& mapa) {
    // Define el nodo del continente a persistir.
    xmlNodePtr nodoContinente;
    // Define el nodo del pais a persistir.
    xmlNodePtr nodoPais;
    // Defino el contador de continente.
    Mapa::IteradorPais iterContinente;
    // Defino el contador de adyacente.
    Pais::Iterador iterPais;

    // Itero por cada continente.
    for (iterContinente = mapa->primerContinente();
        iterContinente != mapa->ultimoContinente(); ++iterContinente) {
        // Obtengo continente actual.
        ReferenceCountPtr<Continente> actual = *iterContinente;
        // Creo el nodo del continente a persistir.
        nodoContinente = xmlNewChild(nodoMapa, NULL, BAD_CAST "continente",
          NULL);
        // Agrego el atributo nombre del continente a persistir.
        xmlNewProp(nodoContinente, BAD_CAST "nombre",
            BAD_CAST (const xmlChar*) actual->getNombre().c_str());
        // Itero por cada pais.
        for (iterPais = actual->primerPais(); 
            iterPais != actual->ultimoAPais(); ++iterPais) {
            // Obtengo pais pais actual.
            ReferenceCountPtr<Pais> paisActual = *iterPais;
            // Creo el nodo del pais adyacente a persistir.
            nodoAdyacente = xmlNewChild(nodoContinente, NULL, BAD_CAST "pais",
                BAD_CAST (const xmlChar*) paisActual->getNombre().c_str());
        }
    }
}

void MapaParser::persistirReglas(xmlNodePtr& nodoMapa,
    ReferenceCountPtr<Mapa>& mapa) {

}

void MapaParser::saveMap(const std::string& fileName,
    ReferenceCountPtr<Mapa>& mapa) {
    // Define el nodo raiz del documento XML sobre el cual se va a trabajar.
    xmlNodePtr mapaNode;

    // Crea el documento XML sobre el cual se va a trabajar.
    this->document = xmlNewDoc(BAD_CAST "1.0");
    // Crea el nodo raiz del documento XML sobre el cual se va a trabajar.
    mapaNode = xmlNewNode(NULL, BAD_CAST "mapa");
    // Establece el nodo raìz del documento XML sobre el cual se va a trabajar.
    xmlDocSetRootElement(this->document, mapaNode);

    // Persiste los paises del mapa.
    persistirPaises(mapaNode, mapa);
    // Persiste los continentes del mapa.
    persistirContinentes(mapaNode, mapa);
    // Persiste las reglas del mapa.
    persistirReglas(mapaNode, mapa);

    // Escribe el documento XML a disco.
    xmlSaveFormatFileEnc(fileName.c_str(), this->document, "UTF-8", 1);

    // Libera el documento XML sobre el cual se va a trabajar.
    xmlFreeDoc(this->document);

    // Libera las variables globales que el parser XML haya inicializado.
    xmlCleanupParser();
}

ReferenceCountPtr<Mapa> MapaParser::loadMap(
    const std::string& fileName) {
    // No realiza ninguna acciòn todavia.
    return NULL;
}

MapaParser::~MapaParser() {
    // No realiza ninguna acciòn.
}

