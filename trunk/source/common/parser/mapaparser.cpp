#include "mapaparser.h"

MapaParser::MapaParser():
    document(NULL) {
    // No realiza ninguna acciòn.
}

void MapaParser::persistirPaises(xmlNodePtr& nodoMapa,
    ReferenceCountPtr<Mapa>& mapa) {
    // Define el nodo de lista de paises a persistir.
    xmlNodePtr nodoListaPaises;
    // Define el nodo del pais a persistir.
    xmlNodePtr nodoPais;
    // Define el nodo del pais adyacente a persistir.
    xmlNodePtr nodoAdyacente;
    // Defino el contador de pais.
    Mapa::IteradorPais iterPais;
    // Defino el contador de adyacente.
    Pais::Iterador iterAdyacente;

    // Creo el nodo de lista de paises a persistir.
    nodoListaPaises = xmlNewChild(nodoMapa, NULL, BAD_CAST "lista-paises",
        NULL);
    // Itero por cada pais.
    for (iterPais = mapa->primerPais(); iterPais != mapa->ultimoPais();
        ++iterPais) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = *iterPais;
        // Creo el nodo del pais a persistir.
        nodoPais = xmlNewChild(nodoListaPaises, NULL, BAD_CAST "pais", NULL);
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
    // Define el nodo de lista de continentes a persistir.
    xmlNodePtr nodoListaContinentes;
    // Define el nodo del continente a persistir.
    xmlNodePtr nodoContinente;
    // Define el nodo del pais a persistir.
    xmlNodePtr nodoPais;
    // Defino el contador de continente.
    Mapa::IteradorContinente iterContinente;
    // Defino el contador de adyacente.
    Pais::Iterador iterPais;

    // Creo en nodo de lista de continentes a persistir.
    nodoListaContinentes = xmlNewChild(nodoMapa, NULL,
        BAD_CAST "lista-continentes", NULL);
    // Itero por cada continente.
    for (iterContinente = mapa->primerContinente();
        iterContinente != mapa->ultimoContinente(); ++iterContinente) {
        // Obtengo continente actual.
        ReferenceCountPtr<Continente> actual = *iterContinente;
        // Creo el nodo del continente a persistir.
        nodoContinente = xmlNewChild(nodoListaContinentes, NULL,
            BAD_CAST "continente",
          NULL);
        // Agrego el atributo nombre del continente a persistir.
        xmlNewProp(nodoContinente, BAD_CAST "nombre",
            BAD_CAST (const xmlChar*) actual->getNombre().c_str());
        // Itero por cada pais.
        for (iterPais = actual->primerPais(); 
            iterPais != actual->ultimoPais(); ++iterPais) {
            // Obtengo pais pais actual.
            ReferenceCountPtr<Pais> paisActual = *iterPais;
            // Creo el nodo del pais a persistir.
            nodoPais = xmlNewChild(nodoContinente, NULL, BAD_CAST "pais",
                BAD_CAST (const xmlChar*) paisActual->getNombre().c_str());
        }
    }
}

void MapaParser::persistirReglas(xmlNodePtr& nodoMapa,
    ReferenceCountPtr<Mapa>& mapa) {

}

void MapaParser::cargarPaises(xmlNodePtr& nodoMapa,
    ReferenceCountPtr<Mapa>& mapa) {
    // Defino un contexto de XPath.
    xmlXPathContextPtr contextoXPath;
    // Defino un objeto de XPath.
    xmlXPathObjectPtr objetoXPath;
    // Defino el set de nodos devueltos por la expresiòn XPath.
    xmlNodeSetPtr setNodoPais;

    // Creo el contexto de XPath.
    contextoXPath = xmlXPathNewContext(this->document);

    // Evaluo la expresiòn XPath.
    objetoXPath = xmlXPathEvalExpression(BAD_CAST "//mapa/lista-paises/pais",
        contextoXPath);

    // Obtengo el set de nodos de paises.
    setNodoPais = objetoXPath->nodesetval;

    // Itero por cada nodo de paises.
    for ( int contador = 0; contador < setNodoPais->nodeNr; ++contador) {
        // Obtengo el nodo del pais actual.
        xmlNodePtr nodoPais = setNodoPais->nodeTab[contador];

        // Obtengo el nombre del pais actual.
        std::string nombre = (const char*) xmlGetProp(nodoPais,
            BAD_CAST "nombre");

        // Creo posicion del pais
        MapPosition position(0,0);
        // Creo objeto pais.
        ReferenceCountPtr<Pais> pais(new Pais(nombre, position));

        // Agrego pais al mapa de paises cargados.
        this->paisesCargados[nombre] = pais;

        // Agrego el pais al mapa.
        mapa->agregarPais(pais);
    }
}

void MapaParser::cargarContinentes(xmlNodePtr& nodoMapa,
    ReferenceCountPtr<Mapa>& mapa) {

}

void MapaParser::cargarReglas(xmlNodePtr& nodoMapa,
    ReferenceCountPtr<Mapa>& mapa) {

}

void MapaParser::saveMap(const std::string& fileName,
    ReferenceCountPtr<Mapa>& mapa) {
    // Define el nodo raiz del documento XML sobre el cual se va a trabajar.
    xmlNodePtr nodoMapa;

    // Crea el documento XML sobre el cual se va a trabajar.
    this->document = xmlNewDoc(BAD_CAST "1.0");
    // Crea el nodo raiz del documento XML sobre el cual se va a trabajar.
    nodoMapa = xmlNewNode(NULL, BAD_CAST "mapa");
    // Establece el nodo raìz del documento XML sobre el cual se va a trabajar.
    xmlDocSetRootElement(this->document, nodoMapa);

    // Persiste los paises del mapa.
    persistirPaises(nodoMapa, mapa);
    // Persiste los continentes del mapa.
    persistirContinentes(nodoMapa, mapa);
    // Persiste las reglas del mapa.
    persistirReglas(nodoMapa, mapa);

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
    ReferenceCountPtr<Mapa> mapa;
    // Defino el elemento raiz del documento XML sobre el cual voy a trabajar.
    xmlNodePtr nodoMapa;

    // Leo el documento XML de disco
    this->document = xmlReadFile(fileName.c_str(), NULL, 0);

    // Obtengo el elemento root del documento XML sobre el cual se va a
    // trabajar.
    nodoMapa = xmlDocGetRootElement(this->document);

    // Vacio la lista de paises cargados.
    this->paisesCargados.clear();

    // Leo los paises del mapa.
    cargarPaises(nodoMapa, mapa);

    // Leo los contientes del mapa.
    cargarContinentes(nodoMapa, mapa);

    // Leo las reglas del mapa.
    cargarReglas(nodoMapa, mapa);

    // Libera el documento XML sobre el cual se va a trabajar.
    xmlFreeDoc(this->document);

    // Libera las variables globales que el parser XML haya inicializado.
    xmlCleanupParser();

    // Devuelve el mapa cargado.
    return mapa;
}

MapaParser::~MapaParser() {
    // No realiza ninguna acciòn.
}

