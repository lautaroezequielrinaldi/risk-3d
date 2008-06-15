#include "mapaparser.h"

MapaParser::MapaParser():
    document(NULL) {
    // No realiza ninguna acciòn.
}

void MapaParser::persistirPaises(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {
    // Define el nodo de lista de paises a persistir.
    xmlNodePtr countryListNode;
    // Define el nodo del pais a persistir.
    xmlNodePtr countryNode;
    // Define el nodo del pais adyacente a persistir.
    xmlNodePtr adjacentNode;
    // Defino el contador de pais.
    Mapa::IteradorPais countryIter;
    // Defino el contador de adyacente.
    Pais::Iterador adjacentIter;

    // Creo el nodo de lista de paises a persistir.
    countryListNode = xmlNewChild(mapNode, NULL, BAD_CAST "lista-paises",
        NULL);
    // Itero por cada pais.
    for (countryIter = map->primerPais(); countryIter != map->ultimoPais();
        ++countryIter) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = *countryIter;
        // Creo el nodo del pais a persistir.
        countryNode = xmlNewChild(countryListNode, NULL, BAD_CAST "pais", NULL);
        // Agrego el atributo nombre del pais a persistir.
        xmlNewProp(countryNode, BAD_CAST "nombre",
            BAD_CAST (const xmlChar*) actual->getNombre().c_str());

        // Creo un string stream para convertir numeros a string
        std::ostringstream xPositionStr;
        xPositionStr << actual->getPosition().getX();

        // Creo un string stream para convertir numeros a string
        std::ostringstream yPositionStr;
        yPositionStr << actual->getPosition().getY();

        // Agrego el atributo x del pais a persistir.
        xmlNewProp(countryNode, BAD_CAST "x",
            BAD_CAST (const xmlChar*) xPositionStr.str().c_str());

        // Agrego el atributo y del pais a persistir.
        xmlNewProp(countryNode, BAD_CAST "y",
            BAD_CAST (const xmlChar*) yPositionStr.str().c_str());
            
        // Itero por cada pais adyacente.
        for (adjacentIter = actual->primerAdyacente(); 
            adjacentIter != actual->ultimoAdyacente(); ++adjacentIter) {
            // Obtengo pais adyacente actual.
            ReferenceCountPtr<Pais> adyacenteActual = *adjacentIter;
            // Creo el nodo del pais adyacente a persistir.
            adjacentNode = xmlNewChild(countryNode, NULL, BAD_CAST "adyacente",
                BAD_CAST (const xmlChar*) adyacenteActual->getNombre().c_str());
        }
    }
}

void MapaParser::persistirContinentes(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {
    // Define el nodo de lista de continentes a persistir.
    xmlNodePtr continentListNode;
    // Define el nodo del continente a persistir.
    xmlNodePtr continentNode;
    // Define el nodo del pais a persistir.
    xmlNodePtr countryNode;
    // Defino el contador de continente.
    Mapa::IteradorContinente continentIter;
    // Defino el contador de adyacente.
    Pais::Iterador countryIter;

    // Creo en nodo de lista de continentes a persistir.
    continentListNode = xmlNewChild(mapNode, NULL,
        BAD_CAST "lista-continentes", NULL);
    // Itero por cada continente.
    for (continentIter = map->primerContinente();
        continentIter != map->ultimoContinente(); ++continentIter) {
        // Obtengo continente actual.
        ReferenceCountPtr<Continente> actual = *continentIter;
        // Creo el nodo del continente a persistir.
        continentNode = xmlNewChild(continentListNode, NULL,
            BAD_CAST "continente", NULL);
        // Agrego el atributo nombre del continente a persistir.
        xmlNewProp(continentNode, BAD_CAST "nombre",
            BAD_CAST (const xmlChar*) actual->getNombre().c_str());

		// Creo un stream de salida de string para convertir numero a string
		std::ostringstream strBonus;
		strBonus << actual->getArmyBonus();

		// Agrego el atributo bonus del continente a persistir.
		xmlNewProp(continentNode, BAD_CAST "bonus",
			BAD_CAST (const xmlChar*) strBonus.str().c_str());
			
        // Itero por cada pais.
        for (countryIter = actual->primerPais(); 
            countryIter != actual->ultimoPais(); ++countryIter) {
            // Obtengo pais pais actual.
            ReferenceCountPtr<Pais> paisActual = *countryIter;
            // Creo el nodo del pais a persistir.
            countryNode = xmlNewChild(continentNode, NULL, BAD_CAST "pais",
                BAD_CAST (const xmlChar*) paisActual->getNombre().c_str());
        }
    }
}

void MapaParser::persistirReglas(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {

}

void MapaParser::cargarPaises(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {
    // Defino un contexto de XPath.
    xmlXPathContextPtr xpathContext;
    // Defino un objeto de XPath.
    xmlXPathObjectPtr xpathObject;
    // Defino el set de nodos devueltos por la expresiòn XPath.
    xmlNodeSetPtr countryNodeSet;

    // Creo el contexto de XPath.
    xpathContext = xmlXPathNewContext(this->document);

    // Evaluo la expresiòn XPath.
    xpathObject = xmlXPathEvalExpression(BAD_CAST "//mapa/lista-paises/pais",
        xpathContext);

    // Obtengo el set de nodos de paises.
    countryNodeSet = xpathObject->nodesetval;

    // Itero por cada nodo de paises.
    for ( int contador = 0; contador < countryNodeSet->nodeNr; ++contador) {
        // Obtengo el nodo del pais actual.
        xmlNodePtr countryNode = countryNodeSet->nodeTab[contador];

        // Obtengo el nombre del pais actual.
        std::string nombre = (const char*) xmlGetProp(countryNode,
            BAD_CAST "nombre");
        // Obtengo la posicion x del pais actual,
        std::string xPositionStr = (const char*) xmlGetProp(countryNode,
            BAD_CAST "x");
        // Obtengo la posicion y del pais actual.
        std::string yPositionStr = (const char*) xmlGetProp(countryNode,
            BAD_CAST "y");
        // Creo posicion del pais
        MapPosition position(atoi(xPositionStr.c_str()),
            atoi(yPositionStr.c_str()));
        // Creo objeto pais.
        ReferenceCountPtr<Pais> country(new Pais(nombre, position));

        // Agrego pais al mapa de paises cargados.
        this->paisesCargados[nombre] = country;

        // Agrego el pais al mapa.
        map->agregarPais(country);
    }
}

void MapaParser::cargarContinentes(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {

}

void MapaParser::cargarReglas(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {

}

void MapaParser::saveMap(const std::string& fileName,
    ReferenceCountPtr<Mapa>& map) {
    // Define el nodo raiz del documento XML sobre el cual se va a trabajar.
    xmlNodePtr mapNode;

    // Crea el documento XML sobre el cual se va a trabajar.
    this->document = xmlNewDoc(BAD_CAST "1.0");
    // Crea el nodo raiz del documento XML sobre el cual se va a trabajar.
    mapNode = xmlNewNode(NULL, BAD_CAST "mapa");
    // Establece el nodo raìz del documento XML sobre el cual se va a trabajar.
    xmlDocSetRootElement(this->document, mapNode);

    // Persiste los paises del mapa.
    persistirPaises(mapNode, map);
    // Persiste los continentes del map.
    persistirContinentes(mapNode, map);
    // Persiste las reglas del map.
    persistirReglas(mapNode, map);

    // Escribe el documento XML a disco.
    xmlSaveFormatFileEnc(fileName.c_str(), this->document, "UTF-8", 1);

    // Libera el documento XML sobre el cual se va a trabajar.
    xmlFreeDoc(this->document);

    // Libera las variables globales que el parser XML haya inicializado.
    xmlCleanupParser();
}

ReferenceCountPtr<Mapa> MapaParser::loadMap(
    const std::string& fileName) {
    // Defino el mapa que voy a devolver.
    ReferenceCountPtr<Mapa> map;
    // Defino el elemento raiz del documento XML sobre el cual voy a trabajar.
    xmlNodePtr mapNode;

    // Leo el documento XML de disco
    this->document = xmlReadFile(fileName.c_str(), NULL, 0);

    // Obtengo el elemento root del documento XML sobre el cual se va a
    // trabajar.
    mapNode = xmlDocGetRootElement(this->document);

    // Vacio la lista de paises cargados.
    this->paisesCargados.clear();

    // Leo los paises del mapa.
    cargarPaises(mapNode, map);

    // Leo los contientes del mapa.
    cargarContinentes(mapNode, map);

    // Leo las reglas del mapa.
    cargarReglas(mapNode, map);

    // Libera el documento XML sobre el cual se va a trabajar.
    xmlFreeDoc(this->document);

    // Libera las variables globales que el parser XML haya inicializado.
    xmlCleanupParser();

    // Devuelve el mapa cargado.
    return map;
}

MapaParser::~MapaParser() {
    // No realiza ninguna acciòn.
}

